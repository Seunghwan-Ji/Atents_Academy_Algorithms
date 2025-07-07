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

int main() {
	printf("&add = %p\n", &add);
	printf("&div = %p\n", &div);
	printf("&threeMul = %p\n", &threeMul);

	add(20, 30);
	// call add

	// 함수포인터
	int a = 20;
	int b = 30;
	float c = 0.0f;

	float(*pfunc)(int, int);   // 함수 포인터 변수

	pfunc = add;

	c = pfunc(a, b);
	printf("%d + %d = %d\n", a, b, c);

	pfunc = div;
	c = pfunc(a, b);
	printf("%d / %d = %f\n", a, b, c);

	// threeMul 함수의 함수 포인터 변수를 만들고
	// 만든 변수에 threeMul 함수의 주소값을 저장하고
	// threeMul 함수의 주소값을 저장한 변수에 인자값을 전달해서
	// threeMul 함수를 호출하고 결과값을 출력해보세요...

	int d = 40;

	float (*pfunc3)(int, int, int);

	pfunc3 = threeMul;
	c = pfunc3(a, b, d);
	printf("%d * %d * %d = %f\n", a, b, d, c);

	return 0;
}
