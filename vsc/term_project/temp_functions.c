#include "temp_functions.h"

int binarySearch(DataPoint *dataPoints, int left, int right, int year, int month) {
    int low = left;
    int high = right;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (dataPoints[mid].year == year && dataPoints[mid].month == month) {
            return mid;
        }
        
        if (dataPoints[mid].year < year || (dataPoints[mid].year == year && dataPoints[mid].month < month)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

void pressAnyKey()
{
    // ������� ������ ����� � ������� fflush(stdin)
    if (fflush(stdin) == EOF)
    {
        // ���� ������� fflush(stdin) ������� ������, �� ������� ���������
        printf("������ ��� ������� ������ �����\n");
        return;
    }

    printf("\n������� ����� ������� ��� �����������...");
    getch(); // ������������ ���������
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


int main() {
    setlocale(LC_ALL, "Rus");

    char *fileName = "data.csv";
    DataPoint *dataPoints = NULL;

    int lineCount = readDataFromFile(fileName, &dataPoints);
    printf("%d\n", lineCount);

    if (lineCount < 0)
        return 1;
    

    // ������� ��������� ������
    printDataByYear(dataPoints, lineCount, 2021);
    printDataByMonth(dataPoints, lineCount, 2021, 2);

    // �� �������� ������������� ������


    // ����������� ���������� ������
    free(dataPoints);

    pressAnyKey();

    return 0;
}
