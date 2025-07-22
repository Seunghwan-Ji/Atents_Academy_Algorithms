#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 이진트리

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

void     SBT_PreorderPrintTree(SBTNode* Node);  // 전위 순회.
void     SBT_InorderPrintTree(SBTNode* Node);   // 중위 순회.
void     SBT_PostorderPrintTree(SBTNode* Node); // 후위 순회.

#endif