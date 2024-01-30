// ������ 1. �� ������ ����
/*
� ������ ������� � ������� � �������� ������� ������� ��������� �������� �� ����� ��������� ����������� ������� � ����� =1
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// �������, ������� ���������, �������� �� ������ ������
int is_letter(char c)
{
    return isalpha(c) && islower(c);
}

// �������, ������� ���������, ����������� �� ����� ������ ���� ��� � �����
int is_unique_letter(char *word, char letter)
{
    int count = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (word[i] == letter)
        {
            count++;
        }
        if (count > 1)
        {
            return 0; // ����� ������� ����� ������ ����
        }
    }

    return count == 1;
}

// �������, ������� ������� �������, ������������� ������ ���� ��� � ����� ������
char *find_unique_chars(char *word1, char *word2)
{
    int length1 = strlen(word1);
    char *unique_chars = malloc(sizeof(char) * (length1 + 1)); // ������ ���������� malloc � ����������. �� ����� ���� ������ �� ��� �� ��������.
    int index = 0;

    // ���������� ������ �����, ������ ��� ������ �� �����
    for (int i = 0; i < length1; i++)
    {
        if (is_unique_letter(word1, word1[i]) && is_unique_letter(word2, word1[i]))
        {
            unique_chars[index++] = word1[i];
        }
    }

    unique_chars[index] = '\0'; // ��������� ������� ������ � ����� ������
    return unique_chars;
}

// �������, ������� ���������� ��� ������� ��� ���������� � ������������������ �������
int compare_chars(const void *a, const void *b)
{
    return *((char *)a) - *((char *)b);
    // ������ ��� ���� ��� �������� qsort():
    // ��� ����� ������������ ���������������� ������� ��� ��������� �������� ��������� �� ������� � ������� const void*.
    // � ���������� ������� ������� ����� > ��� < 0. 0 = �������� �����
}

int main()
{
    setlocale(LC_ALL, "Rus");

    FILE *in_file = fopen("in.txt", "r");
    if (in_file == NULL)
    {
        printf("������ �������� ����� in.txt\n");
        return 1;
    }

    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];

    fscanf(in_file, "%s %s", word1, word2);

    fclose(in_file);

    char *unique_chars = find_unique_chars(word1, word2);

    // ��������� ������� � ������������������ �������
    qsort(unique_chars, strlen(unique_chars), sizeof(char), compare_chars); // ������ ��� ���������� � ������� ��������?

    // �������� ������� � ����
    FILE *out_file = fopen("out.txt", "w");
    if (out_file == NULL)
    {
        printf("������ �������� ����� out.txt\n");
        return 1;
    }

    fprintf(out_file, "%s\n", unique_chars);
    fclose(out_file);

    free(unique_chars);
    return 0;
}