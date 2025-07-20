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
    int   Front; // 다음에 삭제될 데이터의 자리. (선출 대기번호)
    int   Rear; // 다음 데이터가 들어갈 자리를 가리킴. (마지막으로 삽입된 데이터 다음 위치)

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
