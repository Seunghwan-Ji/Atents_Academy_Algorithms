#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// qsort는 내부에서 어떤 자료형을 다루는지 모르고, 그냥 void*로 된 메모리 블록들을 처리한다.
// 그래서 "어떤 요소가 더 큰가, 작은가?"를 사용자가 정의한
// 비교 함수를 호출해서 두 요소를 비교하게 된다.
int ComparePoint(const void* _elem1, const void* _elem2)
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if (*elem1 > *elem2)
        return 1;
    else if (*elem1 < *elem2)
        return -1;
    else
        return 0;

    // 리턴값이
    // < 0(음수) 이면, _elem1이 _elem2보다 작다.
    // = 0       이면, _elem1이 _elem2와 같다.
    // > 0(양수) 이면, _elem1이 _elem2보다 크다.
}

int ComparePointF(const void* _elem1, const void* _elem2) {
    float* elem1 = (float*)_elem1;
    float* elem2 = (float*)_elem2;

    // 오름차순
    if (*elem1 > *elem2) {
        return 1;
    }
    else if (*elem1 < *elem2) {
        return -1;
    }
    else {
        return 0;
    }

    // 내림차순
    /*if (*elem1 < *elem2) {
        return 1;
    }
    else if (*elem1 > *elem2) {
        return -1;
    }
    else {
        return 0;
    }*/
}

int main(void)
{
    int DataSet[] = { 6, 4, 2, 3, 1, 5 };

    float DataSetFloat[] = { 11.2f, 8.9f, 5.4f, 3.4f, 9.9f, 1.2f, 7.8f };


    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    int Lengthf = sizeof DataSetFloat / sizeof(float);

    // qsort: C 표준 라이브러리의 퀵정렬 함수.
    qsort((void*)DataSet, Length, sizeof(int), ComparePoint);


    for (int i = 0; i < Lengthf; i++) {
        printf("%.2f ", DataSetFloat[i]);
    }

    printf("\n");
    qsort((void*)DataSetFloat, Lengthf, sizeof(float), ComparePointF);
    for (int i = 0; i < Lengthf; i++) {
        printf("%.2f ", DataSetFloat[i]);
    }

    return 0;
}
