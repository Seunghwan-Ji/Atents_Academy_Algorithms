#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// 우선순위 큐.
// 데이터를 넣을 때 우선순위를 부여해서, 꺼낼 때 항상 우선순위가 가장 높은 데이터부터 나온다.

typedef int PriorityType;

typedef struct tagePQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create(int InitialSize);
void           PQ_Destroy(PriorityQueue* PQ);
void           PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);
void           PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
int            PQ_GetParent(int Index);
int            PQ_GetLeftChild(int Index);
void           PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);
int            PQ_IsEmpty(PriorityQueue* PQ);

#endif