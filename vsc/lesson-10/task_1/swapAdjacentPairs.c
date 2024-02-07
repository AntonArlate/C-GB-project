/*
������ 1. ���� �������� ��������
� ����� .txt �������� �������. ���������� ����������� �������, �������
������ ������� ���� �������� �������� �� ������� �������� �� �������
������. ���� ���������� �������� ������� (������� �� �������), ��
��������� ������ �� ������. ��������� �������� � ���� .txt.
������ �� �����: ������ �� ���������� ����, �������� � ������
����������. �� ����� 1000 ��������.
������ �� ������: ������ �� ���������� ����, �������� � ������
����������.
������ �1
������ �� �����: Hello world!
������ �� ������: eHllw orodl!
������ �2
������ �� �����: abc def
������ �� ������: bad cfe
*/

#include "../func.h"

void swapAdjacentPairs(FILE *inputFile, FILE *outputFile) {
    char c;
    int isOdd = 1; // ����
    int spaceCount = 0; // ������� ��� ��������

    char temp = ' '; // ��������� ���������� ��� �������� ��������
    
    while ((c = fgetc(inputFile)) != EOF) {
        
        // ���� ���� ������
        if (isOdd) {
            //��������� ������
            if (c == ' ') {
                // � ������ �������� ����� ������ � ��������� �� ��������� ��������
                fputc(c, outputFile);
            } else {
                // ���� �� ������ ����� � temp � ������ ���������
                temp = c; 
                isOdd = !isOdd; // ����������� ����
            } 
        } else // ���� ���� ������
        {
            //��������� ������
            if (c == ' ') {
                // ����������� ������� �������� � ������ � ��������� �� ��������� ��������
                spaceCount++;
            } else
            {
                // ����� ������� ������
                fputc(c, outputFile);
                // ��������� �������
                for (; spaceCount > 0; spaceCount--) {
                    fputc(' ', outputFile);
                }
                // ��������� temp ������
                fputc(temp, outputFile);
                isOdd = !isOdd; // ����������� ����
            }
        }
    }

    // ����� ����� ����� ��������� ��������� �����
    // ���� ���� =0 ������ � temp ����� ������ ��� ����. ����� ���.
    if (!isOdd) 
        fputc(temp, outputFile);
}

void task1()
{
    FILE *inputFile, *outputFile;
    inputFile = fopen("task_1/in.txt", "r");
    outputFile = fopen("task_1/out.txt", "w");
    
    if (inputFile && outputFile) {
        swapAdjacentPairs(inputFile, outputFile);
        fclose(inputFile);
        fclose(outputFile);
        printf("������ ��������� �������!\n");
    }
    else {
        printf("������ �������� ������.\n");
    }
}