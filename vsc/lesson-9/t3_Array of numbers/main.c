/*
Задача 3. Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
числа и иные символы. Требуется все числа, которые встречаются в строке,
поместить в отдельный целочисленный массив. Например, если дана строка
"data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
массив по возрастанию в файл .txt.
Данные на входе: Строка из английских букв, цифр и знаков
препинания
Данные на выходе: Последовательность целых чисел
отсортированная по возрастанию
Пример
Данные на входе: data 48 call 9 read13 blank0a
Данные на выходе: 0 9 13 48
*/

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Функция, которая проверяет, является ли символ цифрой
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

    // Открываем файлы для чтения и записи
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");

    // Проверяем успешное открытие файлов
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Ошибка открытия файлов\n");
        return 1;
    }

    // Считываем строку из файла

    // Проходим по каждому символу в строке
    char c = '0';
    do
    {
        c = fgetc(inputFile);
        printf("%c\n", c);
        // Если текущий символ - цифра
        if (isDigit(c))
        {
            // Преобразуем последовательность цифр в число
            num = 0;
            while (isDigit(c))
            {
                num = num * 10 + (c - '0');
                c = fgetc(inputFile);
                if (c == EOF)
                    break;
            }

            // Добавляем число в массив
            numbers[numCount] = num;
            numCount++;
        }
    } while (c != EOF);

    // Сортируем массив чисел по возрастанию
    int compare(const void *a, const void *b)
    {
        int *num1 = (int *)a;
        int *num2 = (int *)b;

        return (*num1 - *num2);
    }
    qsort(numbers, numCount, sizeof(int), compare);

    // Выводим массив чисел в файл
    for (int i = 0; i < numCount; i++)
    {
        fprintf(outputFile, "%d ", numbers[i]);
    }

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    printf("Массив чисел сохранен в файле %s\n", outputFileName);

    return 0;
}