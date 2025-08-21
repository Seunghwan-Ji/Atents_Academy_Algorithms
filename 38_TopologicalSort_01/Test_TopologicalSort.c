#include "Graph.h"
#include "TopologicalSort.h"

int main( void )
{
    Node* SortedList  = NULL; // �Ϸķ� ���ﶧ ������� �ּ�.
    Node* CurrentNode = NULL;

    //  �׷��� ����     
    Graph* graph = CreateGraph();
    
    //  ���� ����    
    Vertex* V1 = CreateVertex("C���");
    Vertex* V2 = CreateVertex("C++");
    Vertex* V3 = CreateVertex("�ڷᱸ��");
    Vertex* V4 = CreateVertex("�˰���");
    Vertex* V5 = CreateVertex("�𸮾�1");
    Vertex* V6 = CreateVertex("�𸮾�2");
    Vertex* V7 = CreateVertex("�𸮾�3");
    Vertex* V8 = CreateVertex("��������1");
    Vertex* V9 = CreateVertex("��������2");
    Vertex* V10 = CreateVertex("����Ƽ1");
    Vertex* V11 = CreateVertex("����Ƽ2");
    Vertex* V12 = CreateVertex("����Ƽ3");
    Vertex* V13 = CreateVertex("����Ƽ4");
    Vertex* V14 = CreateVertex("����Ƽ5");
    
    //  �׷����� ������ �߰�
    AddVertex(graph, V1);
    AddVertex(graph, V2);
    AddVertex(graph, V3);
    AddVertex(graph, V4);
    AddVertex(graph, V5);
    AddVertex(graph, V6);
    AddVertex(graph, V7);
    AddVertex(graph, V8);
    AddVertex(graph, V9);
    AddVertex(graph, V10);
    AddVertex(graph, V11);
    AddVertex(graph, V12);
    AddVertex(graph, V13);
    AddVertex(graph, V14);

    //  ������ ������ �������� �ձ� 
    AddEdge(V1, CreateEdge(V1, V2, 0));
    AddEdge(V2, CreateEdge(V2, V3, 0));
    AddEdge(V3, CreateEdge(V3, V4, 0));
    AddEdge(V4, CreateEdge(V4, V5, 0));
    AddEdge(V5, CreateEdge(V5, V6, 0));
    AddEdge(V6, CreateEdge(V6, V7, 0));
    AddEdge(V7, CreateEdge(V7, V8, 0));
    AddEdge(V8, CreateEdge(V8, V9, 0));
    AddEdge(V9, CreateEdge(V9, V10, 0));
    AddEdge(V10, CreateEdge(V10, V11, 0));
    AddEdge(V11, CreateEdge(V11, V12, 0));
    AddEdge(V12, CreateEdge(V12, V13, 0));
    AddEdge(V13, CreateEdge(V13, V14, 0));

    //  ���� ���� 
    TopologicalSort( graph->Vertices, &SortedList );

 
    printf("Topological Sort Result : ");

    CurrentNode = SortedList;

    while ( CurrentNode != NULL )
    {
        printf("%s ", CurrentNode->Data->Data );
        CurrentNode = CurrentNode->NextNode;
    }
    printf("\n");
    

    //  �׷��� �Ҹ� 
    DestroyGraph( graph );

    return 0;
}
