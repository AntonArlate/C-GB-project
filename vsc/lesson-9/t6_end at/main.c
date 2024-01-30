/*
������ 6. ������������� �� a
� ����� .txt ���� �����������. ���������� ����������, ������� ����
������������� �� ����� '�'. ����� �������� � ���� .txt.
������ �� �����: ������ �� ���������� ���� � �������� �� ����� 1000
��������.
������ �� ������: ���� ����� �����
������
������ �� �����: Mama mila ramu
������ �� ������: 2
*/

#include <locale.h>
// setlocale(LC_ALL, "Rus");
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWordsEndingWith(char *sentence, char endingLetter)
{
    int count = 0;
    int length = strlen(sentence);

    // ��������� ������ ����� � �����������
    for (int i = 0; i < length; i++)
    {
        // ���������� ������� � ������� ����������
        if (isspace(sentence[i]) || ispunct(sentence[i]))
        {
            continue;
        }

        // ������� ����� �������� �����
        int j = i;
        while (j < length && !isspace(sentence[j]) && !ispunct(sentence[j]))
        {
            printf("%c", sentence[j]);
            j++;
        }

        // ���������, ������������� �� ����� �� ������ �����
        if (tolower(sentence[j - 1]) == tolower(endingLetter))
        {
            count++;
            printf("%d", count);
        }
        printf("\n");

        // ���������� ������� �������� �����
        i = j;
    }

    return count;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    // ��������� ����� ��� ������ � ������
    FILE *inputFile = fopen("in.txt", "r");
    FILE *outputFile = fopen("out.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("�� ������� ������� �����\n");
        return 1;
    }

    // ������ ����������� �� �����
    char sentence[1000];
    fgets(sentence, sizeof(sentence), inputFile);

    // �������� ������� ��� �������� ����, ��������������� �� ����� 'a'
    int count = countWordsEndingWith(sentence, 'a');
    printf("result: %d", count);

    // ���������� ��������� � ����
    fprintf(outputFile, "%d", count);

    // ��������� �����
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}