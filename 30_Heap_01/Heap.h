#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// ���� �⺻������ �迭 ����.
// �迭�� �ε��� ���踦 �ؼ��ϸ�, ���� ���� Ʈ�� ������ �� �� ����.

typedef int ElementType;

typedef struct tageHeapNode
{
    ElementType Data;
} HeapNode;

typedef struct tagHeap
{
    HeapNode* Nodes; // �� ��ü�� ��� '�迭' (���� ���� Ʈ�� ���¸� �ε����� ǥ��)
    int Capacity;    // �迭 �ִ� ũ��.
    int UsedSize;    // ���� ���� ����� ��� ���� (���� ���� �� ��ġ ��꿡�� ���)
} Heap;

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_PrintNodes(Heap* H);

#endif