#include "temp_functions.h"

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

void printHelp()
{
    printf("Данное приложение читает предоставленный файл .csv с ';' в качестве разделителей \n");
    printf("либо любой текстовый формат подходящего форматирования.\n");
    printf("Затем из полученых данных выводится статистика температуры за указаный период.\n\n");
    printf("-h: Описание функционала приложения (help)\n");
    printf("-f <filename.csv>: Входной файл csv для обработки (обязателен)\n");
    printf("-m <номер месяца>: Выводить только статистику за указанный месяц\n");
    printf("-y <номер года>: Выводить статистику за указаный год. При использовании с -m: 1 месяц указанного года\n");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Rus");

    // Получение параметров запуска
    int year = 0;
    int month = 0;
    bool help = true;
    // bool notParam = true;
    char *fileName = NULL;

    int opt = 0;
    opterr = 0;
    while ((opt = getopt(argc, argv, "hf:m:y:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printHelp();
            return 0;

        case 'f':
            fileName = optarg;
            help = false;
            break;

        case 'm':
            if (optarg != NULL)
                month = atoi(optarg);

            help = false;
            break;

        case 'y':
            if (optarg != NULL)
                year = atoi(optarg);

            help = false;
            break;

        case '?':
            if (optopt == 'f')
                fprintf(stderr, "Не указан входной файл csv. Используйте -f <filename.csv>\n");
            else
            {
                fprintf(stderr, "Неизвестный ключ: -%c\n", optopt);
                printf("-h to HELP");
            }
            return 1;

        default:
            break;
        }
    }

    // Перепроверяем получение параметров
    if (help)
    {
        printHelp();
        return 0;
    }

    if (year == 0)
    {
        // Получение текущего года
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);
        year = local_time->tm_year + 1900; // добавляем 1900, так как в tm_year хранится смещение от 1900 года

        if (month == 0)
        {
            // Получение текущего месяца
            time_t now = time(NULL);
            struct tm *local_time = localtime(&now);
            month = local_time->tm_mon + 1;
        }
    } // Во всех остальных случаях изменение месяца на стандартный пропускается

    // char *fileName = "temperature_big.csv";
    // char *fileName = "data.csv";
    DataPoint *dataPoints = NULL;

    int lineCount = readDataFromFile(fileName, &dataPoints);

    if (lineCount < 0)
        return 1;

    // Выводим считанные данные
    // printDataByYear(dataPoints, lineCount, 2021);
    // printDataByMonth(dataPoints, lineCount, 2021, 2);

    // Мы получили сортированный массив
    // Ищем заданый период
    int start, end;
    printf("year: %d\nmonth: %d\n", year, month);
    search(dataPoints, lineCount, year, month, &start, &end);
    // Получаем стартовый и конечный индекс для массива dataPoints
    // Выводим

    printf("lineCount = %d\n", lineCount);
    printf("start: %d\nend: %d\n", start, end);

    calculateStatistics(dataPoints, start, end);

    // Освобождаем выделенную память
    free(dataPoints);

    pressAnyKey();

    return 0;
}
