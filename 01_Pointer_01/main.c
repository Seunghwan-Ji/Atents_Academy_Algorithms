#include <stdio.h>

// 포인터형

int main() {
	int a = 0;

	a = 20;

	printf("&a = %p\n", &a); // &: 주소연산자 (변수명앞에 사용해서 변수의 주소값을 돌려줍니다.)

	// 포인터형

	int* pa;  // 변수를 만들때 사용한 *(asterisk)는 포인터형 지정자입니다.

	pa = &a;

	int** ppa;

	ppa = &pa;

	**ppa;  // 주소값 앞에 *(asterisk)는 포인터 연산자
	**&pa;
	*pa;
	*&a;
	a;

	printf("&**ppa = %p\n", &**ppa);
	printf("&**&pa = %p\n", &**&pa);
	printf("&*pa = %p\n", &*pa);
	printf("&*&a = %p\n", &*&a);
	printf("&a = %p\n", &a);

	*pa = 2000;

	printf("**ppa = %d\n", **ppa);
	printf("**&pa = %d\n", **&pa);
	printf("*pa = %d\n", *pa);
	printf("*&a = %d\n", *&a);
	printf("a = %d\n", a);







	return 0;
}