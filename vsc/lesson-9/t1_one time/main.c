/*
Задача 1. По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные
одним пробелом. Найдите только те символы слов, которые встречаются в
обоих словах только один раз. Напечатайте их через пробел в файл .txt в
лексикографическом порядке.
Данные на входе: Два слова из маленьких английских букв через
пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: Маленькие английские буквы через пробел.
Пример №1
Данные на входе: hello world
Данные на выходе: o
Данные на входе: aabcd bcef
Данные на выходе: b c
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Функция, которая проверяет, является ли символ буквой
int is_letter(char c)
{
    return isalpha(c) && islower(c);
}

// Функция, которая находит символы, встречающиеся только один раз в обоих словах
char *find_unique_chars(char *word1, char *word2)
{
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    char *unique_chars = malloc(sizeof(char) * 27); // просто тренировка malloc и указателей. На самом деле массив ни где не меняется.
    int index = 0;

    // Создаем массивы для подсчета количества вхождений каждой буквы в словах
    // Здесь я решил применить часто встречаемый подход использовать массив для счётчика повторений.
    // Обычно избегал этого метода с цифрами, но для букв думаю массив на 26 индексов приемлим.
    int count1[26] = {0}; // для первого слова
    int count2[26] = {0}; // для второго слова

    // Считаем количество вхождений каждой буквы в первом слове
    for (int i = 0; i < length1; i++)
    {
        if (is_letter(word1[i]))
        {
            count1[word1[i] - 'a']++;
        }
    }

    // Считаем количество вхождений каждой буквы во втором слове
    for (int i = 0; i < length2; i++)
    {
        if (is_letter(word2[i]))
        {
            count2[word2[i] - 'a']++;
        }
    }

    // Получаем буквы, которые встречаются только один раз в каждом слове
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] == 1 && count2[i] == 1)
        {
            unique_chars[index++] = 'a' + i;
        }
    }

    unique_chars[index] = '\0'; // Добавляем нулевой символ в конец строки
    return unique_chars;
}

// Функция, которая сравнивает два символа для сортировки в лексикографическом порядке
int compare_chars(const void *a, const void *b)
{
    return *((char *)a) - *((char *)b);
    // Зметка для себя как работает qsort():
    // Она может использовать пользовательскую функцию для сравнения значений передавая их попарно в формате const void*.
    // В результате ожидает увидеть число > или < 0. 0 = значения равны
}

int main()
{
    setlocale(LC_ALL, "Rus");

    FILE *in_file = fopen("in.txt", "r");
    if (in_file == NULL)
    {
        printf("Ошибка открытия файла in.txt\n");
        return 1;
    }

    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];

    fscanf(in_file, "%s %s", word1, word2);

    fclose(in_file);

    char *unique_chars = find_unique_chars(word1, word2);

    // Сортируем символы в лексикографическом порядке
    qsort(unique_chars, strlen(unique_chars), sizeof(char), compare_chars);

    // Печатаем символы в файл
    FILE *out_file = fopen("out.txt", "w");
    if (out_file == NULL)
    {
        printf("Ошибка открытия файла out.txt\n");
        return 1;
    }

    fprintf(out_file, "%s\n", unique_chars);
    fclose(out_file);

    free(unique_chars);
    return 0;
}