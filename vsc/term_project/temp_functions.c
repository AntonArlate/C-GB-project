#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} DataPoint;

void pressAnyKey()
{
    int c;
    printf("\nPress any key ...");


    // Очищаем буфер ввода
    while ((c = getchar()) != '\n' && c != EOF) {}

    // В случае некорректной очистки буфера ввода, можно использовать следующий способ:
    // fseek(stdin, 0, SEEK_END);
    // fflush(stdin);
}



bool isValidFormat(char *str, int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isNumber(char *str) {
    int i = 0;
    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int parseLine(char *line, DataPoint *dataPoint) {
    char *token;
    int i = 0;

    token = strtok(line, ";");
    while (token != NULL) {
        if (!isNumber(token))
            return -1;

        switch (i) {
            case 0: {
                int year = atoi(token);
                if (year < 1000 || year > 9999)
                    return -1;
                dataPoint->year = year;
                break;
            }
            case 1: {
                int month = atoi(token);
                if (month < 1 || month > 12)
                    return -1;
                dataPoint->month = month;
                break;
            }
            case 2: {
                int day = atoi(token);
                if (day < 1 || day > 31)
                    return -1;
                dataPoint->day = day;
                break;
            }
            case 3: {
                int hour = atoi(token);
                if (hour < 0 || hour > 23)
                    return -1;
                dataPoint->hour = hour;
                break;
            }
            case 4: {
                int minute = atoi(token);
                if (minute < 0 || minute > 59)
                    return -1;
                dataPoint->minute = minute;
                break;
            }
            case 5: {
                int temperature = atoi(token);
                if (temperature < -99 || temperature > 99)
                    return -1;
                dataPoint->temperature = temperature;
                break;
            }
        }

        token = strtok(NULL, ";");
        i++;
    }

    return i;
}

int main() {
    setlocale(LC_ALL, "Rus");

    FILE *file;
    char line[100];
    DataPoint **dataPoints = NULL;
    int lineCount = 0;
    int maxLines = 10;
    int i;

    // Открываем файл для чтения
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }
    
    // Выделяем память для массива указателей
    dataPoints = (DataPoint**)malloc(maxLines * sizeof(DataPoint*));
    
    // Считываем строки файла и парсим их
    while (fgets(line, sizeof(line), file)) {
        // Удаляем символ перевода строки, если есть
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Выделяем память под копию структуры и сохраняем указатель во временную переменную
        DataPoint *dataPoint = (DataPoint*)malloc(sizeof(DataPoint));
        int fields = parseLine(line, dataPoint);

        // Если количество полей некорректно, выводим номер строки с ошибкой и освобождаем выделенную память
        if (fields != 6) {
            printf("Ошибка в строке %d\n", lineCount + 1);
            free(dataPoint);
        } else {
            // Увеличиваем размер массива указателей при необходимости
            if (lineCount >= maxLines) {
                maxLines *= 2;
                dataPoints = (DataPoint**)realloc(dataPoints, maxLines * sizeof(DataPoint*));
            }

            // Если всё хорошо, записываем временный указатель в массив указателей
            dataPoints[lineCount] = dataPoint;
            lineCount++;
        }
    }

    // Закрываем файл
    fclose(file);

    // Выводим считанные данные
    for (i = 0; i < lineCount; i++) {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d, Temperature: %d\n",
            dataPoints[i]->year, dataPoints[i]->month, dataPoints[i]->day,
            dataPoints[i]->hour, dataPoints[i]->minute, dataPoints[i]->temperature);
        free(dataPoints[i]);
    }

    // Освобождаем выделенную память
    free(dataPoints);

    pressAnyKey();
    return 0;
}
