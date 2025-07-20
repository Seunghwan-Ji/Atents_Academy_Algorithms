#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

// ���� ť: ���� ������ ����
typedef struct tagCircularQueue
{
    int   Capacity; // �� ���� ���� ����
    int   Front; // ������ ������ �������� �ڸ�. (���� ����ȣ)
    int   Rear; // ���� �����Ͱ� �� �ڸ��� ����Ŵ. (���������� ���Ե� ������ ���� ��ġ)

    Node* Nodes; // ��� �迭.
} CircularQueue;

void        CQ_CreateQueue( CircularQueue** Queue, int Capacity);
void        CQ_DestroyQueue( CircularQueue* Queue );
void        CQ_Enqueue( CircularQueue* Queue, ElementType Data); // ť�� �����͸� �߰��ϴ� �Լ�.
ElementType CQ_Dequeue( CircularQueue* Queue ); // ť���� �����͸� �����ϰ�, �� ���� ��ȯ�ϴ� �Լ�.
int         CQ_GetSize( CircularQueue* Queue );
int         CQ_IsEmpty( CircularQueue* Queue );
int         CQ_IsFull( CircularQueue* Queue );

#endif
