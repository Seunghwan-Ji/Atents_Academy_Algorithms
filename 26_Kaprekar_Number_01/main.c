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

	unsigned long long iSquareNumber = number * number; printf("������: %llu\n", iSquareNumber);
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

	int iPart1 = atoi(cPart1); printf("��Ʈ1: %d\n", iPart1);
	int iPart2 = atoi(cPart2); printf("��Ʈ2: %d\n", iPart2);
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
	
	printf("ī����ī �� �Ǻ���\n\n");

	while (1) {
		printf("9�ڸ� ���� ������ �Է��ϼ���: ");
		scanf_s("%9s", cNumber, (unsigned int)sizeof(cNumber));

		if (ClearUnReadBuffer()) {
			printf("\n�Է� ���� ���� �� �ʰ�. �ٽ� �Է��ϼ���.\n");
		}
		else if (!IsAllDigits(cNumber)) {
			printf("\n���ڸ� �Է��ϼ���.\n");
		}
		else {
			break;
		}
	}

	int iNumber = atoi(cNumber);

	if (IsKaprekar(iNumber)) {
		printf("\n�Է��Ͻ� ���� %d��(��) ī����ī ���Դϴ�.\n", iNumber);
	}
	else
	{
		printf("\n�Է��Ͻ� ���� %d��(��) ī����ī ���� �ƴմϴ�.\n", iNumber);
	}
}