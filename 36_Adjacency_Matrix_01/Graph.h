#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int VElementType;

typedef struct tagVertex
{
    VElementType      Data; // 정점의 데이터.
    int               Visited; // 이 정점의 방문 여부.
    int               Index; // 정점의 인덱스.
    struct tagVertex* Next; // 다음 정점.
    struct tagEdge*   AdjacencyList; // 이 정점의 간선 리스트
} Vertex;

typedef struct tagEdge
{
    int             Weight; // 가중치 (여기선 쓰이지 않음.)
    struct tagEdge* Next; // 다음 간선.
    Vertex*         From; // 어느 정점부터.
    Vertex*         Target; // 어느 정점까지.
} Edge;

typedef struct tagGraph
{
    Vertex* Vertices; // 이 그래프의 정점 리스트.
    int     VertexCount; // 이 그래프의 모든 정점 개수.
} Graph;

Graph* CreateGraph();
void   DestroyGraph(Graph* G);

Vertex* CreateVertex(VElementType Data);
void    DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void    DestroyEdge(Edge* E);

void   AddVertex(Graph* G, Vertex* V);
void   AddEdge(Vertex* V, Edge* E);
void   PrintGraph(Graph* G);

#endif