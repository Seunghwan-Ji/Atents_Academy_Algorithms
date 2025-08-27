#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char* fileName;      // ������ ��ϵǾ��ִ� ������ ���ϸ�, (path ����)

    fileName = argv[1];

    char* pattern = argv[2];

    char Text[512];   // ���Ͽ��� ���� ������ ������ �迭

    FILE* fp;

    fp = fopen(fileName, "r");   // ������ �б���� ����

    if (fp == NULL) {
        printf("�����б⿡ �����Ͽ����ϴ�.\n");
        return 0;
    }

    if (argc < 3) {
        printf("Usage: �������ϸ� �������ϸ� ���Ϲ��ڿ�");
        return 0;
    }

    int patternLength = strlen(pattern);   // ���� ���ڿ��� ����
    int line = 1;

    while (fgets(Text, 512, fp) != NULL) {
        // �о���� ����ȿ� ã�� ���� ���ڿ��� �ִ��� Ȯ���ϰ�
        // ������ �ش� ���ι�ȣ�� �÷���ȣ�� ����ϸ�˴ϴ�.

        int Text_length = strlen(Text);   // ���� ���ڿ��� ���̸� ���Ѵ�.

        // printf("line: %d : %s\n", line, Text);

        int col = 1;
        int pattern_index = 0;

        for (int i = 0; i < Text_length; i++)
        {
            if (Text[i] != ' ')
            {
                Text[i] == pattern[pattern_index] ? pattern_index++ : (pattern_index = 0);

                if (pattern_index == patternLength)
                {
                    printf("Line: %d, Col: %d\n", line, col);
                }
            }
            else
            {
                col++;
            }
        }

        line++;
    }

    fclose(fp);

    return 0;
}