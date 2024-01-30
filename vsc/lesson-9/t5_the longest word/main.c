/*
Задача 5. Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
несколько, не обрабатывать.
Данные на входе: Строка из английских букв и пробелов. Не более
1000 символов.
Данные на выходе: Одно слово из английских букв.
Пример
Данные на входе: Hello beautiful world
Данные на выходе: beautiful
*/

#include <locale.h>
// setlocale(LC_ALL, "Rus");
#include <stdio.h>
#include <string.h>
// char *word = strtok(line, " "); // узнал о такой функции разделяющей строку по разделителю, но и моя реализация показалась приемлимой

int main() {
    setlocale(LC_ALL, "Rus");

    // открытие файлов
    FILE *inputFile, *outputFile;
    inputFile = fopen("in.txt", "r");
    outputFile = fopen("out.txt", "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка при открытии файла");
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

    fprintf(outputFile, "%s", longest_word);  // Запись самого длинного слова в файл

    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}