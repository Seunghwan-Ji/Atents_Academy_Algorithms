/*
ī����ī ��
ī����ī ���� �ε��� ������ D.R.ī����ī�� ���� ������ ���̰�, �������� ������� ���ǵ� �����̴�.

� ���� �������� �� �κ����� ������ ���Ͽ��� �� �ٽ� ������ ���� �Ǵ� ������ �ǹ��Ѵ�.

���� ��� 45�� ī����ī ���ε�, 45^2 = 2025�̰�, 20+25 = 45�̱� �����̴�.
(ex2 n = 297, n�� �ڸ��� = 3, n^2 = 88209�� �����ʿ��� 3�ڸ��� �ڸ�)

1. � ���� �Է� �ް� �� ���� ī����ī ������ �ƴ����� ����ϴ� �Լ��� ����ÿ�.

2. � ���� �Է� �ް� �ڸ����� �� ���� ��� ī����ī ���� ����Ͻÿ�. (ex �Է�: 2 -> ��� �� �ڸ��� �߿��� ī����ī�� ��  ã��.

3. � ���� �Է� �ް� � �� ������ ��� ī����ī ���� ����Ͻÿ�.

�� ���߿��� ���ϴ� ���� �ϳ��� ��� Ǫ�ÿ�.

�Է� (���� 1)

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
	printf("\n���: %d\n", number);
	char cNumber[10]; sprintf_s(cNumber, sizeof(cNumber), "%d", number);
	int numberDigits = (int)strlen(cNumber);

	long long numberLL = (long long)number; // ������ int ���� �ʰ� ����.
	unsigned long long iSquareNumber = numberLL * numberLL; printf("������: %llu\n", iSquareNumber);
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

void Case1() {
	printf("\n1. � �� N�� ī����ī ������ �Ǻ�\n\n");

	char inputNumber[10];

	while (1) {
		printf("9�ڸ� ���� ������ �Է��ϼ���: ");
		scanf_s("%9s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n�Է� ���� ���� �� �ʰ�. �ٽ� �Է��ϼ���.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n���ڸ� �Է��ϼ���.\n\n");
		}
		else {
			break;
		}
	}

	int iNumber = atoi(inputNumber);

	if (IsKaprekar(iNumber)) {
		printf("\n�Է��Ͻ� ���� %d��(��) ī����ī ���Դϴ�.\n", iNumber);
	}
	else
	{
		printf("\n�Է��Ͻ� ���� %d��(��) ī����ī ���� �ƴմϴ�.\n", iNumber);
	}
}

void Case2() {
	printf("\n2. N�ڸ��� �߿��� ��� ī����ī �� ã��\n\n");

	char inputNumber[2];

	while (1) {
		printf("N�� �Է��ϼ���(0 < N < 10): ");
		scanf_s("%1s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n�Է� ���� ���� �� �ʰ�. �ٽ� �Է��ϼ���.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n���ڸ� �Է��ϼ���.\n\n");
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
		printf("�޸� �ʱ� �Ҵ� ����\n");
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
					printf("�޸� ���Ҵ� ����\n");
					free(array);
					return;
				}

				array = tempArr;
			}
		}
	}

	printf("\n%d�ڸ��� �߿��� ��� ī����ī ��:\n", digit);

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
		printf("1. � �� N�� ī����ī ������ �Ǻ�(���� 1 �Է�)\n");
		printf("2. N�ڸ��� �߿��� ��� ī����ī �� ã��(���� 2 �Է�)\n");
		printf("3. � �� N������ ��� ī����ī �� ã��(���� 3 �Է�)\n");
		printf("\n�Է�: ");
		scanf_s("%1s", inputNumber, (unsigned int)sizeof(inputNumber));

		if (ClearUnReadBuffer()) {
			printf("\n�Է� ���� ���� �� �ʰ�. �ٽ� �Է��ϼ���.\n\n");
		}
		else if (!IsAllDigits(inputNumber)) {
			printf("\n���ڸ� �Է��ϼ���.\n\n");
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