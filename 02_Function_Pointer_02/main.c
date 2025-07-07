#include <stdio.h>

// �Լ� ������
// �Լ���

float add(int a, int b) {
	return a + (float)b;
}

float div(int a, int b) {
	return a / (float)b;
}

float threeMul(int a, int b, int c) {
	return a * b * c;
}

float Calculator(float(*pfunc)(int, int), int a, int b) {
	return pfunc(a, b);
}

float Calculator2(float(*pfunc)(int, int, int), int a, int b, int c) {
	return pfunc(a, b, c);
}

int main() {
	int a = 20;
	int b = 30;

	float c = 0.0f;

	c = Calculator(add, a, b);
	printf("%d + %d = %f\n", a, b, c);

	c = Calculator(div, a, b);
	printf("%d / %d = %f\n", a, b, c);

	// threeMul�Լ��� �ּҰ��� ���ڰ����� �����ؼ� ����ϴ� �Լ��� 
	// ����� ������Ѽ� ������� ����� ������...

	int d = 40;

	c = Calculator2(threeMul, a, b, d);
	printf("%d * %d * %d = %f\n", a, b, d, c);

	return 0;
}
