/*
������ 3. �������� ����������
� ����� in.txt ������� ������ ����� ����� (��������, ��� ����������).
���������� �������� ��� ���������� �� ".html" � �������� ��������� � ����
out.txt.
������ �� �����: ������ ��������� �� ��������: a-z, A-Z, 0-9, /
������ �� ������: �������� ������ � ���������� �����������.
������ �1
������ �� �����: /DOC.TXT/qqq
������ �� ������: /DOC.TXT/qqq.html
������ �2
������ �� �����: /DOC.TXT/qqq.com
������ �� ������: /DOC.TXT/qqq.html
*/

#include "../func.h"

#define MAX_LENGTH 100

void task3()
{
// ��������� ����� ��� ������ � ������
    FILE *inFile = fopen("task_3/in.txt", "r");
    FILE *outFile = fopen("task_3/out.txt", "w");

    // ���������, ������� �� ������� �����
    if (inFile == NULL || outFile == NULL) {
        printf("������ �������� ������\n");
        return;
    }

    // ��������� ������ �� �����
    char newName[MAX_LENGTH];
    fgets(newName, MAX_LENGTH, inFile);
    
    // char* oldName = (char*)malloc(strlen(newName) + 1);
    char* oldName = calloc(strlen(newName) + 1, sizeof(char));
    strcpy(oldName, newName);
    

    // ���������� ������� ��������� ����� � ������ (���� ��� �����, ��������, ��� ���������� �� �������)
    char *dot = strrchr(newName, '.'); // ������� ���������� ��������� �� ��������� ���������
    if (dot != NULL) {
        // �������� ���������� �� ".html"
        strcpy(dot, ".txt");
        // strncpy(dot, ".html", MAX_LENGTH - (dot - line));
    } else {
        // ��������� ���������� ".html" � ����� ������
        strcat(newName, ".txt");
    }

    // ���������� ����� ������ � ����
    fprintf(outFile, "%s", newName);

    // ��������� �����
    fclose(inFile);
    fclose(outFile);

    printf("oldName: %s\n", oldName);
    printf("newName: %s\n", newName);

    // ���������� ������� rename() ��� ��������� ����� �����
    int result = rename(oldName, newName);

    // ���������, ������� �� ��������� ��������������
    if (result == 0) {
        printf("��� ����� ������� ��������.\n");
    } else {
        perror("������ ��� ��������� ����� �����");
    }

    free(oldName);
    printf("������ ���������");
}