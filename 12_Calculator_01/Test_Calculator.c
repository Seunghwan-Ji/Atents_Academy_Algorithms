#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main( void )
{
    char InfixExpression[100]; // ���� ǥ������ ������ �迭.
    char PostfixExpression[100]; // ���� ǥ������ ������ �迭.

	double Result = 0.0;

    // �� �迭�� 0���� �ʱ�ȭ.
    memset( InfixExpression,   0, sizeof(InfixExpression) );
    memset( PostfixExpression, 0, sizeof(PostfixExpression) );
    
    // ������ �Է�.
    printf( "Enter Infix Expression:" );
    scanf( "%s", InfixExpression );
    
    GetPostfix( InfixExpression, PostfixExpression );
    
    printf( "Infix:%s\nPostfix:%s\n",
             InfixExpression,
             PostfixExpression );

	Result = Calculate( PostfixExpression );

    printf( "Calculation Result : %f\n", Result );

    return 0;
}
