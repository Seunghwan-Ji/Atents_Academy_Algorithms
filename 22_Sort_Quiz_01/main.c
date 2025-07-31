#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Score.h"
#include <time.h>

void Descending_BubbleSort(Score* dataSet, int length)
{
    Score temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (dataSet[j].score < dataSet[j + 1].score)
            {
                temp = dataSet[j];
                dataSet[j] = dataSet[j + 1];
                dataSet[j + 1] = temp;
            }
        }
    }
}

void Descending_InsertionSort(Score* dataSet, int length)
{
    Score temp;

    for (int i = 1; i < length; i++)
    {
        if (dataSet[i - 1].score >= dataSet[i].score)
            continue;

        temp = dataSet[i];

        for (int j = 0; j < i; j++)
        {
            if (dataSet[j].score < temp.score)
            {
                memmove(&dataSet[j + 1], &dataSet[j], sizeof(dataSet[0]) * (i - j));
                dataSet[j] = temp;
                break;
            }
        }
    }
}

void Swap(Score* A, Score* B)
{
    Score Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition_For_Descending(Score* DataSet, int Left, int Right)
{
    int First = Left;
    Score Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left].score >= Pivot.score && Left < Right)
            ++Left;

        while (DataSet[Right].score <= Pivot.score && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void Descending_QuickSort(Score* DataSet, int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition_For_Descending(DataSet, Left, Right);

        Descending_QuickSort(DataSet, Left, Index - 1);
        Descending_QuickSort(DataSet, Index + 1, Right);
    }
}

int ComparePoint_For_Descending(const void* _elem1, const void* _elem2)
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;

    if (elem1->score > elem2->score)
        return -1;
    else if (elem1->score < elem2->score)
        return 1;
    else
        return 0;
}

int main()
{
	// 문제
	// score.h 파일에 저장된 3만개의 데이타를 score 순으로 정렬해서 앞에 10개(1 ~ 10)
	// 뒤에 10개(29990 ~ 29999)를 출력해보세요.
	// 버블소트
	// 삽입정렬
	// 퀵소트
	// 퀵소트2

    int Length = sizeof DataSet / sizeof DataSet[0];

    double startTime = 0.0, endTime = 0.0;
    startTime = (double)clock() / CLOCKS_PER_SEC;

    // Descending_BubbleSort(DataSet, Length);
    // Descending_InsertionSort(DataSet, Length);
    Descending_QuickSort(DataSet, 0, Length - 1);
    // qsort(DataSet, Length, sizeof(Score), ComparePoint_For_Descending);
    // 표준 퀵소트가 기존 퀵소트보다 느림.
    // 표준 퀵소트는 안정성을 고려하여 만들었기 때문.

    endTime = (double)clock() / CLOCKS_PER_SEC;

    printf("상위 10:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d위 - 번호: %d, 점수: %lf\n", i + 1, DataSet[i].number, DataSet[i].score);
    }

    printf("\n하위 10:\n");
    for (int i = Length - 10; i < Length; i++)
    {
        printf("%d위 - 번호: %d, 점수: %lf\n", i + 1, DataSet[i].number, DataSet[i].score);
    }

    printf("\n3만개 데이터 소팅 시간: %lf sec\n", endTime - startTime);

    return 0;
}