// Задача 1. По одному разу
/*
В данном примере я написал и применил функцию которая проверяет является ли число вхождений переданного символа в слове =1
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

// Функция, которая проверяет, встречается ли буква только один раз в слове
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
            return 0; // Буква найдена более одного раза
        }
    }

    return count == 1;
}

// Функция, которая находит символы, встречающиеся только один раз в обоих словах
char *find_unique_chars(char *word1, char *word2)
{
    int length1 = strlen(word1);
    char *unique_chars = malloc(sizeof(char) * (length1 + 1)); // просто тренировка malloc и указателей. На самом деле массив ни где не меняется.
    int index = 0;

    // Перебираем первое слово, второе уже смысла не будет
    for (int i = 0; i < length1; i++)
    {
        if (is_unique_letter(word1, word1[i]) && is_unique_letter(word2, word1[i]))
        {
            unique_chars[index++] = word1[i];
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
    qsort(unique_chars, strlen(unique_chars), sizeof(char), compare_chars); // вопрос что происходит с нулевым символом?

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