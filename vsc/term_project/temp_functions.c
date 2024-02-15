#include "temp_functions.h"

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

void printHelp()
{
    printf("������ ���������� ������ ��������������� ���� .csv � ';' � �������� ������������ \n");
    printf("���� ����� ��������� ������ ����������� ��������������.\n");
    printf("����� �� ��������� ������ ��������� ���������� ����������� �� �������� ������.\n\n");
    printf("-h: �������� ����������� ���������� (help)\n");
    printf("-f <filename.csv>: ������� ���� csv ��� ��������� (����������)\n");
    printf("-m <����� ������>: �������� ������ ���������� �� ��������� �����\n");
    printf("-y <����� ����>: �������� ���������� �� �������� ���. ��� ������������� � -m: 1 ����� ���������� ����\n");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Rus");

    // ��������� ���������� �������
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
                fprintf(stderr, "�� ������ ������� ���� csv. ����������� -f <filename.csv>\n");
            else
            {
                fprintf(stderr, "����������� ����: -%c\n", optopt);
                printf("-h to HELP");
            }
            return 1;

        default:
            break;
        }
    }

    // ������������� ��������� ����������
    if (help)
    {
        printHelp();
        return 0;
    }

    if (year == 0)
    {
        // ��������� �������� ����
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);
        year = local_time->tm_year + 1900; // ��������� 1900, ��� ��� � tm_year �������� �������� �� 1900 ����

        if (month == 0)
        {
            // ��������� �������� ������
            time_t now = time(NULL);
            struct tm *local_time = localtime(&now);
            month = local_time->tm_mon + 1;
        }
    } // �� ���� ��������� ������� ��������� ������ �� ����������� ������������

    // char *fileName = "temperature_big.csv";
    // char *fileName = "data.csv";
    DataPoint *dataPoints = NULL;

    int lineCount = readDataFromFile(fileName, &dataPoints);

    if (lineCount < 0)
        return 1;

    // ������� ��������� ������
    // printDataByYear(dataPoints, lineCount, 2021);
    // printDataByMonth(dataPoints, lineCount, 2021, 2);

    // �� �������� ������������� ������
    // ���� ������� ������
    int start, end;
    printf("year: %d\nmonth: %d\n", year, month);
    search(dataPoints, lineCount, year, month, &start, &end);
    // �������� ��������� � �������� ������ ��� ������� dataPoints
    // �������

    printf("lineCount = %d\n", lineCount);
    printf("start: %d\nend: %d\n", start, end);

    calculateStatistics(dataPoints, start, end);

    // ����������� ���������� ������
    free(dataPoints);

    pressAnyKey();

    return 0;
}
