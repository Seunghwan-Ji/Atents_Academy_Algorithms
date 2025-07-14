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

	// ���� 2. ������ Capacity�� 50���� �����ϰ� while������ Stack�� ���� �������� ó�� �� 100��
	// ������Ű�鼭 �����ϰ� ������ �������� ���� ����غ�����..
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
	// ���ÿ� ���� Push�ϴٰ� �뷮�� �����ϸ� �����迭�� �뷮�� 2�� �÷��� ���� �����ϵ���
	// ����� ������.
	// �׽�Ʈ �ʱ⿡ �뷮�� 50���� �����ϰ� 100���� �����ؼ� ���� ����غ�����.
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