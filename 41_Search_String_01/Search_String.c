#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char* fileName;      // 문장이 기록되어있는 파일의 파일명, (path 포함)

    fileName = argv[1];

    char* pattern = argv[2];

    char Text[512];   // 파일에서 읽은 문장을 저장할 배열

    FILE* fp;

    fp = fopen(fileName, "r");   // 파일을 읽기모드로 오픈

    if (fp == NULL) {
        printf("파일읽기에 실패하였습니다.\n");
        return 0;
    }

    if (argc < 3) {
        printf("Usage: 실행파일명 문장파일명 패턴문자열");
        return 0;
    }

    int patternLength = strlen(pattern);   // 패턴 문자열의 길이
    int line = 1;

    while (fgets(Text, 512, fp) != NULL) {
        // 읽어들인 문장안에 찾는 패턴 문자열이 있는지 확인하고
        // 있으면 해당 라인번호와 컬럼번호를 출력하면됩니다.

        int Text_length = strlen(Text);   // 읽은 문자열의 길이를 구한다.

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