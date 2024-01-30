/*
Задача 6. Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000
символов.
Данные на выходе: Одно целое число
Пример
Данные на входе: Mama mila ramu
Данные на выходе: 2
*/

#include <locale.h>
// setlocale(LC_ALL, "Rus");
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWordsEndingWith(char *sentence, char endingLetter)
{
    int count = 0;
    int length = strlen(sentence);

    // Проверяем каждое слово в предложении
    for (int i = 0; i < length; i++)
    {
        // Пропускаем пробелы и символы пунктуации
        if (isspace(sentence[i]) || ispunct(sentence[i]))
        {
            continue;
        }

        // Находим конец текущего слова
        int j = i;
        while (j < length && !isspace(sentence[j]) && !ispunct(sentence[j]))
        {
            printf("%c", sentence[j]);
            j++;
        }

        // Проверяем, заканчивается ли слово на нужную букву
        if (tolower(sentence[j - 1]) == tolower(endingLetter))
        {
            count++;
            printf("%d", count);
        }
        printf("\n");

        // Пропускаем остаток текущего слова
        i = j;
    }

    return count;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    // Открываем файлы для чтения и записи
    FILE *inputFile = fopen("in.txt", "r");
    FILE *outputFile = fopen("out.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Не удалось открыть файлы\n");
        return 1;
    }

    // Читаем предложение из файла
    char sentence[1000];
    fgets(sentence, sizeof(sentence), inputFile);

    // Вызываем функцию для подсчета слов, заканчивающихся на букву 'a'
    int count = countWordsEndingWith(sentence, 'a');
    printf("result: %d", count);

    // Записываем результат в файл
    fprintf(outputFile, "%d", count);

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}