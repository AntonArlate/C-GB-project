/*
������ 2. ������� ������� �� ������
� ����� .txt ���������� ������� ��� ������ ������� (� ������ �����������
� ��������� �������). ��� ������� ������ ����������� �������. ���������
�������� � .txt.
������ �� �����: ������ �� ���������� ����, ������ ���������� �
��������. �� ����� 1000 ��������.
������ �� ������: ������ �� ���������� ����, ������ ���������� �
��������.
������
������ �� �����: " Hello  world!"
������ �� ������: "Hello world!"
*/

#include "../func.h"

void removeExtraSpaces(const char* inputFilePath, const char* outputFilePath) {
    FILE* inputFile = fopen(inputFilePath, "r");
    FILE* outputFile = fopen(outputFilePath, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �������� ������!\n");
        return;
    }
    
    // ������ ���� � ����� ��� ��� � ���������� �������� ��������� �� ��������� ������
    char inputBuffer[1000];
    fgets(inputBuffer, sizeof(inputBuffer), inputFile);
    
    char outputBuffer[1000] = {0};
    char previousChar = ' ';
    int outputIndex = 0;
    
    for (int i = 0; inputBuffer[i] != '\0'; i++) {
        char currentChar = inputBuffer[i];
        
        if (currentChar != ' ') {
            outputBuffer[outputIndex] = currentChar;
            outputIndex++;
        } else {
            if (previousChar != ' ') {
                outputBuffer[outputIndex] = currentChar;
                outputIndex++;
            }
        }
        
        previousChar = currentChar;
    }
    
    fprintf(outputFile, "%s", outputBuffer);
    
    fclose(inputFile);
    fclose(outputFile);
}

void task2()
{
    removeExtraSpaces("task_2/in.txt", "task_2/out.txt");
    printf("������ ��������� �������!\n");
}