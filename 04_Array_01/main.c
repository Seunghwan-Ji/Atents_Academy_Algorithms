#include <stdio.h>

// 배열
// 동일한 DataType의 공간이 여러개 필요할때.

void SetArray(int* parray, int size) {
    for (int i = 0; i < size; i++) {
        parray[i] = i;
    }
}


void PrintArray(int* parray, int size) {
    for (int i = 0; i < size; i++) {
        printf("parray[%d] = %d\n", i, parray[i]);
    }
}

int main() {
    // DataType 배열명[요소의갯수];

    int array[10];

    // 배열명은 주소상수

    //array = 10;

    int array2[100];

    SetArray(array2, 100);

    PrintArray(array2, 100);



    return 0;
}