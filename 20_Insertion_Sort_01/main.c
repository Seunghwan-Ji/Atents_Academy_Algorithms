#include <stdio.h>

// ���� ����.

void PrintArray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	int DataSet[] = { 5, 1, 6, 4, 2, 3 };
	// 1 5 6 4 2 3
	// 1 4 5 6 2 3
	// 1 2 4 5 6 3
	// 1 2 3 4 5 6

	int arraySize = sizeof(DataSet) / sizeof(DataSet[0]);

	printf("-- Before --\n");
	PrintArray(DataSet, arraySize);

	printf("\n\n-- ���� ���� --\n");
	for (int i = 1; i < arraySize; i++)
	{
		if (DataSet[i] < DataSet[i - 1])
		{
			// ���� �ε������� �������� ��ȸ.
			for (int j = i; j > 0; j--)
			{
				if (DataSet[j] < DataSet[j - 1])
				{
					// ��� ����.
					int temp = DataSet[j];

					DataSet[j] = DataSet[j - 1];
					DataSet[j - 1] = temp;
				}
			}

			PrintArray(DataSet, arraySize);
			printf("\n");
		}
	}

	printf("\n-- Result --\n");
	PrintArray(DataSet, arraySize);
}