#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main( void )
{
    char InfixExpression[100]; // 중위 표현식을 저장할 배열.
    char PostfixExpression[100]; // 후위 표현식을 저장할 배열.

	double Result = 0.0;

    // 각 배열을 0으로 초기화.
    memset( InfixExpression,   0, sizeof(InfixExpression) );
    memset( PostfixExpression, 0, sizeof(PostfixExpression) );
    
    // 중위식 입력.
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
