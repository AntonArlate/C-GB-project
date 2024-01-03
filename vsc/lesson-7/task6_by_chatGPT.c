/*
Задача 6. Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается
чаще всего. Гарантируется, что такое число ровно 1.
Данные на входе: 10 целых числе через пробел
Данные на выходе: Одно число, которое встречается чаще других.
Пример
Данные на входе: 4 1 2 1 11 2 34 11 0 11
Данные на выходе: 11
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

    // Проверяем, изначально ли пустая ячейка в хэш-таблице
    if (head == NULL) {
        hashTable[index] = createNode(number);
        return;
    }

    // Проверяем, если число уже есть в ячейке
    // Увеличиваем его счетчик
    Node* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    // Вставляем новое число в конец списка
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(number);
}

int mostFrequentNumber(Node** hashTable) {
    int maxCount = 0;
    int mostFrequentNum = 0;

    // Находим число с наибольшим счетчиком
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
    // Освобождаем память, выделенную под хэш-таблицу
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

    // Инициализируем хэш-таблицу
    for (int i = 0; i < 10; i++) {
        hashTable[i] = NULL;
    }

    printf("Введите 10 целых чисел через пробел: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        insert(hashTable, arr[i]);
    }

    int mostFrequentNum = mostFrequentNumber(hashTable);
    printf("Наиболее часто встречающееся число: %d\n", mostFrequentNum);

    // Освобождаем память, выделенную под хэш-таблицу
    freeHashTable(hashTable);

    return 0;
}