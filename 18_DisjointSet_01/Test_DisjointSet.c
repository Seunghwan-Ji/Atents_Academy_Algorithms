#include <stdio.h>
#include "DisjointSet.h"

int main( void )
{
	// 데이터 생성.
	int a=1, b=2, c=3, d=4;

	// 집합 생성후 데이터 넣기.
	DisjointSet* Set1 = DS_MakeSet(&a);
	DisjointSet* Set2 = DS_MakeSet(&b);
	DisjointSet* Set3 = DS_MakeSet(&c);
	DisjointSet* Set4 = DS_MakeSet(&d);

	// Set1 집합과 Set2 집합의 최상위 부모 집합이 같은지 확인. (교집합 관계인가?)
    printf("Set1 == Set2 : %d \n", DS_FindSet( Set1 ) == DS_FindSet( Set2 ) );

	// Set1 집합과 Set3 집합을 합집합으로.
	DS_UnionSet( Set1, Set3 );
    printf("Set1 == Set3 : %d \n", DS_FindSet( Set1 ) == DS_FindSet( Set3 ) );

    DS_UnionSet( Set3, Set4 );
    printf("Set3 == Set4 : %d \n", DS_FindSet( Set3 ) == DS_FindSet( Set4 ) );

	return 0;
}
