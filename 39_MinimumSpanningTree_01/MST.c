#include "MST.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
    int i = 0;

    PQNode         StartNode = { 0, StartVertex };
    PriorityQueue* PQ = PQ_Create(10);

    Vertex* CurrentVertex = NULL;
    Edge* CurrentEdge = NULL;

    // 가중치 배열.
    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);

    // MST 그래프로 새로 만드는 배열, 인덱스로 정점 접근이 용이.
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    
    // 방문 여부 배열, 각 인덱스에 해당하는 정점의 주소값이 저장됨.
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    
    // From 정점 배열.
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    // 각 배열 초기화.
    CurrentVertex = G->Vertices;
    while (CurrentVertex != NULL)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, NewVertex);

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    PQ_Enqueue(PQ, StartNode);

    Weights[StartVertex->Index] = 0; // 시작 정점은 가중치 0으로 초기화.

    while (!PQ_IsEmpty(PQ))
    {
        PQNode  Popped;

        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;

        Fringes[CurrentVertex->Index] = CurrentVertex;

        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != NULL)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            if (Fringes[TargetVertex->Index] == NULL &&
                CurrentEdge->Weight < Weights[TargetVertex->Index])
            {
                PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
                PQ_Enqueue(PQ, NewNode);

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
        }
    }

    for (i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;

        if (Precedences[i] == NULL)
            continue;

        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(MSTVertices[FromIndex],
            CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));

        AddEdge(MSTVertices[ToIndex],
            CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));
    }

    free(Fringes);
    free(Precedences);
    free(MSTVertices);
    free(Weights);

    PQ_Destroy(PQ);
}

void Kruskal(Graph* G, Graph* MST)
{
    int           i;
    Vertex* CurrentVertex = NULL;
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    DisjointSet** VertexSet =
        (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);

    PriorityQueue* PQ = PQ_Create(10);

    i = 0;
    CurrentVertex = G->Vertices;
    while (CurrentVertex != NULL)
    {
        Edge* CurrentEdge;

        VertexSet[i] = DS_MakeSet(CurrentVertex);
        MSTVertices[i] = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, MSTVertices[i]);

        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != NULL)
        {
            PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };
            PQ_Enqueue(PQ, NewNode);

            CurrentEdge = CurrentEdge->Next;
        }

        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    while (!PQ_IsEmpty(PQ))
    {
        Edge* CurrentEdge;
        int    FromIndex;
        int    ToIndex;
        PQNode Popped;

        PQ_Dequeue(PQ, &Popped);
        CurrentEdge = (Edge*)Popped.Data;

        printf("%c - %c : %d\n",
            CurrentEdge->From->Data,
            CurrentEdge->Target->Data,
            CurrentEdge->Weight);

        FromIndex = CurrentEdge->From->Index;
        ToIndex = CurrentEdge->Target->Index;

        if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
        {
            AddEdge(MSTVertices[FromIndex],
                CreateEdge(MSTVertices[FromIndex],
                    MSTVertices[ToIndex],
                    CurrentEdge->Weight));

            AddEdge(MSTVertices[ToIndex],
                CreateEdge(MSTVertices[ToIndex],
                    MSTVertices[FromIndex],
                    CurrentEdge->Weight));

            DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
        }
    }

    for (i = 0; i < G->VertexCount; i++)
        DS_DestroySet(VertexSet[i]);

    free(VertexSet);
    free(MSTVertices);
}
