#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front; // 다음에 삭제될 노드.
    Node* Rear; // 마지막 노드.
    int   Count; // 노드 개수.
} LinkedQueue;

void  LQ_CreateQueue( LinkedQueue** Queue );
void  LQ_DestroyQueue( LinkedQueue* Queue );

Node* LQ_CreateNode(char* Data);
void  LQ_DestroyNode(Node* _Node );

void  LQ_Enqueue( LinkedQueue* Queue, Node* NewNode );
Node* LQ_Dequeue( LinkedQueue* Queue );

int   LQ_IsEmpty( LinkedQueue* Queue );

#endif
