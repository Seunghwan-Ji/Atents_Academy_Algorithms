#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char cNumber[10]; sprintf_s(cNumber, sizeof(cNumber), "%d", number);
	int numberDigits = (int)strlen(cNumber);

	unsigned long long iSquareNumber = number * number; printf("제곱값: %llu\n", iSquareNumber);
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
	char cNumber[10];
	
	printf("카프리카 수 판별기\n\n");

	while (1) {
		printf("9자리 이하 정수를 입력하세요: ");
		scanf_s("%9s", cNumber, (unsigned int)sizeof(cNumber));

		if (ClearUnReadBuffer()) {
			printf("\n입력 제한 글자 수 초과. 다시 입력하세요.\n");
		}
		else if (!IsAllDigits(cNumber)) {
			printf("\n숫자만 입력하세요.\n");
		}
		else {
			break;
		}
	}

	int iNumber = atoi(cNumber);

	if (IsKaprekar(iNumber)) {
		printf("\n입력하신 숫자 %d은(는) 카프리카 수입니다.\n", iNumber);
	}
	else
	{
		printf("\n입력하신 숫자 %d은(는) 카프리카 수가 아닙니다.\n", iNumber);
	}
}