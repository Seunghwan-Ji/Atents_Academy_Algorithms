#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include "string.h"

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc( sizeof( Graph ) );
    graph->Vertices = NULL;
    graph->VertexCount = 0;

    return graph;
}

void DestroyGraph( Graph* G )
{
    while ( G->Vertices != NULL )
    {
        Vertex* Vertices = G->Vertices->Next;        
        DestroyVertex( G->Vertices );
        G->Vertices = Vertices;        
    }

    free( G );
}

Vertex* CreateVertex( VElementType Data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );
    
    // 원본 Data 훼손 방지, 동적 할당 후 Data 복사.
    char* temp = (char*)malloc(strlen(Data) + 1); // char 는 1바이트 이므로 문자열 길이만큼 바이트 할당.
    strcpy(temp, Data);

    V->Data = temp;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex( Vertex* V )
{
    while ( V->AdjacencyList != NULL )
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge ( V->AdjacencyList );

        V->AdjacencyList = Edge;
    }

    free(V->Data); // 문자열 복사를 위해 동적 할당한 메모리 해제.
    free( V );
}

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight )
{
    Edge* E   = (Edge*)malloc( sizeof( Edge ) );
    E->From   = From;
    E->Target = Target;
    E->Next   = NULL;
    E->Weight = Weight;

    return E;
}

void    DestroyEdge( Edge* E )
{
    free( E );
}

void AddVertex( Graph* G, Vertex* V )
{
    Vertex* VertexList = G->Vertices;

    if ( VertexList == NULL ) 
    {
        G->Vertices = V;
    } 
    else 
    {
        while ( VertexList->Next != NULL )
            VertexList = VertexList->Next;

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL ) 
    {
        V->AdjacencyList = E;
    } 
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while ( AdjacencyList->Next != NULL )
            AdjacencyList = AdjacencyList->Next;

        AdjacencyList->Next = E;
    }
}

void PrintGraph ( Graph* G )
{
    Vertex* V = NULL;
    Edge*   E = NULL;

    if ( ( V = G->Vertices ) == NULL )
        return;

    while ( V != NULL )
    {
        printf( "%s : ", V->Data );        
        
        if ( (E = V->AdjacencyList) == NULL ) {
            V = V->Next;
            printf("\n");
            continue;
        }

        while ( E != NULL )
        {
            printf("%s[%d] ", E->Target->Data, E->Weight );
            E = E->Next;
        }

        printf("\n");

        V = V->Next;    
    }   

    printf("\n");
}
