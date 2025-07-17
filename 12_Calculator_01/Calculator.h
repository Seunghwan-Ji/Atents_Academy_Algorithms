#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
} SYMBOL;

// 전달된 문자(Cipher)가 숫자인지 판별하는 함수.
int IsNumber(char Cipher);

// 수식 문자열(Expression)에서 다음 토큰(숫자, 연산자 등)을 추출해서 Token에 저장하고,
// 그 타입을 TYPE에 저장하는 함수.
// 수식을 한 글자씩 읽는 것이 아닌, 의미 단위(토큰)로 쪼갠다.
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);

// 두 연산자의 우선순위를 비교하여 Operator1이 Operator2보다 높은지 판단하는 함수.
int IsPrior(char Operator1, char Operator2);

// 중위표기법(Infix)으로 주어진 수식을 후위표기법(Postfix)으로 변환하는 함수.
void GetPostfix(char* InfixExpression, char* PostfixExpression);

// 후위표기법으로 표현된 수식을 실제로 계산하여 double 타입의 결과를 반환하는 함수.
double Calculate(char* PostfixExpression);

#endif
