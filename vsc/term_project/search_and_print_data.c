#include "temp_functions.h"

int binarySearch(DataPoint *dataPoints, int left, int right, int year, int month)
{
    int low = left;
    int high = right;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (dataPoints[mid].year == year && dataPoints[mid].month == month)
        {
            return mid;
        }

        if (dataPoints[mid].year < year || (dataPoints[mid].year == year && dataPoints[mid].month < month))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// Печать всего массива данных
void printDataPoints(DataPoint *dataPoints, int lineCount)
{
    for (int i = 0; i < lineCount; i++)
    {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d, Temperature: %d\n",
               dataPoints[i].year, dataPoints[i].month, dataPoints[i].day,
               dataPoints[i].hour, dataPoints[i].minute, dataPoints[i].temperature);
    }
}

// Печать года
void printDataByYear(DataPoint *dataPoints, int size, int year)
{
    printf("Data for year %d:\n", year);

    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (dataPoints[mid].year < year)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    int index = left;

    while (index < size && dataPoints[index].year == year)
    {
        int month = dataPoints[index].month;
        int monthIndex = binarySearch(dataPoints, index, size - 1, year, month);

        if (monthIndex != -1)
        {
            printf("\nMonth %d:", month);

            while (monthIndex < size && dataPoints[monthIndex].year == year && dataPoints[monthIndex].month == month)
            {
                printf("\nDay: %d ", dataPoints[monthIndex].day);
                printf("Hour: %d ", dataPoints[monthIndex].hour);
                printf("Minute: %d ", dataPoints[monthIndex].minute);
                printf("Temperature: %d\n", dataPoints[monthIndex].temperature);
                monthIndex++;
            }
        }

        index = monthIndex;
    }
}

// Печать месяца
void printDataByMonth(DataPoint *dataPoints, int size, int year, int month)
{
    int index = binarySearch(dataPoints, 0, size - 1, year, month);

    if (index == -1)
    {
        printf("Data not found for year %d, month %d\n", year, month);
        return;
    }

    printf("Data for year %d, month %d:\n", year, month);

    while (index < size && dataPoints[index].year == year && dataPoints[index].month == month)
    {
        printf("Day: %d\n", dataPoints[index].day);
        printf("Hour: %d\n", dataPoints[index].hour);
        printf("Minute: %d\n", dataPoints[index].minute);
        printf("Temperature: %d\n", dataPoints[index].temperature);
        index++;
    }
}

// Принимает указатели в которые будут возвращены начало и конец
void search(DataPoint *dataPoints, int size, int year, int month, int *start, int *end)
{
    *start = -1;
    *end = -1;

    // сначала ищем год
    // Перебираем массив с конца
    for (int i = size - 1; i >= 0; i--)
    {
        // Если нашли указанный год
        if (dataPoints[i].year == year)
        {
            // Отмечаем конец
            *end = i;
            // Продолжаем перебор до начала
            for (int j = i; j >= 0; j--)
            {
                // Если год изменилсz, значит дошли до начала
                if (dataPoints[j].year != year || j == 0)
                {
                    // Отмечаем начало и выходим из цикла
                    *start = j;
                    break;
                }
            }
            // Если дошли до начала, выходим из функции
            if (*start != -1)
            {
                break;
            }
        }
    }

    // ищем месяц в году если необходимо
    if (month == 0)
        return;

    // Перебираем массив с конца найденого года
    int tempStart = *start;
    for (int i = *end; i >= tempStart; i--)
    {
        // Если нашли указанный месяц
        if (dataPoints[i].month == month)
        {
            // Отмечаем конец
            *end = i;
            // Продолжаем перебор до начала
            for (int j = i; j >= tempStart; j--)
            {
                // Если год или месяц изменился, значит дошли до начала
                if (dataPoints[j].month != month || dataPoints[j].year != year || j == tempStart)
                {
                    // Отмечаем начало и выходим из цикла
                    *start = j;
                    break;
                }
            }
            // Если нашли новое начало, выходим из функции
            if (*start != tempStart)
            {
                break;
            }
        }
    }
}

void calculateStatistics(DataPoint *dataPoints, int start, int end)
{
    int minTemp = dataPoints[start].temperature;
    int maxTemp = dataPoints[start].temperature;
    int sumTemp = 0;

    for (int i = start; i <= end; i++)
    {
        int temp = dataPoints[i].temperature;
        sumTemp += temp;

        if (temp < minTemp)
        {
            minTemp = temp;
        }

        if (temp > maxTemp)
        {
            maxTemp = temp;
        }
    }

    int numPoints = end - start + 1;
    float avgTemp = (float)sumTemp / numPoints;

    printf("Minimum temperature: %d\n", minTemp);
    printf("Maximum temperature: %d\n", maxTemp);
    printf("Average temperature: %.2f\n", avgTemp);
}

void printAllYear(DataPoint *dataPoints, int start, int end)
{
    int year = dataPoints[start].year;
    int startMonth = start;
    int endMonth = start;

    int month = 0;
    do
    {
        month = dataPoints[startMonth].month;
        printf("----> Month %d <----\n", month);
        // ищем начало и конец месяца
        while (endMonth < end && dataPoints[startMonth].month == dataPoints[endMonth + 1].month)
        {
            endMonth++;
        }

        // запрашиваем калькуляцию
        calculateStatistics(dataPoints, startMonth, endMonth);

        // Проверяем что это ещё не конец года и переставляем указатель на следующий месяц
        if (endMonth < end)
            startMonth = endMonth + 1;
        else
            break;

    } while (month < 12);

    printf("----> All %d year <----\n", year);
    calculateStatistics(dataPoints, start, end);
}

bool isValidFormat(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isNumber(char *str)
{
    int i = 0;
    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
