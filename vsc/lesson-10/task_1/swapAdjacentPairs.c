/*
Задача 1. Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe
*/

#include "../func.h"

void swapAdjacentPairs(FILE *inputFile, FILE *outputFile) {
    char c;
    int isOdd = 1; // флаг
    int spaceCount = 0; // счётчик для пробелов

    char temp = ' '; // временная переменная для хранения символов
    
    while ((c = fgetc(inputFile)) != EOF) {
        
        // если флаг поднят
        if (isOdd) {
            //Проверяем пробел
            if (c == ' ') {
                // В данной ситуации пишем пробел и переходим на следующую итерацию
                fputc(c, outputFile);
            } else {
                // Если не пробел пишем в temp и читаем следующий
                temp = c; 
                isOdd = !isOdd; // переключаем флаг
            } 
        } else // Если флаг опущен
        {
            //Проверяем пробел
            if (c == ' ') {
                // Увеличиваем счётчик пробелов и читаем с переходом на следующую итерацию
                spaceCount++;
            } else
            {
                // Пишем текущий символ
                fputc(c, outputFile);
                // Дополняем пробелы
                for (; spaceCount > 0; spaceCount--) {
                    fputc(' ', outputFile);
                }
                // Добавляем temp символ
                fputc(temp, outputFile);
                isOdd = !isOdd; // переключаем флаг
            }
        }
    }

    // После конца файла проверяем состояние флага
    // Если флаг =0 значит в temp лежит символ без пары. Пишем его.
    if (!isOdd) 
        fputc(temp, outputFile);
}

void task1()
{
    FILE *inputFile, *outputFile;
    inputFile = fopen("task_1/in.txt", "r");
    outputFile = fopen("task_1/out.txt", "w");
    
    if (inputFile && outputFile) {
        swapAdjacentPairs(inputFile, outputFile);
        fclose(inputFile);
        fclose(outputFile);
        printf("Замена выполнена успешно!\n");
    }
    else {
        printf("Ошибка открытия файлов.\n");
    }
}