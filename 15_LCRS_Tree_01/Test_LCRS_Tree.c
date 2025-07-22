#include "LCRS_Tree.h"

int main(void)
{
    //  ��� ���� 
    LCRSNode* Root = LCRS_CreateNode('A');

    LCRSNode* B = LCRS_CreateNode('B');
    LCRSNode* C = LCRS_CreateNode('C');
    LCRSNode* D = LCRS_CreateNode('D');
    LCRSNode* E = LCRS_CreateNode('E');
    LCRSNode* F = LCRS_CreateNode('F');
    LCRSNode* G = LCRS_CreateNode('G');
    LCRSNode* H = LCRS_CreateNode('H');
    LCRSNode* I = LCRS_CreateNode('I');
    LCRSNode* J = LCRS_CreateNode('J');
    LCRSNode* K = LCRS_CreateNode('K');

    //  Ʈ���� ��� �߰� 
    LCRS_AddChildNode(Root, B);
    LCRS_AddChildNode(B, C);
    LCRS_AddChildNode(B, D);
    LCRS_AddChildNode(D, E);
    LCRS_AddChildNode(D, F);

    LCRS_AddChildNode(Root, G);
    LCRS_AddChildNode(G, H);

    LCRS_AddChildNode(Root, I);
    LCRS_AddChildNode(I, J);
    LCRS_AddChildNode(J, K);

    //  Ʈ�� ��� 
    LCRS_PrintTree(Root, 0);

    // ������ Ʈ�� ���.
    int level = 2;
    printf("\nprint tree level: %d\n", level);
    LCRS_LevelPrintTree(Root, level);
    printf("\n");
    LCRS_LevelPrintTree2(Root, 0, level);
    printf("\n");
    LCRS_LevelPrintTree3(Root, level);

    //  Ʈ�� �Ҹ��Ű�� 
    LCRS_DestroyTree(Root);

    return 0;
}