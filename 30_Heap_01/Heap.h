#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// 힙은 기본적으로 배열 형태.
// 배열의 인덱스 관계를 해석하면, 완전 이진 트리 구조로 볼 수 있음.

typedef int ElementType;

typedef struct tageHeapNode
{
    ElementType Data;
} HeapNode;

typedef struct tagHeap
{
    HeapNode* Nodes; // 힙 전체를 담는 '배열' (완전 이진 트리 형태를 인덱스로 표현)
    int Capacity;    // 배열 최대 크기.
    int UsedSize;    // 현재 힙에 저장된 노드 개수 (다음 삽입 시 위치 계산에도 사용)
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