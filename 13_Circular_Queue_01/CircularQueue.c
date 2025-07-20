#include "CircularQueue.h"

void  CQ_CreateQueue( CircularQueue** Queue, int Capacity)
{
    //  큐를 자유 저장소에 생성 
    (*Queue )           = ( CircularQueue*)malloc(sizeof( CircularQueue ));

    // 큐가 비워진 상태와 가득 찬 상태를 구별하기 위해 배열 한 칸을 더 늘린다.
    // 이렇게 하지 않으면 real == front 이 큐가 비워진건지 가득찬건지 구별하기 어렵기 때문이다.
    (*Queue )->Nodes    = (Node*)malloc(sizeof(Node )* ( Capacity+1) );

    (*Queue )->Capacity = Capacity;
    (*Queue )->Front = 0;
    (*Queue )->Rear  = 0;
}

void CQ_DestroyQueue( CircularQueue* Queue )
{
    free(Queue->Nodes);
    free(Queue );
}

void CQ_Enqueue( CircularQueue* Queue, ElementType Data)
{
    int Position=0;
    
    // Real이 큐의 끝에 도달했다면.
    if(Queue->Rear==Queue->Capacity)
    {
        Position=Queue->Rear;
        Queue->Rear=0; // real을 맨 앞으로 이동.
    }
    else
        // 포지션 갱신 후, real을 증가시킴.
        Position=Queue->Rear++;
    
    // 데이터 추가.
    Queue->Nodes[Position].Data=Data;
}

ElementType CQ_Dequeue( CircularQueue* Queue )
{
    int Position = Queue->Front;

    // Front가 큐의 끝에 도달했다면.
    if ( Queue->Front == Queue->Capacity )
        // Front를 맨 앞으로 이동.
        Queue->Front = 0;
    else
        // Front 증가.
        Queue->Front++;

    return Queue->Nodes[Position].Data;
}

int CQ_GetSize( CircularQueue* Queue )
{
    // 데이터 개수 측정 방법은 두 가지 경우로 나뉜다.

    // real 위치가 front 위치보다 이상인 경우.
    if ( Queue->Front <= Queue->Rear )
        return Queue->Rear - Queue->Front;
    // real 위치가 front 위치보다 이전인 경우.
    else
        // 1. 배열의 처음부터 real 까지 데이터 수 = real
        // +
        // 2. front 부터 배열의 끝까지 데이터 수. = Capacity - front + 1(front 자기 자신)
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty( CircularQueue* Queue )
{
    // 큐에서 front 위치와 real 위치가 같은지 확인한다.
    return (Queue->Front == Queue->Rear);
}

int CQ_IsFull( CircularQueue* Queue )
{
    // 큐가 가득 찬 상태는 두 가지 경우로 나뉜다.
    if ( Queue->Front < Queue->Rear )
        // real 의 위치가 배열의 끝이고, front 의 위치가 배열의 시작인지 확인한다.
        return ( Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        // real 의 위치가 front 의 위치보다 한 칸 이전인지 확인한다.
        return ( Queue->Rear + 1 ) == Queue->Front;
}
