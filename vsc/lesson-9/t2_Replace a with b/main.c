/*
������ 2. �������� a �� b
� ����� .txt ���� ���������� ������ �� ����� 1000 ��������. ����������
�������� ��� ����� "�" �� ����� "b" � ��������, ��� ���������, ��� �
��������. ��������� �������� � .txt.
������ �� �����: ������ �� ��������� � ������� ���������� ����,
������ ���������� � ��������.
������ �� ������: ������ �� ��������� � ������� ����������
����, ������ ���������� � ��������.
������
������ �� �����: aabbccddABCD
������ �� ������: bbaaccddBACD
*/

#include <locale.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main()
{
    setlocale(LC_ALL, "Rus");
    
    FILE *inputFile = fopen("in.txt", "r");
    FILE *outputFile = fopen("out.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("������ ��� �������� ������!\n");
        return 1;
    }

    char line[MAX_LENGTH + 1];
    if (fgets(line, (MAX_LENGTH + 1), inputFile) == NULL)
    {
        printf("������ ��� ������ ������ �� �����!\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == 'a' || line[i] == 'A')
        {
            line[i] = (line[i] == 'a') ? 'b' : 'B';
        }
        else if (line[i] == 'b' || line[i] == 'B')
        {
            line[i] = (line[i] == 'b') ? 'a' : 'A';
        }
    }

    fputs(line, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}