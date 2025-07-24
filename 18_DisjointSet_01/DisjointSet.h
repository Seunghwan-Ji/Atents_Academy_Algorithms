#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// �и� ����(���μ� ����) �ڷᱸ��.

typedef struct tagDisjointSet
{
    struct tagDisjointSet* Parent; // �ڽ��� �θ� ����.
    void*                  Data;
} DisjointSet;

// �� ������ ���������� ����� �Լ�.
void DS_UnionSet( DisjointSet* Set1, DisjointSet* Set2 );

// �Ű������� ���� ������ �ֻ��� �θ� ������ Ž���ϴ� �Լ�.
DisjointSet* DS_FindSet( DisjointSet* Set );

// ���� ���� �Լ�.
DisjointSet* DS_MakeSet( void* NewData );

// ���� ���� �Լ�.
void DS_DestroySet( DisjointSet* Set );

#endif
