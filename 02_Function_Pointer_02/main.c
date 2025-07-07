#include <stdio.h>

// 함수 포인터
// 함수형

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

	// threeMul함수의 주소값을 인자값으로 전달해서 계산하는 함수를 
	// 만들고 실행시켜서 결과값을 출력해 보세요...

	int d = 40;

	c = Calculator2(threeMul, a, b, d);
	printf("%d * %d * %d = %f\n", a, b, d, c);

	return 0;
}
