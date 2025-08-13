#define _CRT_SECURE_NO_WARNINGS // 표준 C 함수 보안 경고 끔.
#define _CRT_NONSTDC_NO_DEPRECATE // 비표준 C 함수 보안 경고 끔.
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

        // 피연산자(숫자) 부분 추출.
        if (IsNumber(Expression[i]) == 1)
        {
            *TYPE = OPERAND;

            if (IsNumber(Expression[i + 1]) != 1)
                break;
        }
        // 연산자 부분 추출.
        else
        {
            *TYPE = Expression[i];
            break;
        }
    }

    Token[++i] = '\0'; // 널 종료 문자로 문자열 종료 처리.
    return i; // 총 몇 글자 읽었는지 반환.
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
    LinkedListStack* Stack; // 연산자 우선순위 판별용 스택.

    char Token[32];
    int  Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    LLS_CreateStack(&Stack);

    while (Position < Length)
    {
        // 토큰 배열 갱신, 읽어드린 토큰의 타입 갱신, 다음에 중위식 배열에서 읽어드릴 시작 포지션 갱신.
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        // 타입이 피연산자인가?
        if (Type == OPERAND)
        {
            // strcat 함수는 널 종료 문자 위치를 찾아서 그 위치에 복사함.
            
            // 후위식 배열에 현재 토큰을 먼저 이어 붙임.
            strcat(PostfixExpression, Token);

            // 공백 문자를 붙여 각각의 토큰을 구분함.
            strcat(PostfixExpression, " ");
        }
        // 타입이 닫는 괄호인가?
        else if (Type == RIGHT_PARENTHESIS)
        {
            // 스택이 비워질 때까지 반복.
            while (!LLS_IsEmpty(Stack))
            {
                // 스택에서 연산자를 꺼냄.
                Node* Popped = LLS_Pop(Stack);

                // 여는 괄호라면 중단. (괄호는 후위식 배열에서 다루지 않음)
                if (Popped->Data[0] == LEFT_PARENTHESIS)
                {
                    LLS_DestroyNode(Popped);
                    break;
                }
                else
                {
                    // 연산자는 후위식 배열로 이동.
                    strcat(PostfixExpression, Popped->Data);
                    LLS_DestroyNode(Popped);
                }
            }
        }
        // 피연산자도 아니고 닫는 괄호도 아닌가?
        else
        {
            // 스택이 비어 있지 않고, 최상단 스택에 있는 연산자의 우선순위가 현재 연산자보다
            // 낮다면 계속 반복.
            while (!LLS_IsEmpty(Stack) &&
                !IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
            {
                Node* Popped = LLS_Pop(Stack);

                // 꺼낸 스택이 여는괄호가 아니라면 후위식 배열로 이동. (괄호는 후위식에서 무시)
                if (Popped->Data[0] != LEFT_PARENTHESIS)
                    strcat(PostfixExpression, Popped->Data);

                LLS_DestroyNode(Popped);
            }

            // 현재 연산자는 스택에 푸쉬
            LLS_Push(Stack, LLS_CreateNode(Token));
        }
    }

    // 모든 토큰 처리가 끝나고, 스택에 남아있는 연산자들을 후위식 배열로 이동.
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
    LinkedListStack* Stack; // 피연산자를 저장할 스택.
    Node* ResultNode; // 최종 결과를 담을 노드.

    double Result; // 계산 결과.
    char Token[32]; // 토큰 문자열 저장용 배열.
    int  Type = -1; // 토큰 타입 식별자.
    unsigned int Read = 0; // 문자열 읽기 위치(인덱스)
    unsigned int Length = strlen(PostfixExpression); // 전체 문자열 길이.

    LLS_CreateStack(&Stack);

    // 전체 문자열을 끝까지 순회.
    while (Read < Length)
    {
        // 추출한 문자 수만큼 Read를 증가시켜 다음으로 이동.
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        // 공백은 무시하고 다음 루프로.
        if (Type == SPACE)
            continue;

        // 피연산자인 경우.
        if (Type == OPERAND)
        {
            Node* NewNode = LLS_CreateNode(Token);
            LLS_Push(Stack, NewNode); // 숫자 문자열 저장.
        }
        // 연산자인 경우.
        else
        {
            char   ResultString[32];
            double Operator1, Operator2, TempResult;
            Node* OperatorNode;

            // 스택에서 두 번째 피연산자를 꺼내고 문자열을 실수형으로 변환.
            OperatorNode = LLS_Pop(Stack);
            Operator2 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            // 스택에서 첫 번째 피연산자를 꺼내고 실수형으로 변환.
            OperatorNode = LLS_Pop(Stack);
            Operator1 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            // 연산자 타입에 맞게 선택해 계산.
            switch (Type)
            {
            case PLUS:     TempResult = Operator1 + Operator2; break;
            case MINUS:    TempResult = Operator1 - Operator2; break;
            case MULTIPLY: TempResult = Operator1 * Operator2; break;
            case DIVIDE:   TempResult = Operator1 / Operator2; break;
            }

            // 계산 결과를 문자열로 변환하고 다시 스택에 푸시.
            gcvt(TempResult, 10, ResultString);
            LLS_Push(Stack, LLS_CreateNode(ResultString));
        }
    }

    // 스택에 남은 최종 결과 노드를 꺼내어 변수에 저장.
    ResultNode = LLS_Pop(Stack);

    // 결과물 노드의 타입을 실수로 변환.
    Result = atof(ResultNode->Data);

    // 스택 메모리 해제.
    LLS_DestroyNode(ResultNode);
    LLS_DestroyStack(Stack);

    return Result;
}
