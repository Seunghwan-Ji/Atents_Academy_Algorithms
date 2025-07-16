#include "LinkedListStack.h"
#include <time.h>

// ���� 1. GetSize �Լ��� �����ϼ���...

int main(void)
{
    clock_t start, end;
    float processTime;

    int i = 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;

    LLS_CreateStack(&Stack);

    start = clock(); // ���۽ð�
    for (int i = 0; i < 10000; i++) {
        LLS_Push(Stack, LLS_CreateNode("abc"));
        LLS_Push(Stack, LLS_CreateNode("def"));
        LLS_Push(Stack, LLS_CreateNode("efg"));
        LLS_Push(Stack, LLS_CreateNode("hij"));
    }

    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n",
        Count, LLS_Top(Stack)->Data);

    for (i = 0; i < Count; i++)
    {
        if (LLS_IsEmpty(Stack))
            break;

        Popped = LLS_Pop(Stack);

        //printf( "Popped: %s, ", Popped->Data );

        LLS_DestroyNode(Popped);

        /*
             if ( ! LLS_IsEmpty(Stack) )
             {
                 printf( "Current Top: %s\n", LLS_Top(Stack)->Data );
             }
             else
             {
                 printf( "Stack Is Empty.\n");
             }
           */
    }

    LLS_DestroyStack(Stack);

    end = clock();

    processTime = (float)(end - start) / CLOCKS_PER_SEC;

    printf("ó���ð�: %lf\n", processTime);

    return 0;
}
