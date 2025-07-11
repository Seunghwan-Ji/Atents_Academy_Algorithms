#include "DoublyLInkedLIst.h"

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	// 노드 5개 추가
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 리스트의 세번째 칸 뒤에 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	//  리스트 출력 
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	// 문제 1.
	/*
	   더블링크드 리스트에는 InsertNewHead 함수가 없습니다.
	   InsertNewHead 함수는 헤드노드를 변경하는 함수입니다.
	   더블링크드 리스트에서 작동하는 InsertNewHead 함수를 만들고
	   새로운 노드를 만들어서 값을 6000을 입력하고 새로운 노드를 Head 노드로 만들고 리스트
	   출력해보세요.
	*/
	printf("\n\nQ 01)\n");

	// 노드 5개 추가
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// Before 리스트 출력
	printf("<Before List>\n");
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 데이터 6000 노드 추가
	NewNode = DLL_CreateNode(6000);
	DLL_InsertNewHead(&List, NewNode);

	// After 리스트 출력
	printf("<After List>\n");
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}


	// 문제 2.
	/*
	   DLL_GetNodeCount 함수는 노드의 갯수를 리턴해주는 함수입니다.
	   그런데 노드의 갯수를 세기 위해서 매번 헤드 노드에서부터 꼬리노드까지
	   count를 합니다.
	   이 비효율적인 문제를 해결해보세요....
	*/
	printf("\n\nQ 02)\n");

	// 노드 5개 추가
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 테스트
	Count = DLL_GetNodeCount(List);

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}