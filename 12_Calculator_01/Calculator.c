#define _CRT_SECURE_NO_WARNINGS // ǥ�� C �Լ� ���� ��� ��.
#define _CRT_NONSTDC_NO_DEPRECATE // ��ǥ�� C �Լ� ���� ��� ��.
#include "Calculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

int IsNumber(char Cipher)
{
    int i = 0;
    int ArrayLength = sizeof(NUMBER);

    for (i = 0; i < ArrayLength; i++)
    {
        if (Cipher == NUMBER[i])
            return 1;
    }

    return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
    unsigned int i = 0;

    for (i = 0; 0 != Expression[i]; i++)
    {
        Token[i] = Expression[i];

        // �ǿ�����(����) �κ� ����.
        if (IsNumber(Expression[i]) == 1)
        {
            *TYPE = OPERAND;

            if (IsNumber(Expression[i + 1]) != 1)
                break;
        }
        // ������ �κ� ����.
        else
        {
            *TYPE = Expression[i];
            break;
        }
    }

    Token[++i] = '\0'; // �� ���� ���ڷ� ���ڿ� ���� ó��.
    return i; // �� �� ���� �о����� ��ȯ.
}

int GetPriority(char Operator, int InStack)
{
    int Priority = -1;

    switch (Operator)
    {
    case LEFT_PARENTHESIS:
        if (InStack)
            Priority = 3;
        else
            Priority = 0;
        break;

    case MULTIPLY:
    case DIVIDE:
        Priority = 1;
        break;

    case PLUS:
    case MINUS:
        Priority = 2;
        break;
    }

    return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
    return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
    LinkedListStack* Stack; // ������ �켱���� �Ǻ��� ����.

    char Token[32];
    int  Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    LLS_CreateStack(&Stack);

    while (Position < Length)
    {
        // ��ū �迭 ����, �о�帰 ��ū�� Ÿ�� ����, ������ ������ �迭���� �о�帱 ���� ������ ����.
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        // Ÿ���� �ǿ������ΰ�?
        if (Type == OPERAND)
        {
            // strcat �Լ��� �� ���� ���� ��ġ�� ã�Ƽ� �� ��ġ�� ������.
            
            // ������ �迭�� ���� ��ū�� ���� �̾� ����.
            strcat(PostfixExpression, Token);

            // ���� ���ڸ� �ٿ� ������ ��ū�� ������.
            strcat(PostfixExpression, " ");
        }
        // Ÿ���� �ݴ� ��ȣ�ΰ�?
        else if (Type == RIGHT_PARENTHESIS)
        {
            // ������ ����� ������ �ݺ�.
            while (!LLS_IsEmpty(Stack))
            {
                // ���ÿ��� �����ڸ� ����.
                Node* Popped = LLS_Pop(Stack);

                // ���� ��ȣ��� �ߴ�. (��ȣ�� ������ �迭���� �ٷ��� ����)
                if (Popped->Data[0] == LEFT_PARENTHESIS)
                {
                    LLS_DestroyNode(Popped);
                    break;
                }
                else
                {
                    // �����ڴ� ������ �迭�� �̵�.
                    strcat(PostfixExpression, Popped->Data);
                    LLS_DestroyNode(Popped);
                }
            }
        }
        // �ǿ����ڵ� �ƴϰ� �ݴ� ��ȣ�� �ƴѰ�?
        else
        {
            // ������ ��� ���� �ʰ�, �ֻ�� ���ÿ� �ִ� �������� �켱������ ���� �����ں���
            // ���ٸ� ��� �ݺ�.
            while (!LLS_IsEmpty(Stack) &&
                !IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
            {
                Node* Popped = LLS_Pop(Stack);

                // ���� ������ ���°�ȣ�� �ƴ϶�� ������ �迭�� �̵�. (��ȣ�� �����Ŀ��� ����)
                if (Popped->Data[0] != LEFT_PARENTHESIS)
                    strcat(PostfixExpression, Popped->Data);

                LLS_DestroyNode(Popped);
            }

            // ���� �����ڴ� ���ÿ� Ǫ��
            LLS_Push(Stack, LLS_CreateNode(Token));
        }
    }

    // ��� ��ū ó���� ������, ���ÿ� �����ִ� �����ڵ��� ������ �迭�� �̵�.
    while (!LLS_IsEmpty(Stack))
    {
        Node* Popped = LLS_Pop(Stack);

        if (Popped->Data[0] != LEFT_PARENTHESIS)
            strcat(PostfixExpression, Popped->Data);

        LLS_DestroyNode(Popped);
    }

    LLS_DestroyStack(Stack);
}

double Calculate(char* PostfixExpression)
{
    LinkedListStack* Stack; // �ǿ����ڸ� ������ ����.
    Node* ResultNode; // ���� ����� ���� ���.

    double Result; // ��� ���.
    char Token[32]; // ��ū ���ڿ� ����� �迭.
    int  Type = -1; // ��ū Ÿ�� �ĺ���.
    unsigned int Read = 0; // ���ڿ� �б� ��ġ(�ε���)
    unsigned int Length = strlen(PostfixExpression); // ��ü ���ڿ� ����.

    LLS_CreateStack(&Stack);

    // ��ü ���ڿ��� ������ ��ȸ.
    while (Read < Length)
    {
        // ������ ���� ����ŭ Read�� �������� �������� �̵�.
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        // ������ �����ϰ� ���� ������.
        if (Type == SPACE)
            continue;

        // �ǿ������� ���.
        if (Type == OPERAND)
        {
            Node* NewNode = LLS_CreateNode(Token);
            LLS_Push(Stack, NewNode); // ���� ���ڿ� ����.
        }
        // �������� ���.
        else
        {
            char   ResultString[32];
            double Operator1, Operator2, TempResult;
            Node* OperatorNode;

            // ���ÿ��� �� ��° �ǿ����ڸ� ������ ���ڿ��� �Ǽ������� ��ȯ.
            OperatorNode = LLS_Pop(Stack);
            Operator2 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            // ���ÿ��� ù ��° �ǿ����ڸ� ������ �Ǽ������� ��ȯ.
            OperatorNode = LLS_Pop(Stack);
            Operator1 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            // ������ Ÿ�Կ� �°� ������ ���.
            switch (Type)
            {
            case PLUS:     TempResult = Operator1 + Operator2; break;
            case MINUS:    TempResult = Operator1 - Operator2; break;
            case MULTIPLY: TempResult = Operator1 * Operator2; break;
            case DIVIDE:   TempResult = Operator1 / Operator2; break;
            }

            // ��� ����� ���ڿ��� ��ȯ�ϰ� �ٽ� ���ÿ� Ǫ��.
            gcvt(TempResult, 10, ResultString);
            LLS_Push(Stack, LLS_CreateNode(ResultString));
        }
    }

    // ���ÿ� ���� ���� ��� ��带 ������ ������ ����.
    ResultNode = LLS_Pop(Stack);

    // ����� ����� Ÿ���� �Ǽ��� ��ȯ.
    Result = atof(ResultNode->Data);

    // ���� �޸� ����.
    LLS_DestroyNode(ResultNode);
    LLS_DestroyStack(Stack);

    return Result;
}
