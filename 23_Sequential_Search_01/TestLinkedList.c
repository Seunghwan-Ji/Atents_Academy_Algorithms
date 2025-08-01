#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. 순차탐색
// 싱글링크드 리스트에 저장된 3만개의 데이타 안에서 Target매개변수에 전달된 값을 가진 노드를 찾고
// 해당 노드의 주소값을 전달한다.
Node* SequentialSearch(Node* Head, double Target)
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
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트의
// 맨앞으로 이동시킨다(헤드노드로 만들다.)
Node* MoveToFront(Node** Head, double Target)
{
	Node* tempNode = *Head;
	Node* prevNode = NULL;

	while (tempNode != NULL)
	{
		if (tempNode->Data.score == Target)
			break;

		prevNode = tempNode;
		tempNode = tempNode->NextNode;
	}

	if (tempNode == NULL)
		return NULL;

	if (prevNode != NULL)
	{
		prevNode->NextNode = tempNode->NextNode;
		tempNode->NextNode = *Head;
		*Head = tempNode;
	}

	return tempNode;
}

// 3. 전위법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트에서
// 한칸 앞쪽으로 이동시킨다.
Node* Transpose(Node** Head, double Target)
{
	Node* tempNode = *Head;
	Node* prevNode = NULL;
	Node* prevPrevNode = NULL;

	while (tempNode != NULL)
	{
		if (tempNode->Data.score == Target)
			break;

		if (prevNode != NULL)
			prevPrevNode = prevNode;

		prevNode = tempNode;
		tempNode = tempNode->NextNode;
	}

	if (tempNode == NULL)
		return NULL;

	if (prevNode != NULL)
	{
		prevNode->NextNode = tempNode->NextNode;
		tempNode->NextNode = prevNode;
		
		if (prevPrevNode != NULL)
			prevPrevNode->NextNode = tempNode;
		else // 찾은 노드가 헤드 노드 다음인 경우.
			*Head = tempNode;
	}

	return tempNode;
}

// 4. 계수법
// Node에 빈도수(Frequency)를 저장하는 변수를 만들고
// Target 값을 가진 노드를 찾고, 그 노드의 Frequency(빈도수)를 1 증가시킨 후,
// 리스트 내에서 더 자주 조회된 순서로 앞으로 정렬되도록 위치를 옮긴다.
Node* FrequencyMethod(Node** Head, double Target)
{
	Node* findedNode = *Head;
	Node* findedPrevNode = NULL;

	while (findedNode != NULL)
	{
		if (findedNode->Data.score == Target)
		{
			findedNode->Frequency++;
			break;
		}

		findedPrevNode = findedNode;
		findedNode = findedNode->NextNode;
	}

	if (findedNode == NULL)
		return NULL;

	Node* currentNode = *Head;
	Node* prevNode = NULL;

	while (currentNode != NULL)
	{
		if (findedNode->Frequency > currentNode->Frequency)
		{
			if (findedPrevNode != NULL)
				findedPrevNode->NextNode = findedNode->NextNode;

			if (prevNode != NULL)
				prevNode->NextNode = findedNode;
			else
				*Head = findedNode;
			
			findedNode->NextNode = currentNode;
			break;
		}
		else if (findedNode->Frequency == currentNode->Frequency &&
			findedNode == currentNode)
		{
			return findedNode;
		}

		prevNode = currentNode;
		currentNode = currentNode->NextNode;
	}

	return findedNode;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;  // 헤드노드주소값을 저장
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// 찾는 값을 저장하는 변수

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet 배열요소의 갯수 (30000개)

	//  노드 30000개 추가 
	for (i = 0; i < Length; i++)
	{
		NewNode = SLL_CreateNode(DataSet[i]);
		SLL_AppendNode(&List, NewNode);
	}

	// 찾는 값을 찾는 반복연산
	
	while (1)
	{
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0)
		{
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL)
		{	// 찾는 score값을 가진 노드를 찾은 경우
			printf("MATCH!!!! searchValue Frequency: %d, number: %d, score: %lf\n",
				targetNode->Frequency, targetNode->Data.number, targetNode->Data.score);
		}
		else
		{	// 찾는 score값을 가진 노드를 못 찾은 경우
			printf("찾는 값을 가진 노드가 없음!!!!\n");
		}

		// 앞에 10개
		for (int i = 0; i < 10; i++)
		{
			Current = SLL_GetNodeAt(List, i);
			printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
				i, Current->Frequency, Current->Data.number, Current->Data.score);
		}

		printf("===============================================\n");

		for (int i = Length - 10; i < Length; i++)
		{
			Current = SLL_GetNodeAt(List, i);
			printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
				i, Current->Frequency, Current->Data.number, Current->Data.score);
		}

	}	

	//  모든 노드를 메모리에서 제거     
	printf("\nDestroying List...\n");

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}
