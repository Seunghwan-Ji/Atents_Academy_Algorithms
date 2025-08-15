/*
카프리카 수
카프리카 수란 인도의 수학자 D.R.카프리카의 의해 정의한 수이고, 정수만을 대상으로 정의된 개념이다.

어떤 수의 제곱수를 두 부분으로 나누어 더하였을 때 다시 원래의 수가 되는 수들을 의미한다.

예를 들어 45는 카프리카 수인데, 45^2 = 2025이고, 20+25 = 45이기 때문이다.
(ex2 n = 297, n의 자릿수 = 3, n^2 = 88209를 오른쪽에서 3자리를 자름)

1. 어떤 수를 입력 받고 그 수가 카프리카 수인지 아닌지를 출력하는 함수를 만드시오.

2. 어떤 수를 입력 받고 자릿수가 그 수인 모든 카프리카 수를 출력하시오. (ex 입력: 2 -> 모든 두 자리수 중에서 카프리카인 수  찾기.

3. 어떤 수를 입력 받고 어떤 수 이하의 모든 카프리카 수를 출력하시오.

이 셋중에서 원하는 유형 하나를 골라 푸시오.

입력 (유형 1)

print(kaprekar_number(1))
print(kaprekar_number(45))
print(kaprekar_number(297))
print(kaprekar_number(3213))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ClearUnReadBuffer() {
	int clear = 0;

	while (getchar() != '\n') { clear = 1; }

	return clear;
}

int IsAllDigits(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
	}

	return 1;
}

int IsKaprekar(int number) {
	printf("\n대상: %d\n", number);
	char cNumber[10]; sprintf_s(cNumber, sizeof(cNumber), "%d", number);
	int numberDigits = (int)strlen(cNumber);

	long long numberLL = (long long)number; // 제곱시 int 범위 초과 방지.
	unsigned long long iSquareNumber = numberLL * numberLL; printf("제곱값: %llu\n", iSquareNumber);
	char cSquareNumber[24]; sprintf_s(cSquareNumber, sizeof(cSquareNumber), "%llu", iSquareNumber);
	int SquareNumberDigits = (int)strlen(cSquareNumber);

	int splitStartIndex = SquareNumberDigits - numberDigits;

	char cPart1[10];
	char cPart2[10];

	for (int i = 0; i < splitStartIndex; i++) {
		cPart1[i] = cSquareNumber[i];
	}

	cPart1[splitStartIndex] = '\0';

	int part2Index = 0;
	for (int i = splitStartIndex; i < SquareNumberDigits; i++) {
		cPart2[part2Index] = cSquareNumber[i];
		part2Index++;
	}

	cPart2[part2Index] = '\0';

	int iPart1 = atoi(cPart1); printf("파트1: %d\n", iPart1);
	int iPart2 = atoi(cPart2); printf("파트2: %d\n", iPart2);
	int sumPart = iPart1 + iPart2; printf("%d + %d = %d\n", iPart1, iPart2, sumPart);

	return sumPart == number;
}

void Case1() {
	printf("\n1. 어떤 수 N이 카프리카 수인지 판별\n\n");

	char inputNumber[10];

	while (1) {
		printf("9자리 이하 정수를 입력하세요: ");
		scanf_s("%9s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n입력 제한 글자 수 초과. 다시 입력하세요.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n숫자만 입력하세요.\n\n");
		}
		else {
			break;
		}
	}

	int iNumber = atoi(inputNumber);

	if (IsKaprekar(iNumber)) {
		printf("\n입력하신 숫자 %d은(는) 카프리카 수입니다.\n", iNumber);
	}
	else
	{
		printf("\n입력하신 숫자 %d은(는) 카프리카 수가 아닙니다.\n", iNumber);
	}
}

void Case2() {
	printf("\n2. N자릿수 중에서 모든 카프리카 수 찾기\n\n");

	char inputNumber[2];

	while (1) {
		printf("N을 입력하세요(0 < N < 10): ");
		scanf_s("%1s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n입력 제한 글자 수 초과. 다시 입력하세요.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n숫자만 입력하세요.\n\n");
		}
		else {
			break;
		}
	}

	int digit = atoi(inputNumber);
	int min = digit == 1 ? 0 : (int)pow(10, digit - 1);
	int max = (int)pow(10, digit) - 1;

	int capacity = 10;
	int* array = malloc(sizeof(int) * capacity);
	if (!array) {
		printf("메모리 초기 할당 실패\n");
		return;
	}

	int arrIndex = 0;

	for (int i = min; i <= max; i++) {
		if (IsKaprekar(i)) {
			array[arrIndex] = i;
			arrIndex++;

			if (arrIndex == capacity) {
				capacity *= 2;

				int* tempArr = realloc(array, sizeof(int) * capacity);
				if (!tempArr) {
					printf("메모리 재할당 실패\n");
					free(array);
					return;
				}

				array = tempArr;
			}
		}
	}

	printf("\n%d자릿수 중에서 모든 카프리카 수:\n", digit);

	for (int i = 0; i < arrIndex; i++) {
		printf("%d, ", array[i]);
	}

	free(array);
}

void Case3() {

}

/*
int CharNumberToIntNumber(const char* array) {
	unsigned int result = 0;

	for (int i = 0; array[i] != '\0'; i++) {
		result = result * 10 + (array[i] - '0');
	}

	return result;
}
*/

int main()
{
	char inputNumber[2];

	while (1) {
		printf("1. 어떤 수 N이 카프리카 수인지 판별(숫자 1 입력)\n");
		printf("2. N자릿수 중에서 모든 카프리카 수 찾기(숫자 2 입력)\n");
		printf("3. 어떤 수 N이하의 모든 카프리카 수 찾기(숫자 3 입력)\n");
		printf("\n입력: ");
		scanf_s("%1s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n입력 제한 글자 수 초과. 다시 입력하세요.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n숫자만 입력하세요.\n\n");
		}
		else {
			break;
		}
	}

	switch (inputNumber[0]) {
	case '1':
		Case1(); break;
	case '2':
		Case2(); break;
	case '3':
		Case3(); break;
	}	
}