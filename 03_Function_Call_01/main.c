#include <stdio.h>

// 함수에 인자를 전달하는 방식
// 1. call by value (값에 의한 호출)
// 2. call by address (주소값에 의한 호출)

// 1. call by value:
void Swap(int a, int b) {
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

// 2. call by address
void PSwap(int* pa, int* pb) {
	int temp = 0;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void PPSwap(int** ppa, int** ppb) {
	int temp = 0;
	temp = **ppa;
	**ppa = **ppb;
	**ppb = temp;
}

int main() {
	int a = 20;
	int b = 30;

	int* pa = &a;
	int* pb = &b;


	Swap(a, b);

	printf("before a = %d, b = %d\n", a, b);
	PSwap(&a, &b);
	printf("after a = %d, b = %d\n", a, b);


	//pa변수의 주소값과 pb변수의 주소값을 인자로 받아 a변수와 b변수의 값을 바꾸는
	// 함수를 만들고 실행해 보세요..

	printf("before a = %d, b = %d\n", a, b);
	PPSwap(&pa, &pb);
	printf("after a = %d, b = %d\n", a, b);


	return 0;
}