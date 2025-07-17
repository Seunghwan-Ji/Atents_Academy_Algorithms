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

// ���޵� ����(Cipher)�� �������� �Ǻ��ϴ� �Լ�.
int IsNumber(char Cipher);

// ���� ���ڿ�(Expression)���� ���� ��ū(����, ������ ��)�� �����ؼ� Token�� �����ϰ�,
// �� Ÿ���� TYPE�� �����ϴ� �Լ�.
// ������ �� ���ھ� �д� ���� �ƴ�, �ǹ� ����(��ū)�� �ɰ���.
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);

// �� �������� �켱������ ���Ͽ� Operator1�� Operator2���� ������ �Ǵ��ϴ� �Լ�.
int IsPrior(char Operator1, char Operator2);

// ����ǥ���(Infix)���� �־��� ������ ����ǥ���(Postfix)���� ��ȯ�ϴ� �Լ�.
void GetPostfix(char* InfixExpression, char* PostfixExpression);

// ����ǥ������� ǥ���� ������ ������ ����Ͽ� double Ÿ���� ����� ��ȯ�ϴ� �Լ�.
double Calculate(char* PostfixExpression);

#endif
