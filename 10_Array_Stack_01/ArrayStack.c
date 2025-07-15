#include "ArrayStack.h"

// 문제 1. 스택이 가득찼는지 판단하는 함수를 만드세요.
int AS_IsFull(ArrayStack* Stack)
{
	return (Stack->Top + 1 == Stack->Capacity);
}

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택을 자유 저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// 입력된 Capacity 만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// 노드를 자유 저장소에서 해제
	free(Stack->Nodes);

	// 스택을 자유 저장소에서 해제
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
	if (AS_IsFull(Stack))
	{
		Stack->Capacity *= 2;
		Stack->Nodes = (Node*)realloc(Stack->Nodes, sizeof(Node) * (Stack->Capacity));
	}

	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}