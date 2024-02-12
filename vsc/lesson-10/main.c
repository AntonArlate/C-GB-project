// пробуем собирать программу. Это будет подключена библиотека с прототипами и структурами
#include "func.h"

// Печать массива
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void pressAnyKey()
{
    // очистка буфера ввода с помощью fflush(stdin)
    if (fflush(stdin) == EOF)
    {
        // если функция fflush(stdin) вернула ошибку, то выводим сообщение
        printf("Ошибка при очистке буфера ввода\n");
        return;
    }

    printf("\nНажмите любую клавишу для продолжения...");
    getch(); // приостановка программы
}

// MAIN
int main()
{
    setlocale(LC_ALL, "Rus");

    int choice;
    int exit = 0;

    while (!exit)
    {
        printf("\n-----------------------------\n");
        printf("1. Меняет местами пары соседних символов.\n");
        printf("2. Удалить лишниие пробелы из текста.\n");
        printf("3. Изменить расширение.\n");

        printf("<<< Выберите пункт меню или введите иное для выхода: ");

        if (scanf("%d", &choice) != 1)
        {
            choice = -1;
        }
        printf(">>>\n");

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        default:
            exit = 1;
            printf("END\n");
        }

        if (exit == 1)
        {
            break;
        }
        pressAnyKey();
    }

    return 0;
}
