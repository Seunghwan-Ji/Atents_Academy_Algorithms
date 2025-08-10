#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

int main( void )
{
    Node* Popped;
    LinkedQueue* Queue;

    LQ_CreateQueue(&Queue );

	char data[100];	// 문자열 입력 공간
	int priority = 0;	// 우선 순위 입력용

	while (1) {
		printf("우선순위 큐에 저장할 데이타를 입력하세요: ");
		scanf("%d %s", &priority, data);

		if (priority <= -1) break;	// 입력 중단.

		// 입력받은 데이타를 큐에 저장한다.
		LQ_Enqueue(Queue, LQ_CreateNode(priority, data));


		// 큐에 입력된 데이타를 출력
		Node* Current = Queue->Front;		// 헤드노드의 주소값을 Current에 저장

		while (Current != NULL) {
			printf("[priority: %d, Data: %s\n", Current->priority, Current->Data);

			Current = Current->NextNode;
		}
	}	
    

    while ( LQ_IsEmpty( Queue ) == 0 )
    {
        Popped = LQ_Dequeue( Queue );

        printf( "Dequeue: %s \n", Popped->Data );

        LQ_DestroyNode( Popped );
    }

    LQ_DestroyQueue( Queue );

    return 0;
}
