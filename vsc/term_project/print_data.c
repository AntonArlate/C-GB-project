#include "temp_functions.h"

// ѕечать всего массива данных
void printDataPoints(DataPoint* dataPoints, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d, Temperature: %d\n", 
            dataPoints[i].year, dataPoints[i].month, dataPoints[i].day, 
            dataPoints[i].hour, dataPoints[i].minute, dataPoints[i].temperature);
    }
}

// ѕечать года
void printDataByYear(DataPoint *dataPoints, int size, int year) {
    printf("Data for year %d:\n", year);
    
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (dataPoints[mid].year < year) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    int index = left;
    
    while (index < size && dataPoints[index].year == year) {
        int month = dataPoints[index].month;
        int monthIndex = binarySearch(dataPoints, index, size - 1, year, month);
        
        if (monthIndex != -1) {
            printf("\nMonth %d:", month);
            
            while (monthIndex < size && dataPoints[monthIndex].year == year && dataPoints[monthIndex].month == month) {
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

// ѕечать мес€ца
void printDataByMonth(DataPoint *dataPoints, int size, int year, int month) {
    int index = binarySearch(dataPoints, 0, size - 1, year, month);
    
    if (index == -1) {
        printf("Data not found for year %d, month %d\n", year, month);
        return;
    }
    
    printf("Data for year %d, month %d:\n", year, month);
    
    while (index < size && dataPoints[index].year == year && dataPoints[index].month == month) {
        printf("Day: %d\n", dataPoints[index].day);
        printf("Hour: %d\n", dataPoints[index].hour);
        printf("Minute: %d\n", dataPoints[index].minute);
        printf("Temperature: %d\n", dataPoints[index].temperature);
        index++;
    }
}
