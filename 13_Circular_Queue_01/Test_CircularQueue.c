#include "CircularQueue.h"

int main( void )
{
    int i;
    CircularQueue* Queue;

    // ť ����.
    CQ_CreateQueue(&Queue, 10);
    
    // ������ �߰�.
    CQ_Enqueue( Queue, 1 );
    CQ_Enqueue( Queue, 2 );
    CQ_Enqueue( Queue, 3 );
    CQ_Enqueue( Queue, 4 );

    // ���Լ���� ������ ��� Ȯ��.
    for ( i=0; i<3; i++)
    {
        printf( "Dequeue: %d, ",       CQ_Dequeue( Queue ) );
        printf( "Front:%d, Rear:%d\n", Queue->Front, Queue->Rear );
    }
    
    i = 100;
    // ť�� ���� �� ������ ������ �߰�.
    while ( CQ_IsFull( Queue ) == 0 )
    {
        CQ_Enqueue( Queue, i++ );
    }

    printf( "Capacity: %d, Size: %d\n\n", 
        Queue->Capacity, CQ_GetSize(Queue ) );

    // ť�� ����� ������ ������ ���� �� ���.
    while ( CQ_IsEmpty( Queue ) == 0)
    {        
        printf( "Dequeue: %d, ",       CQ_Dequeue( Queue ) );
        printf( "Front:%d, Rear:%d\n", Queue->Front, Queue->Rear );
    }

    // ť ����.
    CQ_DestroyQueue( Queue );

    return 0;
}
