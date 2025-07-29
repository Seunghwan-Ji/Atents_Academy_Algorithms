#include <stdio.h>

// ���� ����.

void PrintArray(const int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	// 4 6 2 3 1 5
	// 4 2 6 3 1 5
	// 4 2 3 6 1 5
	// 4 2 3 1 6 5
	// 4 2 3 1 5 6

	// 2 4 3 1 5 6
	// 2 3 4 1 5 6
	// 2 3 1 4 5 6

	// 2 1 3 4 5 6
	// 1 2 3 4 5 6

	// ���� DataSet �迭�� Data�� ���� ���� ������ �����
	// �����ؼ� ����غ�����...

	int arraySize = sizeof(DataSet) / sizeof(DataSet[0]);
	
	printf("-- Before --\n");
	PrintArray(DataSet, arraySize);

	int freePass = 0; // ��� ������ �� ���̶� �Ͼ�� ����� ����.

	printf("\n\n-- ���� ���� --\n");
	while (!freePass) // �����н� ������ �ߴ�.
	{
		freePass = 1; // �ϴ� Ȱ��ȭ.

		for (int i = 0; i < arraySize - 1; i++)
		{
			if (DataSet[i] > DataSet[i + 1])
			{
				// ��� ����.
				int temp = DataSet[i];

				DataSet[i] = DataSet[i + 1];
				DataSet[i + 1] = temp;

				// �����н� ����.
				freePass = 0;

				PrintArray(DataSet, arraySize);
				printf("\n");
			}
		}
	}

	printf("\n-- Result --\n");
	PrintArray(DataSet, arraySize);

	return 0;
}