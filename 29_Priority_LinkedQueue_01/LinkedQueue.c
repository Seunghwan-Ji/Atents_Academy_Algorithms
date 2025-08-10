#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    //  큐를 자유 저장소에 생성 
    (*Queue )        = ( LinkedQueue*)malloc(sizeof( LinkedQueue ) );
    (*Queue )->Front = NULL;
    (*Queue )->Rear  = NULL;
    (*Queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( !LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode(Popped);
    }

    //  큐를 자유 저장소에서 할당 해제 
    free( Queue );
}

Node* LQ_CreateNode( int priority, char* NewData )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    NewNode->Data = (char*)malloc( strlen( NewData) + 1);

    strcpy(NewNode->Data, NewData);  //  데이터를 저장한다. 

	NewNode->priority = priority;
    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다. 

    return NewNode;//  노드의 주소를 반환한다. 
}

void  LQ_DestroyNode(Node* _Node )
{
    free(_Node->Data);
    free(_Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
    // 큐가 비어있는 경우.
    if (Queue->Front == NULL)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else
    {
        Node* currentNode = Queue->Front;
        Node* prevNode = NULL;

        while (currentNode != NULL)
        {
            // 우선 순위 비교.
            if (NewNode->priority < currentNode->priority)
            {
                // front 에 삽입.
                if (currentNode == Queue->Front)
                {
                    NewNode->NextNode = currentNode;
                    Queue->Front = NewNode;
                    break;
                }
                // front 와 real 사이에 삽입.
                else
                {
                    prevNode->NextNode = NewNode;
                    NewNode->NextNode = currentNode;
                    break;
                }
            }

            prevNode = currentNode;
            currentNode = currentNode->NextNode;
        }

        // real 에 삽입.
        if (currentNode == NULL)
        {
            Queue->Rear->NextNode = NewNode;
            Queue->Rear = NewNode;
        }
    }

    Queue->Count++; // 노드 수 갱신.
}

Node* LQ_Dequeue( LinkedQueue* Queue )
{
    // 반환할 Front 노드(최상위 노드)
    Node* Front = Queue->Front;

    // 큐에 노드가 1개인 경우.
    if (Queue->Front->NextNode == NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
    {
        // front 노드 갱신.
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--; // 노드 수 갱신.

    return Front;
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL);
}
