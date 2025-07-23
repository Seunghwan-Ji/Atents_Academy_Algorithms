#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// ����Ʈ��

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode* Left;
    struct tagSBTNode* Right;
    ElementType        Data;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void     SBT_DestroyNode(SBTNode* Node);
void     SBT_DestroyTree(SBTNode* Root);

void     SBT_PreorderPrintTree(SBTNode* Node);  // ���� ��ȸ. (�θ� ��带 ���� ����)
void     SBT_InorderPrintTree(SBTNode* Node);   // ���� ��ȸ. (�θ� ��带 �߰��� ����)
void     SBT_PostorderPrintTree(SBTNode* Node); // ���� ��ȸ. (�θ� ��带 ���߿� ����)

#endif