#include <stdio.h>
#include <string.h>

// 구조체
// 서로 연관성있는 Data를 하나로 묶을때 사용합니다.
// 이런 연결 형태를 LikedList 라고 부른다.

typedef struct tagCar { // 사용자 정의 데이타 타입
	char modelName[40]; // 구조체 멤버
	int maxSpeed;
	int wheelCount;

	struct tagCar* Next;
} Car;

int main() {

	struct tagCar car = { "QM6", 150, 4, NULL };


	Car car1 = { "BMW", 200, 4, NULL };
	Car car2 = { "제네시스", 200, 4, NULL };
	Car car3 = { "포터", 150, 6, NULL };
	Car car4 = { "오토바이", 200, 2, NULL };

	car1.Next = &car2;
	car2.Next = &car3;
	car3.Next = &car4;

	printf("car4.name = %s\n", car1.Next->Next->Next->modelName);
	printf("car4.maxSpeed = %d\n", car1.Next->Next->Next->maxSpeed);
	printf("car4.wheelCount = %d\n", car1.Next->Next->Next->wheelCount);
	printf("\n\n");
	// car1으로 car3에 접근해서
	// name 멤버에는 EV6 , MaxSpeed : 200, Wheelcount : 4 의 값을 저장하고
	// Car3의 멤버의 값을 출력해보세요..

	strcpy_s(car1.Next->Next->modelName, sizeof(car1.Next->Next->modelName), "EV6");
	// sizeof 함수는 프로그램 실행 도중이 아닌 컴파일 단계에서 실행된다.
	// 따라서 메인 함수 내에서만 사용 가능.
	car1.Next->Next->maxSpeed = 200;
	car1.Next->Next->wheelCount = 4;

	printf("car3.name = %s\n", car1.Next->Next->modelName);
	printf("car3.maxSpeed = %d\n", car1.Next->Next->maxSpeed);
	printf("car3.wheelCount = %d\n", car1.Next->Next->wheelCount);


	return 0;
}