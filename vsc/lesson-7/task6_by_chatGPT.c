/*
������ 6. ���� ������
��� ������ �� 10 ���������. ����������, ����� ����� � ������� �����������
���� �����. �������������, ��� ����� ����� ����� 1.
������ �� �����: 10 ����� ����� ����� ������
������ �� ������: ���� �����, ������� ����������� ���� ������.
������
������ �� �����: 4 1 2 1 11 2 34 11 0 11
������ �� ������: 11
*/

// realized by chatGPT 3.5

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int number;
    int count;
    struct Node* next;
} Node;

Node* createNode(int number) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->number = number;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** hashTable, int number) {
    int index = abs(number) % 10;
    Node* head = hashTable[index];

    // ���������, ���������� �� ������ ������ � ���-�������
    if (head == NULL) {
        hashTable[index] = createNode(number);
        return;
    }

    // ���������, ���� ����� ��� ���� � ������
    // ����������� ��� �������
    Node* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    // ��������� ����� ����� � ����� ������
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(number);
}

int mostFrequentNumber(Node** hashTable) {
    int maxCount = 0;
    int mostFrequentNum = 0;

    // ������� ����� � ���������� ���������
    for (int i = 0; i < 10; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            if (temp->count > maxCount) {
                maxCount = temp->count;
                mostFrequentNum = temp->number;
            }
            temp = temp->next;
        }
    }

    return mostFrequentNum;
}

void freeHashTable(Node** hashTable) {
    // ����������� ������, ���������� ��� ���-�������
    for (int i = 0; i < 10; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            Node* current = temp;
            temp = temp->next;
            free(current);
        }
    }
    free(hashTable);
}

int main() {
    setlocale(LC_ALL, "Rus");

    int arr[10];
    Node** hashTable = (Node**) malloc(10 * sizeof(Node*));

    // �������������� ���-�������
    for (int i = 0; i < 10; i++) {
        hashTable[i] = NULL;
    }

    printf("������� 10 ����� ����� ����� ������: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        insert(hashTable, arr[i]);
    }

    int mostFrequentNum = mostFrequentNumber(hashTable);
    printf("�������� ����� ������������� �����: %d\n", mostFrequentNum);

    // ����������� ������, ���������� ��� ���-�������
    freeHashTable(hashTable);

    return 0;
}