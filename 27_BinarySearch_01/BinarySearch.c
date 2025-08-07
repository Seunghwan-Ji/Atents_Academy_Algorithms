#include <stdlib.h> 
#include <stdio.h>
#include "Point.h"
#include <time.h>

Point* BinarySearch(Point PointList[], int Size, double Target, int* pcount)
{
    int Left, Right, Mid; // 이진 탐색에서 사용할 좌/우 인덱스 및 중간 인덱스.

    Left = 0;
    Right = Size - 1;

    int count = 0; // 중앙값과 탐색값을 비교한 횟수.

    while (Left <= Right)
    {
        Mid = (Left + Right) / 2; // 중앙값 갱신.

        //printf("R[%d], L[%d], M[%d], id = %d, point = %lf\n", Right, Left, Mid, PointList[Mid].id, PointList[Mid].point);

        if (Target == PointList[Mid].point) // 중앙값이 탐색값과 같아지면 탐색 종료.
        {
            printf("Match Count = %d\n", count);
            *pcount = count; // 비교 횟수 전달.

            return &(PointList[Mid]); // 탐색값과 일치하는 구조체를 참조형으로 반환.
        }
        else if (Target > PointList[Mid].point)
            // 탐색값이 중앙값 보다 크면, 다음 탐색은 중앙값의 오른쪽 범위에서 진행.
            Left = Mid + 1;
        else
            // 탐색값이 중앙값 보다 작거나 같으면, 다음 탐색은 중앙값의 왼쪽 범위에서 진행.
            Right = Mid - 1;

        count++; // 비교 횟수 갱신.
    }

    return NULL;
}

int ComparePoint(const void* _elem1, const void* _elem2)
{
    Point* elem1 = (Point*)_elem1;
    Point* elem2 = (Point*)_elem2;

    if (elem1->point > elem2->point)
        return 1;
    else if (elem1->point < elem2->point)
        return -1;
    else
        return 0;
}

int main(void)
{
    srand(time(NULL));
    int Length = sizeof DataSet / sizeof DataSet[0];
    Point* found = NULL;

    int countArray[1000] = { 0, };   // 1000번 탐색 횟수를 저장할 배열

    //  구매포인트에 대해 오름차순으로 정렬 
    qsort((void*)DataSet, Length, sizeof(Point), ComparePoint);

    for (int i = 0; i < 1000; i++) {
        int randValue = rand() % 30000;

        found = BinarySearch(DataSet, Length, DataSet[randValue].point, &countArray[i]);

        if (found != NULL) {
            printf("found: %d, %lf\n", found->id, found->point);
        }

    }

    int sum = 0;

    for (int i = 0; i < 1000; i++) {
        sum += countArray[i];
    }

    printf("1000번 탐색 작업시 평균 비교 횟수: sum = %d, average = %lf\n", sum, sum / (float)1000.0f);

    return 0;
}
