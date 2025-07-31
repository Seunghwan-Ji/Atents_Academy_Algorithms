#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Score.h"
#include <time.h>

void Descending_BubbleSort(Score* dataSet, int length)
{
    Score temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (dataSet[j].score < dataSet[j + 1].score)
            {
                temp = dataSet[j];
                dataSet[j] = dataSet[j + 1];
                dataSet[j + 1] = temp;
            }
        }
    }
}

void Descending_InsertionSort(Score* dataSet, int length)
{
    Score temp;

    for (int i = 1; i < length; i++)
    {
        if (dataSet[i - 1].score >= dataSet[i].score)
            continue;

        temp = dataSet[i];

        for (int j = 0; j < i; j++)
        {
            if (dataSet[j].score < temp.score)
            {
                memmove(&dataSet[j + 1], &dataSet[j], sizeof(dataSet[0]) * (i - j));
                dataSet[j] = temp;
                break;
            }
        }
    }
}

void Swap(Score* A, Score* B)
{
    Score Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition_For_Descending(Score* DataSet, int Left, int Right)
{
    int First = Left;
    Score Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left].score >= Pivot.score && Left < Right)
            ++Left;

        while (DataSet[Right].score <= Pivot.score && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void Descending_QuickSort(Score* DataSet, int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition_For_Descending(DataSet, Left, Right);

        Descending_QuickSort(DataSet, Left, Index - 1);
        Descending_QuickSort(DataSet, Index + 1, Right);
    }
}

int ComparePoint_For_Descending(const void* _elem1, const void* _elem2)
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;

    if (elem1->score > elem2->score)
        return -1;
    else if (elem1->score < elem2->score)
        return 1;
    else
        return 0;
}

int main()
{
	// ����
	// score.h ���Ͽ� ����� 3������ ����Ÿ�� score ������ �����ؼ� �տ� 10��(1 ~ 10)
	// �ڿ� 10��(29990 ~ 29999)�� ����غ�����.
	// �����Ʈ
	// ��������
	// ����Ʈ
	// ����Ʈ2

    int Length = sizeof DataSet / sizeof DataSet[0];

    double startTime = 0.0, endTime = 0.0;
    startTime = (double)clock() / CLOCKS_PER_SEC;

    // Descending_BubbleSort(DataSet, Length);
    // Descending_InsertionSort(DataSet, Length);
    Descending_QuickSort(DataSet, 0, Length - 1);
    // qsort(DataSet, Length, sizeof(Score), ComparePoint_For_Descending);
    // ǥ�� ����Ʈ�� ���� ����Ʈ���� ����.
    // ǥ�� ����Ʈ�� �������� ����Ͽ� ������� ����.

    endTime = (double)clock() / CLOCKS_PER_SEC;

    printf("���� 10:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d�� - ��ȣ: %d, ����: %lf\n", i + 1, DataSet[i].number, DataSet[i].score);
    }

    printf("\n���� 10:\n");
    for (int i = Length - 10; i < Length; i++)
    {
        printf("%d�� - ��ȣ: %d, ����: %lf\n", i + 1, DataSet[i].number, DataSet[i].score);
    }

    printf("\n3���� ������ ���� �ð�: %lf sec\n", endTime - startTime);

    return 0;
}