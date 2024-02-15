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

// ������ ����� ������� ������
void printDataPoints(DataPoint *dataPoints, int lineCount)
{
    for (int i = 0; i < lineCount; i++)
    {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d, Temperature: %d\n",
               dataPoints[i].year, dataPoints[i].month, dataPoints[i].day,
               dataPoints[i].hour, dataPoints[i].minute, dataPoints[i].temperature);
    }
}

// ������ ����
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

// ������ ������
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

// ��������� ��������� � ������� ����� ���������� ������ � �����
void search(DataPoint *dataPoints, int size, int year, int month, int *start, int *end)
{
    *start = -1;
    *end = -1;

    // ������� ���� ���
    // ���������� ������ � �����
    for (int i = size - 1; i >= 0; i--)
    {
        // ���� ����� ��������� ���
        if (dataPoints[i].year == year)
        {
            // �������� �����
            *end = i;
            // ���������� ������� �� ������
            for (int j = i; j >= 0; j--)
            {
                // ���� ��� ��������z, ������ ����� �� ������
                if (dataPoints[j].year != year || j == 0)
                {
                    // �������� ������ � ������� �� �����
                    *start = j;
                    break;
                }
            }
            // ���� ����� �� ������, ������� �� �������
            if (*start != -1)
            {
                break;
            }
        }
    }

    // ���� ����� � ���� ���� ����������
    if (month == 0)
        return;

    // ���������� ������ � ����� ��������� ����
    int tempStart = *start;
    for (int i = *end; i >= tempStart; i--)
    {
        // ���� ����� ��������� �����
        if (dataPoints[i].month == month)
        {
            // �������� �����
            *end = i;
            // ���������� ������� �� ������
            for (int j = i; j >= tempStart; j--)
            {
                // ���� ��� ��� ����� ���������, ������ ����� �� ������
                if (dataPoints[j].month != month || dataPoints[j].year != year || j == tempStart)
                {
                    // �������� ������ � ������� �� �����
                    *start = j;
                    break;
                }
            }
            // ���� ����� ����� ������, ������� �� �������
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
        // ���� ������ � ����� ������
        while (endMonth < end && dataPoints[startMonth].month == dataPoints[endMonth + 1].month)
        {
            endMonth++;
        }

        // ����������� �����������
        calculateStatistics(dataPoints, startMonth, endMonth);

        // ��������� ��� ��� ��� �� ����� ���� � ������������ ��������� �� ��������� �����
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
