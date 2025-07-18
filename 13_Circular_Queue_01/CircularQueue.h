#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

// 원형 큐: 선입 선출형 구조
typedef struct tagCircularQueue
{
    int   Capacity; // 총 저장 가능 개수
    int   Front; // 가장 오래된 요소의 위치 (삭제 대상의 *직전* 인덱스)
    int   Rear; // 마지막으로 삽입된 요소의 위치

    Node* Nodes; // 노드 배열.
} CircularQueue;

void        CQ_CreateQueue( CircularQueue** Queue, int Capacity);
void        CQ_DestroyQueue( CircularQueue* Queue );
void        CQ_Enqueue( CircularQueue* Queue, ElementType Data); // 큐에 데이터를 추가하는 함수.
ElementType CQ_Dequeue( CircularQueue* Queue ); // 큐에서 데이터를 제거하고, 그 값을 반환하는 함수.
int         CQ_GetSize( CircularQueue* Queue );
int         CQ_IsEmpty( CircularQueue* Queue );
int         CQ_IsFull( CircularQueue* Queue );

#endif
