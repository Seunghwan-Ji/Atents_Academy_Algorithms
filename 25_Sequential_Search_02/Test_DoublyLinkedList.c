#include "DoublyLinkedList.h"
#include "Score.h"
#include "ScoreData.h"


//1. 순차탐색
//순서대로 탐색
//#작동 순서
//탐색할 노드 NULL 확인
//Target Match 되는지 확인
//안되면 다음 -> 찾았으면 return
//끝까지 못 찾았으면 NULL일테니 위에서 거르기
Node* SequntialSearch(Node* Head, double Target)
{
	while (Head != NULL)
	{
		if (Head->Data.score == Target)
			return Head;

		Head = Head->NextNode;
	}

	return NULL;
}

// 2. 전진이동법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 더블링크드 리스트의 맨앞으로 이동시킨다(헤드노드로 만들다.)
Node* MoveToFront(Node** Head, double Target)
{
	Node* findedNode = *Head;

	while (findedNode != NULL)
	{
		if (findedNode->Data.score == Target)
			break;

		findedNode = findedNode->NextNode;
	}

	if (findedNode == NULL)
		return NULL;

	// 끊긴 부분 연결.
	if (findedNode->PrevNode != NULL)
		findedNode->PrevNode->NextNode = findedNode->NextNode;
	else
		return findedNode;
	if (findedNode->NextNode != NULL)
		findedNode->NextNode->PrevNode = findedNode->PrevNode;

	// 헤드에 삽입.
	findedNode->NextNode = *Head;
	findedNode->PrevNode = NULL;

	// 삽입 부분 연결.
	(*Head)->PrevNode = findedNode;

	// 헤드 갱신.
	*Head = findedNode;

	return findedNode;
}

//3. 전위법
//한 칸 앞으로
Node* Transpose(Node** Head, double Target)
{
	Node* findedNode = *Head;

	while (findedNode != NULL)
	{
		if (findedNode->Data.score == Target)
			break;

		findedNode = findedNode->NextNode;
	}

	if (findedNode == NULL)
		return NULL;

	// 끊긴 부분 연결.
	if (findedNode->PrevNode != NULL)
		findedNode->PrevNode->NextNode = findedNode->NextNode;
	else
		return findedNode;
	if (findedNode->NextNode != NULL)
		findedNode->NextNode->PrevNode = findedNode->PrevNode;

	if (findedNode->PrevNode->PrevNode != NULL)
	{
		// 삽입.
		findedNode->NextNode = findedNode->PrevNode;
		findedNode->PrevNode = findedNode->PrevNode->PrevNode;

		// 삽입 부분 연결.
		findedNode->PrevNode->NextNode = findedNode;
		findedNode->NextNode->PrevNode = findedNode;
	}			
	else // 찾은 노드가 헤드 노드 다음인 경우.
	{
		// 헤드에 삽입.
		findedNode->NextNode = *Head;
		findedNode->PrevNode = NULL;
			
		// 삽입 부분 연결.
		(*Head)->PrevNode = findedNode;

		// 헤드 갱신.
		*Head = findedNode;
	}

	return findedNode;
}

//4. 계수법
//조회수(탐색횟수)에 따른 이동
Node* FrequencyMethod(Node** Head, double Target)
{
	Node* findedNode = *Head;

	while (findedNode != NULL)
	{
		if (findedNode->Data.score == Target)
		{
			findedNode->Frequency++;
			break;
		}

		findedNode = findedNode->NextNode;
	}

	if (findedNode == NULL)
		return NULL;

	Node* currentNode = *Head;

	while (currentNode != NULL)
	{
		if (findedNode->Frequency > currentNode->Frequency)
		{
			// 끊긴 부분 연결.
			if (findedNode->PrevNode != NULL)
				findedNode->PrevNode->NextNode = findedNode->NextNode;
			if (findedNode->NextNode != NULL)
				findedNode->NextNode->PrevNode = findedNode->PrevNode;

			// 삽입.
			findedNode->NextNode = currentNode;
			findedNode->PrevNode = currentNode->PrevNode;

			// 삽입 부분 연결.
			if (currentNode->PrevNode != NULL)
				currentNode->PrevNode->NextNode = findedNode;
			else // 현재 노드가 헤드.
				*Head = findedNode; // 헤드 갱신.
			currentNode->PrevNode = findedNode;

			break;
		}
		else if (findedNode->Frequency == currentNode->Frequency &&
			findedNode == currentNode)
			break;

		currentNode = currentNode->NextNode;
	}

	return findedNode;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	double InputValue = 0.0;	// 찾는 값(lf)을 저장하는 변수

	int Length = sizeof DataSet / sizeof DataSet[0];
	/*  노드 30,000개 추가 */
	for (i = 0; i < Length; i++)
	{
		NewNode = DLL_CreateNode(DataSet[i]);
		DLL_AppendNode(&List, NewNode);
	}

	//Current = DLL_CreateNode(8000);     // 8000값을 현재 노드로 만든다.
	//DLL_InsertNewHead(&List, Current);  //헤드 노드를 바꾼다.


	while (1) {
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	//찾는 Score값을 가진 노드를 찾은 경우
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// 찾는 score값을 가진 노드를 찾지 못함 (값이 없는 경우)
			printf("찾는 값을 가진 노드가 없음!!!\n");
		}

		// 앞에 10개
		for (int i = 0; i < 10; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================================================\n");

		// 뒤에 10개
		for (int i = Length - 10; i < Length; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	/*  모든 노드를 메모리에서 제거     */
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