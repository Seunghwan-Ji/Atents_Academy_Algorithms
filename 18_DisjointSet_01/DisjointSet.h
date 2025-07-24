#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// 분리 집합(서로소 집합) 자료구조.

typedef struct tagDisjointSet
{
    struct tagDisjointSet* Parent; // 자신의 부모 집합.
    void*                  Data;
} DisjointSet;

// 두 집합을 합집합으로 만드는 함수.
void DS_UnionSet( DisjointSet* Set1, DisjointSet* Set2 );

// 매개변수로 들어온 집합의 최상위 부모 집합을 탐색하는 함수.
DisjointSet* DS_FindSet( DisjointSet* Set );

// 집합 생성 함수.
DisjointSet* DS_MakeSet( void* NewData );

// 집합 삭제 함수.
void DS_DestroySet( DisjointSet* Set );

#endif
