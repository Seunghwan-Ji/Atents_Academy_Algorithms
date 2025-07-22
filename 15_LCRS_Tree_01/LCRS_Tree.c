#include "LCRS_Tree.h"

// ����
// level���� �Է��ϸ� �ش� level�� �ִ� ��� ��带 ������ִ�
// �Լ��� ����ð� �����ؼ� �Էµ� ������ ��带 ����غ�����.

void LCRS_LevelPrintTree(LCRSNode* Node, int level)
{
	if (Node->level == level)
		printf("%c - ", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_LevelPrintTree(Node->LeftChild, level);

	if (Node->RightSibling != NULL)
		LCRS_LevelPrintTree(Node->RightSibling, level);
}

// ����� Ǯ��.
void LCRS_LevelPrintTree2(LCRSNode* Node, int Depth, int level) {

	if (level < Depth)
	{
		return;
	}

	if (Depth == level)
	{
		printf("%c, ", Node->Data);
	}

	if (Node->LeftChild != NULL)
	{
		LCRS_LevelPrintTree2(Node->LeftChild, Depth + 1, level);
	}

	if (Node->RightSibling != NULL)
	{
		LCRS_LevelPrintTree2(Node->RightSibling, Depth, level);
	}
}

void LCRS_LevelPrintTree3(LCRSNode* Tree, int level)
{
	if (level < 0) return;

	if (level == 0)
	{
		printf("%c, ", Tree->Data);
	}

	if (Tree->LeftChild != NULL)
	{
		LCRS_LevelPrintTree3(Tree->LeftChild, level - 1);
	}

	if (Tree->RightSibling != NULL)
	{
		LCRS_LevelPrintTree3(Tree->RightSibling, level);
	}
}

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;
	NewNode->level = 0;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
	{
		LCRS_DestroyTree(Root->RightSibling);
	}

	if (Root->LeftChild != NULL)
	{
		LCRS_DestroyTree(Root->LeftChild);
	}

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	// �θ� ��忡 �ڽ��� ������ �ڽ� ��� �߰�.
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
		Parent->LeftChild->level = Parent->level + 1;
	}
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;

		// �θ��� �ڽ� ������ Ž���Ͽ� ������ ����ִ� ��� ����.
		while (TempNode->RightSibling != NULL)
		{
			TempNode = TempNode->RightSibling;
		}

		// ������ ����ִ� ��忡 ��� �߰�.
		TempNode->RightSibling = Child;
		TempNode->RightSibling->level = TempNode->level;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	// �鿩����
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
	{
		printf("   "); // ���� 3ĭ
	}

	if (Depth > 0) // �ڽ� ��� ���� ǥ��
	{
		printf("+--");
	}

	// ��� ������ ���
	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
	{
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	}

	if (Node->RightSibling != NULL)
	{
		LCRS_PrintTree(Node->RightSibling, Depth);
	}
}