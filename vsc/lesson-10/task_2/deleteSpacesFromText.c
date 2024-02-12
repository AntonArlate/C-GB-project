/*
Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: " Hello  world!"
Данные на выходе: "Hello world!"
*/

#include "../func.h"

void removeExtraSpaces(const char* inputFilePath, const char* outputFilePath) {
    FILE* inputFile = fopen(inputFilePath, "r");
    FILE* outputFile = fopen(outputFilePath, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файлов!\n");
        return;
    }
    
    // читаем файл в буфер так как в дальнейшем возможна переделка на получение строки
    char inputBuffer[1000];
    fgets(inputBuffer, sizeof(inputBuffer), inputFile);
    
    char outputBuffer[1000] = {0};
    char previousChar = ' ';
    int outputIndex = 0;
    
    for (int i = 0; inputBuffer[i] != '\0'; i++) {
        char currentChar = inputBuffer[i];
        
        if (currentChar != ' ') {
            outputBuffer[outputIndex] = currentChar;
            outputIndex++;
        } else {
            if (previousChar != ' ') {
                outputBuffer[outputIndex] = currentChar;
                outputIndex++;
            }
        }
        
        previousChar = currentChar;
    }
    
    fprintf(outputFile, "%s", outputBuffer);
    
    fclose(inputFile);
    fclose(outputFile);
}

void task2()
{
    removeExtraSpaces("task_2/in.txt", "task_2/out.txt");
    printf("Задача выполнена успешно!\n");
}