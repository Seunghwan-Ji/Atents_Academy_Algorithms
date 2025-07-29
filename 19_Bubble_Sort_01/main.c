#include <stdio.h>

// 버블 정렬.

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

	// 위의 DataSet 배열의 Data를 버블 소팅 로직을 만들고
	// 소팅해서 출력해보세요...

	int arraySize = sizeof(DataSet) / sizeof(DataSet[0]);
	
	printf("-- Before --\n");
	PrintArray(DataSet, arraySize);

	int freePass = 0; // 요소 스왑이 한 번이라도 일어나면 기록할 변수.

	printf("\n\n-- 정렬 과정 --\n");
	while (!freePass) // 프리패스 유지시 중단.
	{
		freePass = 1; // 일단 활성화.

		for (int i = 0; i < arraySize - 1; i++)
		{
			if (DataSet[i] > DataSet[i + 1])
			{
				// 요소 스왑.
				int temp = DataSet[i];

				DataSet[i] = DataSet[i + 1];
				DataSet[i + 1] = temp;

				// 프리패스 막음.
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