#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Bulls and Cows��� ������ ������ ���α׷����� ������.
<���� ��Ģ>
���� ��ǻ�Ͱ� 0���� 9������ ������ 4���� �ߺ����� �迭�� ���ڿ��� �����ϰ� �����Ѵ�.
�÷��̾�� ������ ���ڿ��� �����Ͽ� 1�Ͽ� 1���� �Է��� �� �ִ�.
��ǻ�ʹ� �÷��̾ �Է��� ���ڿ��� ����� ���Ͽ� ���� ��ġ�� ��� �´� ������ ������ 'Bulls'
��ġ�� Ʋ������ ���� �´� ������ ������ 'Cows'�� ī��Ʈ�Ͽ� ���ϸ���
������� �Է¿� ���� Bulls�� Cows���� �˷��ش�.
�÷��̾�� 10�� �ȿ� ������ ������Ѵ�.

<���� ����>
������ ��������� (Bulls��)B(Cows��)C �� �Ѵ�. ex) ���� 1234�϶� 0124�� �Է��ϸ� 1B2C �� ���
������ ����Ҷ����� ����ڰ� �Է��� Ƚ��N(=���� �ϼ�)�� �Բ� ����Ѵ�.
ex>����: 1B2C, �Է��� Ƚ��: 2
���Ŀ� ���� �ʴ� �߸��� �Է�(ex>2211, a1bc, 209111 ��)�� �� ���� ���� �޽����� ����ϰ�
N�� ������ �ʴ´�.
�� �̹� �Է��ߴ� ���� �ٽ� �Է��ϴ°��� ������.
�÷��̾ ������ ���߸�, "�����Դϴ�. �� �Է��� Ƚ��: N"�� ����Ѵ�.
10���� ������ ������ ������ ���ϸ� ������ �����ϰ� Game Over �޽����� ����Ѵ�.
�÷��̾ ������ ���߰ų� Game Over�� �Ǹ�, �ٽ� ó������ ������ �������� �������� �����.
�̶� �÷��̾ 1�� �Է��ϸ� ó������ ������ �ٽ� �����ϰ�
0�� �Է��ϸ� ������ �����Ѵ�(�� ���� �Է¿��� ������ ����ϰ� �ٽ� �����)
*/

int IsValidInput(const char* array, int length)
{
	char tempArr[5];

	for (int i = 0; i < length - 1; i++)
	{
		switch (array[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (IsNumberInArray(tempArr, length, array[i]))
			{
				printf("���ڸ� �ߺ����� �Է��ϼ���.\n\n");
				return 0;
			}
			else
				tempArr[i] = array[i];

			break;
		default:
			printf("4�ڸ� ���ڸ� �Է��ϼ���.\n\n");
			return 0;
		}
	}

	return 1;
}

int IsNumberInArray(const char* array, int length, char number)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] == number)
		{
			return 1;
		}
	}

	return 0;
}

void PrintArray(const char* array, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		printf("%c, ", array[i]);
	}
	printf("\n");
}

enum type
{
	Bulls,
	Cows,
	None
};

int IsBullsOrCows(const char* array, int length, char number, int index)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] == number && i == index)
		{
			return Bulls;
		}
		else if (array[i] == number)
		{
			return Cows;
		}
	}

	return None;
}

int IsCorrect(const char* array, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] != 'B')
			return 0;
	}

	return 1;
}

int ClearReadBuffer() // scanf_s �Լ��� ���� ���� �Է� ���� �о ��쵵�� ó��.
{
	int clear = 0;

	while (getchar() != '\n') // �ٹٲ� ���ڸ� �о����� ����.
		clear = 1;

	return clear;
}

int main()
{
	char numberArr[5];
	int length = sizeof(numberArr);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < length - 1; i++)
	{
		while (1)
		{
			char randNum = '0' + rand() % 10;

			if (!IsNumberInArray(numberArr, length, randNum))
			{
				numberArr[i] = randNum;
				break;
			}
		}
	}

	numberArr[length - 1] = '\0';

	// PrintArray(numberArr, length);

	int win = 0;

	printf("Bulls and Cows ������ �����մϴ�.\n\n");

	for (int i = 0; i < 10; i++)
	{
		char InputCorrect[5];

		while (1)
		{
			printf("���� �Է�: ");
			scanf_s("%4s", InputCorrect, (unsigned int)sizeof(InputCorrect));
			
			if (ClearReadBuffer())
			{
				printf("�ٽ� �Է��ϼ���.\n\n");
				continue;
			}

			if (IsValidInput(InputCorrect, length))
				break;
		}

		for (int j = 0; j < length - 1; j++)
		{
			int type = IsBullsOrCows(numberArr, length, InputCorrect[j], j);

			switch (type)
			{
			case Bulls:
				InputCorrect[j] = 'B';
				break;
			case Cows:
				InputCorrect[j] = 'C';
				break;
			}
		}

		if (IsCorrect(InputCorrect, length))
		{
			printf("�����Դϴ�. �� �Է��� Ƚ��: %d\n\n", i + 1);
			win = 1;
			break;
		}
		else
		{
			printf("����: %s, �Է��� Ƚ��: %d\n\n", InputCorrect, i + 1);
		}
	}

	if (!win)
	{
		printf("Game Over\n");
		printf("����: %s\n\n", numberArr);
	}

	char answer[2];
	
	while (1)
	{
		printf("������ ó������ �ٽ� �����ϰڽ��ϱ�? (��: 1, �ƴϿ�: 0): ");
		scanf_s("%1s", answer, (unsigned int)sizeof(answer));

		if (ClearReadBuffer())
		{
			printf("�ٽ� �Է��ϼ���.\n\n");
			continue;
		}

		switch (answer[0])
		{
		case '1':
			printf("\n");
			main();
			return;
		case '0':
			return;
		default:
			printf("�Է� ����\n\n");
			break;
		}
	}
}