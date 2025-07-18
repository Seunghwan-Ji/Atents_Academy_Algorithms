#include "CircularQueue.h"

int main( void )
{
    int i;
    CircularQueue* Queue;

    // 큐 생성.
    CQ_CreateQueue(&Queue, 10);
    
    // 데이터 추가.
    CQ_Enqueue( Queue, 1 );
    CQ_Enqueue( Queue, 2 );
    CQ_Enqueue( Queue, 3 );
    CQ_Enqueue( Queue, 4 );

    // 선입선출식 데이터 출력 확인.
    for ( i=0; i<3; i++)
    {
        printf( "Dequeue: %d, ",       CQ_Dequeue( Queue ) );
        printf( "Front:%d, Rear:%d\n", Queue->Front, Queue->Rear );
    }
    
    i = 100;
    // 큐가 가득 찰 때까지 데이터 추가.
    while ( CQ_IsFull( Queue ) == 0 )
    {
        CQ_Enqueue( Queue, i++ );
    }

    printf( "Capacity: %d, Size: %d\n\n", 
        Queue->Capacity, CQ_GetSize(Queue ) );

    // 큐가 비워질 때까지 데이터 삭제 및 출력.
    while ( CQ_IsEmpty( Queue ) == 0)
    {        
        printf( "Dequeue: %d, ",       CQ_Dequeue( Queue ) );
        printf( "Front:%d, Rear:%d\n", Queue->Front, Queue->Rear );
    }

    // 큐 삭제.
    CQ_DestroyQueue( Queue );

    return 0;
}
