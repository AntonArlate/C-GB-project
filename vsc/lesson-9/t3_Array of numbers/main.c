/*
������ 3. ����� � ������
� ����� .txt ���� ������, �� ����� 1000 ��������, ���������� �����, �����
����� � ���� �������. ��������� ��� �����, ������� ����������� � ������,
��������� � ��������� ������������� ������. ��������, ���� ���� ������
"data 48 call 9 read13 blank0a", �� � ������� ����� 48, 9, 13 � 0. �������
������ �� ����������� � ���� .txt.
������ �� �����: ������ �� ���������� ����, ���� � ������
����������
������ �� ������: ������������������ ����� �����
��������������� �� �����������
������
������ �� �����: data 48 call 9 read13 blank0a
������ �� ������: 0 9 13 48
*/

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// �������, ������� ���������, �������� �� ������ ������
int isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    setlocale(LC_ALL, "Rus");

    FILE *inputFile, *outputFile;
    char inputFileName[] = "in.txt";
    char outputFileName[] = "out.txt";
    int numbers[MAX_LENGTH / 2];
    int numCount = 0;
    int num;

    // ��������� ����� ��� ������ � ������
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");

    // ��������� �������� �������� ������
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("������ �������� ������\n");
        return 1;
    }

    // ��������� ������ �� �����

    // �������� �� ������� ������� � ������
    char c = '0';
    do
    {
        c = fgetc(inputFile);
        printf("%c\n", c);
        // ���� ������� ������ - �����
        if (isDigit(c))
        {
            // ����������� ������������������ ���� � �����
            num = 0;
            while (isDigit(c))
            {
                num = num * 10 + (c - '0');
                c = fgetc(inputFile);
                if (c == EOF)
                    break;
            }

            // ��������� ����� � ������
            numbers[numCount] = num;
            numCount++;
        }
    } while (c != EOF);

    // ��������� ������ ����� �� �����������
    int compare(const void *a, const void *b)
    {
        int *num1 = (int *)a;
        int *num2 = (int *)b;

        return (*num1 - *num2);
    }
    qsort(numbers, numCount, sizeof(int), compare);

    // ������� ������ ����� � ����
    for (int i = 0; i < numCount; i++)
    {
        fprintf(outputFile, "%d ", numbers[i]);
    }

    // ��������� �����
    fclose(inputFile);
    fclose(outputFile);

    printf("������ ����� �������� � ����� %s\n", outputFileName);

    return 0;
}