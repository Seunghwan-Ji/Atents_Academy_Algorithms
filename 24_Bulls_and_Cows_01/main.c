#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Bulls and Cows라는 간단한 게임을 프로그램으로 만들어보자.
<게임 규칙>
먼저 컴퓨터가 0부터 9까지의 숫자중 4개를 중복없이 배열한 문자열을 랜덤하게 생성한다.
플레이어는 생성된 문자열을 예상하여 1턴에 1번씩 입력할 수 있다.
컴퓨터는 플레이어가 입력한 문자열을 정답과 비교하여 값과 위치가 모두 맞는 숫자의 갯수를 'Bulls'
위치는 틀렸지만 값은 맞는 숫자의 갯수를 'Cows'로 카운트하여 매턴마다
사용자의 입력에 대해 Bulls와 Cows값을 알려준다.
플레이어는 10턴 안에 정답을 맞춰야한다.

<세부 사항>
판정의 출력형식은 (Bulls값)B(Cows값)C 로 한다. ex) 답이 1234일때 0124를 입력하면 1B2C 를 출력
판정을 출력할때마다 사용자가 입력한 횟수N(=현재 턴수)을 함께 출력한다.
ex>판정: 1B2C, 입력한 횟수: 2
형식에 맞지 않는 잘못된 입력(ex>2211, a1bc, 209111 등)을 한 경우는 에러 메시지를 출력하고
N은 변하지 않는다.
단 이미 입력했던 값을 다시 입력하는것은 괜찮다.
플레이어가 정답을 맞추면, "정답입니다. 총 입력한 횟수: N"를 출력한다.
10턴이 지나도 정답을 맞추지 못하면 정답을 공개하고 Game Over 메시지를 출력한다.
플레이어가 정답을 맞추거나 Game Over가 되면, 다시 처음부터 게임을 시작할지 종료할지 물어본다.
이때 플레이어가 1을 입력하면 처음부터 게임을 다시 시작하고
0을 입력하면 게임을 종료한다(그 외의 입력에는 에러를 출력하고 다시 물어본다)
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
				printf("숫자를 중복없이 입력하세요.\n\n");
				return 0;
			}
			else
				tempArr[i] = array[i];

			break;
		default:
			printf("4자리 숫자만 입력하세요.\n\n");
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

int ClearReadBuffer() // scanf_s 함수가 읽지 않은 입력 버퍼 읽어서 비우도록 처리.
{
	int clear = 0;

	while (getchar() != '\n') // 줄바꿈 문자를 읽었으면 종료.
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

	printf("Bulls and Cows 게임을 시작합니다.\n\n");

	for (int i = 0; i < 10; i++)
	{
		char InputCorrect[5];

		while (1)
		{
			printf("정답 입력: ");
			scanf_s("%4s", InputCorrect, (unsigned int)sizeof(InputCorrect));
			
			if (ClearReadBuffer())
			{
				printf("다시 입력하세요.\n\n");
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
			printf("정답입니다. 총 입력한 횟수: %d\n\n", i + 1);
			win = 1;
			break;
		}
		else
		{
			printf("판정: %s, 입력한 횟수: %d\n\n", InputCorrect, i + 1);
		}
	}

	if (!win)
	{
		printf("Game Over\n");
		printf("정답: %s\n\n", numberArr);
	}

	char answer[2];
	
	while (1)
	{
		printf("게임을 처음부터 다시 시작하겠습니까? (네: 1, 아니오: 0): ");
		scanf_s("%1s", answer, (unsigned int)sizeof(answer));

		if (ClearReadBuffer())
		{
			printf("다시 입력하세요.\n\n");
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
			printf("입력 오류\n\n");
			break;
		}
	}
}