#include <stdio.h>

// �Լ��� ���ڸ� �����ϴ� ���
// 1. call by value (���� ���� ȣ��)
// 2. call by address (�ּҰ��� ���� ȣ��)

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


	//pa������ �ּҰ��� pb������ �ּҰ��� ���ڷ� �޾� a������ b������ ���� �ٲٴ�
	// �Լ��� ����� ������ ������..

	printf("before a = %d, b = %d\n", a, b);
	PPSwap(&pa, &pb);
	printf("after a = %d, b = %d\n", a, b);


	return 0;
}