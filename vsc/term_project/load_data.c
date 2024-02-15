#include "temp_functions.h"

void trim(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    while (isspace(str[start]))
        start++;
    while (end >= start && isspace(str[end]))
        end--;
    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

int parseLine(char *line, DataPoint *dataPoint)
{
    // разделение строки на поля
    char *tokens[6];
    int tokenCount = 0;

    char *token = strtok(line, ";");
    while (token != NULL && tokenCount < 6)
    {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(NULL, ";");
    }

    if (tokenCount != 6)
    { // проверка количества полей
        return -1;
    }

    // проверка и преобразование каждого поля
    char *endptr;
    dataPoint->year = strtol(tokens[0], &endptr, 10);
    if (endptr == tokens[0] || strlen(endptr) != 0 || dataPoint->year < 1000 || dataPoint->year > 9999)
    {
        return -1;
    }

    dataPoint->month = strtol(tokens[1], &endptr, 10);
    if (endptr == tokens[1] || strlen(endptr) != 0 || dataPoint->month < 1 || dataPoint->month > 12)
    {
        return -1;
    }

    dataPoint->day = strtol(tokens[2], &endptr, 10);
    if (endptr == tokens[2] || strlen(endptr) != 0 || dataPoint->day < 1 || dataPoint->day > 31)
    {
        return -1;
    }

    dataPoint->hour = strtol(tokens[3], &endptr, 10);
    if (endptr == tokens[3] || strlen(endptr) != 0 || dataPoint->hour < 0 || dataPoint->hour > 23)
    {
        return -1;
    }

    dataPoint->minute = strtol(tokens[4], &endptr, 10);
    if (endptr == tokens[4] || strlen(endptr) != 0 || dataPoint->minute < 0 || dataPoint->minute > 59)
    {
        return -1;
    }

    dataPoint->temperature = strtol(tokens[5], &endptr, 10);
    if (endptr == tokens[5] || strlen(endptr) != 0 || dataPoint->temperature < -99 || dataPoint->temperature > 99)
    {
        return -1;
    }

    return tokenCount;
}

int readDataFromFile(const char *filename, DataPoint **dataPoints)
{
    FILE *file;
    char line[100];

    int lineCount = 0;
    int maxLines = 10;

    // Открываем файл для чтения
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        return -1;
    }

    // Выделяем память для массива указателей
    *dataPoints = malloc(maxLines * sizeof(DataPoint));

    // fgets(line, sizeof(line), file);

    // pressAnyKey();

    // Считываем строки файла и парсим их
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // printf("%s\n", line);

        // Удаляем символ перевода строки, если есть
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        // Выделяем память под копию структуры и сохраняем указатель во временную переменную
        DataPoint *dataPoint = (DataPoint *)malloc(sizeof(DataPoint));
        int fields = parseLine(line, dataPoint);
        // printf("fields = %d\n", fields);

        // Если количество полей некорректно, выводим номер строки с ошибкой и освобождаем выделенную память
        if (fields != 6)
        {
            printf("Ошибка в строке %d\n", lineCount);
            free(dataPoint);
        }
        else
        {
            // сдвигаем счётчик
            lineCount++;
            // Увеличиваем размер массива указателей при необходимости
            if (lineCount >= maxLines)
            {
                maxLines *= 2;
                *dataPoints = realloc(*dataPoints, maxLines * sizeof(DataPoint));
            }
            // Если всё хорошо, записываем временный указатель в массив указателей
            (*dataPoints)[lineCount - 1] = *dataPoint;
        }
    }

    // Закрываем файл
    fclose(file);

    // printf("Данные в функции readDataFromFile:\n");
    // printDataPoints(*dataPoints, lineCount);
    return lineCount;
}