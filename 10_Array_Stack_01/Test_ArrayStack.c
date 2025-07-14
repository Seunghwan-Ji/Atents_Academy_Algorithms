#include "ArrayStack.h"

int main(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	printf("Capacity: %d, Size: %d, Top: %d\n\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
	
	for (i = 0; i < 4; i++)
	{
		if (AS_IsEmpty(Stack))
			break;

		printf("Popped: %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}

	AS_DestroyStack(Stack);

	// 문제 2. 스택의 Capacity를 50개로 설정하고 while문으로 Stack이 가득 찰때까지 처음 값 100을
	// 증가시키면서 저장하고 스택이 빌때까지 값을 출력해보세요..
	printf("\nQ 02)\n");

	AS_CreateStack(&Stack, 50);
	AS_Push(Stack, 100);

	while (!AS_IsFull(Stack))
	{
		AS_Push(Stack, AS_Top(Stack) + 1);
	}

	while (!AS_IsEmpty(Stack))
	{
		printf("%d\n", AS_Pop(Stack));
	}

	AS_DestroyStack(Stack);

	// extra
	// 스택에 값을 Push하다가 용량이 부족하면 동적배열의 용량을 2배 늘려서 값을 저장하도록
	// 만들어 보세요.
	// 테스트 초기에 용량을 50개로 설정하고 100개를 저장해서 값을 출력해보세요.
	printf("\nQ 03)\n");

	AS_CreateStack(&Stack, 50);
	AS_Push(Stack, 100);

	while (Stack->Top + 1 < 101)
	{
		AS_Push(Stack, AS_Top(Stack) + 1);
	}

	while (!AS_IsEmpty(Stack))
	{
		printf("%d\n", AS_Pop(Stack));
	}

	AS_DestroyStack(Stack);

	return 0;
}