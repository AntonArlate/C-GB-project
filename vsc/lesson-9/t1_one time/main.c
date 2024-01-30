/*
������ 1. �� ������ ����
� ����� .txt ���� ��� ����� �� ����� 100 �������� ������, �����������
����� ��������. ������� ������ �� ������� ����, ������� ����������� �
����� ������ ������ ���� ���. ����������� �� ����� ������ � ���� .txt �
������������������ �������.
������ �� �����: ��� ����� �� ��������� ���������� ���� �����
������. ������ ������� ����� �� ������ 100 ��������.
������ �� ������: ��������� ���������� ����� ����� ������.
������ �1
������ �� �����: hello world
������ �� ������: o
������ �� �����: aabcd bcef
������ �� ������: b c
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

// �������, ������� ������� �������, ������������� ������ ���� ��� � ����� ������
char *find_unique_chars(char *word1, char *word2)
{
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    char *unique_chars = malloc(sizeof(char) * 27); // ������ ���������� malloc � ����������. �� ����� ���� ������ �� ��� �� ��������.
    int index = 0;

    // ������� ������� ��� �������� ���������� ��������� ������ ����� � ������
    // ����� � ����� ��������� ����� ����������� ������ ������������ ������ ��� �������� ����������.
    // ������ ������� ����� ������ � �������, �� ��� ���� ����� ������ �� 26 �������� ��������.
    int count1[26] = {0}; // ��� ������� �����
    int count2[26] = {0}; // ��� ������� �����

    // ������� ���������� ��������� ������ ����� � ������ �����
    for (int i = 0; i < length1; i++)
    {
        if (is_letter(word1[i]))
        {
            count1[word1[i] - 'a']++;
        }
    }

    // ������� ���������� ��������� ������ ����� �� ������ �����
    for (int i = 0; i < length2; i++)
    {
        if (is_letter(word2[i]))
        {
            count2[word2[i] - 'a']++;
        }
    }

    // �������� �����, ������� ����������� ������ ���� ��� � ������ �����
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] == 1 && count2[i] == 1)
        {
            unique_chars[index++] = 'a' + i;
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
    qsort(unique_chars, strlen(unique_chars), sizeof(char), compare_chars);

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