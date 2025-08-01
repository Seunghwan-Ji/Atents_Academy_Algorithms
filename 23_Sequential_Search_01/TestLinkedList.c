#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. ����Ž��
// �̱۸�ũ�� ����Ʈ�� ����� 3������ ����Ÿ �ȿ��� Target�Ű������� ���޵� ���� ���� ��带 ã��
// �ش� ����� �ּҰ��� �����Ѵ�.
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

// 2. �����̵���
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ��
// �Ǿ����� �̵���Ų��(������ �����.)
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

// 3. ������
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ����
// ��ĭ �������� �̵���Ų��.
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
		else // ã�� ��尡 ��� ��� ������ ���.
			*Head = tempNode;
	}

	return tempNode;
}

// 4. �����
// Node�� �󵵼�(Frequency)�� �����ϴ� ������ �����
// Target ���� ���� ��带 ã��, �� ����� Frequency(�󵵼�)�� 1 ������Ų ��,
// ����Ʈ ������ �� ���� ��ȸ�� ������ ������ ���ĵǵ��� ��ġ�� �ű��.
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
	Node* List = NULL;  // ������ּҰ��� ����
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// ã�� ���� �����ϴ� ����

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet �迭����� ���� (30000��)

	//  ��� 30000�� �߰� 
	for (i = 0; i < Length; i++)
	{
		NewNode = SLL_CreateNode(DataSet[i]);
		SLL_AppendNode(&List, NewNode);
	}

	// ã�� ���� ã�� �ݺ�����
	
	while (1)
	{
		printf("\nã�� score���� �Է��ϼ���: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0)
		{
			printf("ã�� �۾��� �ߴ��ϰ� ���α׷��� �����մϴ�.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL)
		{	// ã�� score���� ���� ��带 ã�� ���
			printf("MATCH!!!! searchValue Frequency: %d, number: %d, score: %lf\n",
				targetNode->Frequency, targetNode->Data.number, targetNode->Data.score);
		}
		else
		{	// ã�� score���� ���� ��带 �� ã�� ���
			printf("ã�� ���� ���� ��尡 ����!!!!\n");
		}

		// �տ� 10��
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

	//  ��� ��带 �޸𸮿��� ����     
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
