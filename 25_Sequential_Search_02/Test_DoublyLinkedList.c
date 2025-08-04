#include "DoublyLinkedList.h"
#include "Score.h"
#include "ScoreData.h"


//1. ����Ž��
//������� Ž��
//#�۵� ����
//Ž���� ��� NULL Ȯ��
//Target Match �Ǵ��� Ȯ��
//�ȵǸ� ���� -> ã������ return
//������ �� ã������ NULL���״� ������ �Ÿ���
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

// 2. �����̵���
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 ����ũ�� ����Ʈ�� �Ǿ����� �̵���Ų��(������ �����.)
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

	// ���� �κ� ����.
	if (findedNode->PrevNode != NULL)
		findedNode->PrevNode->NextNode = findedNode->NextNode;
	else
		return findedNode;
	if (findedNode->NextNode != NULL)
		findedNode->NextNode->PrevNode = findedNode->PrevNode;

	// ��忡 ����.
	findedNode->NextNode = *Head;
	findedNode->PrevNode = NULL;

	// ���� �κ� ����.
	(*Head)->PrevNode = findedNode;

	// ��� ����.
	*Head = findedNode;

	return findedNode;
}

//3. ������
//�� ĭ ������
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

	// ���� �κ� ����.
	if (findedNode->PrevNode != NULL)
		findedNode->PrevNode->NextNode = findedNode->NextNode;
	else
		return findedNode;
	if (findedNode->NextNode != NULL)
		findedNode->NextNode->PrevNode = findedNode->PrevNode;

	if (findedNode->PrevNode->PrevNode != NULL)
	{
		// ����.
		findedNode->NextNode = findedNode->PrevNode;
		findedNode->PrevNode = findedNode->PrevNode->PrevNode;

		// ���� �κ� ����.
		findedNode->PrevNode->NextNode = findedNode;
		findedNode->NextNode->PrevNode = findedNode;
	}			
	else // ã�� ��尡 ��� ��� ������ ���.
	{
		// ��忡 ����.
		findedNode->NextNode = *Head;
		findedNode->PrevNode = NULL;
			
		// ���� �κ� ����.
		(*Head)->PrevNode = findedNode;

		// ��� ����.
		*Head = findedNode;
	}

	return findedNode;
}

//4. �����
//��ȸ��(Ž��Ƚ��)�� ���� �̵�
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
			// ���� �κ� ����.
			if (findedNode->PrevNode != NULL)
				findedNode->PrevNode->NextNode = findedNode->NextNode;
			if (findedNode->NextNode != NULL)
				findedNode->NextNode->PrevNode = findedNode->PrevNode;

			// ����.
			findedNode->NextNode = currentNode;
			findedNode->PrevNode = currentNode->PrevNode;

			// ���� �κ� ����.
			if (currentNode->PrevNode != NULL)
				currentNode->PrevNode->NextNode = findedNode;
			else // ���� ��尡 ���.
				*Head = findedNode; // ��� ����.
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

	double InputValue = 0.0;	// ã�� ��(lf)�� �����ϴ� ����

	int Length = sizeof DataSet / sizeof DataSet[0];
	/*  ��� 30,000�� �߰� */
	for (i = 0; i < Length; i++)
	{
		NewNode = DLL_CreateNode(DataSet[i]);
		DLL_AppendNode(&List, NewNode);
	}

	//Current = DLL_CreateNode(8000);     // 8000���� ���� ���� �����.
	//DLL_InsertNewHead(&List, Current);  //��� ��带 �ٲ۴�.


	while (1) {
		printf("\nã�� score���� �Է��ϼ���: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("ã�� �۾��� �ߴ��ϰ� ���α׷��� �����մϴ�.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	//ã�� Score���� ���� ��带 ã�� ���
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// ã�� score���� ���� ��带 ã�� ���� (���� ���� ���)
			printf("ã�� ���� ���� ��尡 ����!!!\n");
		}

		// �տ� 10��
		for (int i = 0; i < 10; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================================================\n");

		// �ڿ� 10��
		for (int i = Length - 10; i < Length; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	/*  ��� ��带 �޸𸮿��� ����     */
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