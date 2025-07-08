#include <stdio.h>
#include <stdlib.h>

// 변수
// 생성위치, 사용되는 키워드에 따라서 변수의 성격이 다릅니다.
// 존속기간, 접근범위
int global = 0;   // 외부변수, 전역변수

int GetScore(int value) {
    static int sum = 0;   // 로컬변수, 자동변수-> 정적변수

    return sum;
}

int main() {
    int a = 20;   // 로컬변수(지역변수), 자동변수

    {
        int b = 100;   // 로컬변수, 자동변수
    }

    // 동적메모리 공간
    int count = 0;
    printf("입력하실 정수의 갯수를 입력하세요: ");
    scanf_s("%d", &count);

    printf("\nmalloc\n");
    int* parray = (int*)malloc(sizeof(int) * count);   // 동적메모리 할당
    // malloc 함수는 할당된 공간을 초기화하지 않아서 쓰레기 값이 들어가있다.

    /*for (int i = 0; i < count; i++) {
        parray[i] = i;
    }*/

    for (int i = 0; i < count; i++) {
        printf("parray[%d] = %d\n", i, parray[i]);
    }

    free(parray);   // 동적메모리 공간 반납처리

    // calloc 동적으로 할당된 메모리 공간을 0으로 초기화
    // realloc은 할당 받은 공간을 재할당할때 사용.
    printf("\ncalloc\n");
    float* pfarray = (float*)calloc(count, sizeof(float)); // 동적 메모리 공간을 할당
    // calloc 함수는 할당된 공간을 0으로 초기화한다.

    for (int i = 0; i < count; i++) {
        printf("pfarray[%d] = %f\n", i, pfarray[i]);
    }

    printf("\nrealloc\n");
    pfarray = (float*)realloc(pfarray, sizeof(float) * count * 2);   // 동적메모리 공간 재할당
    // realloc 함수는 이전 값들을 복사한다.

    for (int i = 0; i < count * 2; i++) {
        printf("pfarray[%d] = %f\n", i, pfarray[i]);
    }

    free(pfarray);   // 동적메모리 반납처리


    return 0;
}