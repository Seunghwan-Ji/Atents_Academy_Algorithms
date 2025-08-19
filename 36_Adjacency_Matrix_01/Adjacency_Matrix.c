#include <stdio.h>
#include <stdlib.h>

int** CreateMatrix(int row, int col)
{
	// �� ������ �迭.
	int** ppMatrix = (int**)malloc(sizeof(int*) * row);

	// �� �迭.
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

	// 388������ �׷����� ������� ������� ������ ��
	// graph�� ������ ���� ������ 388������ ����Ʈ ������� ����غ��ÿ�..

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