/*
������ 5. ����� ������� �����
� ����� .txt ���� ������ ����, ����������� ���������. ����� ����� �������
����� � ������� ��� � ���� .txt. ������, ����� ����� ������� ���� ����� ����
���������, �� ������������.
������ �� �����: ������ �� ���������� ���� � ��������. �� �����
1000 ��������.
������ �� ������: ���� ����� �� ���������� ����.
������
������ �� �����: Hello beautiful world
������ �� ������: beautiful
*/

#include <locale.h>
// setlocale(LC_ALL, "Rus");
#include <stdio.h>
#include <string.h>
// char *word = strtok(line, " "); // ����� � ����� ������� ����������� ������ �� �����������, �� � ��� ���������� ���������� ����������

int main() {
    setlocale(LC_ALL, "Rus");

    // �������� ������
    FILE *inputFile, *outputFile;
    inputFile = fopen("in.txt", "r");
    outputFile = fopen("out.txt", "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("������ ��� �������� �����");
        return 1;
    }

    char word[100];
    char longest_word[100];
    int max_length = 0;

    while(fscanf(inputFile, "%s", word) != EOF) {
        printf("word: %s\n", word);
        int length = strlen(word);
        
        if (length > max_length) {
            max_length = length;
            printf("new max: %d\n", max_length);
            strcpy(longest_word, word);
        }
    }

    fprintf(outputFile, "%s", longest_word);  // ������ ������ �������� ����� � ����

    // �������� ������
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}