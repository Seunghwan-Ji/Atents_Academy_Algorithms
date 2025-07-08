#include <stdio.h>

// 재귀호출(recursive call)
// 탈출 조건의 명확해야 함.
// stack overflow
// 함수가 자기자신을 자신의 내부에서 호출

int factorial(int n) {

    if (n == 1) { // 탈출 조건
        return 1;
    }


    return n * factorial(n - 1);
}



int main() {

    int ret = factorial(5);

    printf("5! = %d\n", ret);

    return 0;
}