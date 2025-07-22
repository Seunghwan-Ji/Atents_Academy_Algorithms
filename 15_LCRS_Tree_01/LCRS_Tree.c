#include "LCRS_Tree.h"

// 문제
// level값을 입력하면 해당 level에 있는 모든 노드를 출력해주는
// 함수를 만드시고 실행해서 입력된 레벨의 노드를 출력해보세요.

void LCRS_LevelPrintTree(LCRSNode* Node, int level)
{
	if (Node->level == level)
		printf("%c - ", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_LevelPrintTree(Node->LeftChild, level);

	if (Node->RightSibling != NULL)
		LCRS_LevelPrintTree(Node->RightSibling, level);
}

// 강사님 풀이.
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
	// 부모 노드에 자식이 없으면 자식 노드 추가.
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
		Parent->LeftChild->level = Parent->level + 1;
	}
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;

		// 부모의 자식 노드부터 탐색하여 형제가 비어있는 노드 추출.
		while (TempNode->RightSibling != NULL)
		{
			TempNode = TempNode->RightSibling;
		}

		// 형제가 비어있는 노드에 노드 추가.
		TempNode->RightSibling = Child;
		TempNode->RightSibling->level = TempNode->level;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	// 들여쓰기
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
	{
		printf("   "); // 공백 3칸
	}

	if (Depth > 0) // 자식 노드 여부 표시
	{
		printf("+--");
	}

	// 노드 데이터 출력
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