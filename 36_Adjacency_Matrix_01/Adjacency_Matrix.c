#include <stdio.h>
#include <stdlib.h>

int** CreateMatrix(int row, int col)
{
	// 행 포인터 배열.
	int** ppMatrix = (int**)malloc(sizeof(int*) * row);

	// 열 배열.
	for (int i = 0; i < row; i++)
	{
		ppMatrix[i] = (int*)malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ppMatrix[i][j] = 0;
		}
	}

	return ppMatrix;
}

void RemoveMatrix(int** ppMatrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		free(ppMatrix[i]);
	}

	free(ppMatrix);
}

void AddEdge(int** ppMatrix, int v1, int v2)
{
	ppMatrix[v1 - 1][v2 - 1] = 1;
	ppMatrix[v2 - 1][v1 - 1] = 1;
}

void PrintMatrix(int** ppMatrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", ppMatrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < row; i++)
	{
		printf("%d: ", i + 1);

		for (int j = 0; j < col; j++)
		{
			if (ppMatrix[i][j] == 1)
			{
				printf("%d[%d] ", j + 1, 0);
			}
		}

		printf("\n");
	}
}

int main()
{

	// 388페이지 그래프를 인접행렬 방식으로 구현한 후
	// graph의 정점과 간선 정보를 388페이지 프린트 방식으로 출력해보시오..

	int row = 5; int col = 5;

	int** ppMatrix = CreateMatrix(row, col);

	AddEdge(ppMatrix, 1, 2);
	AddEdge(ppMatrix, 1, 3);
	AddEdge(ppMatrix, 1, 4);
	AddEdge(ppMatrix, 1, 5);

	AddEdge(ppMatrix, 2, 1);
	AddEdge(ppMatrix, 2, 3);
	AddEdge(ppMatrix, 2, 5);

	AddEdge(ppMatrix, 3, 1);
	AddEdge(ppMatrix, 3, 2);

	AddEdge(ppMatrix, 4, 1);
	AddEdge(ppMatrix, 4, 5);

	AddEdge(ppMatrix, 5, 1);
	AddEdge(ppMatrix, 5, 2);
	AddEdge(ppMatrix, 5, 4);

	PrintMatrix(ppMatrix, row, col);

	RemoveMatrix(ppMatrix, row);

	return 0;
}