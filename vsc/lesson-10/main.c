// ������� �������� ���������. ��� ����� ���������� ���������� � ����������� � �����������
#include "func.h"

// ������ �������
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

// MAIN
int main()
{
    setlocale(LC_ALL, "Rus");

    int choice;
    int exit = 0;

    while (!exit)
    {
        printf("\n-----------------------------\n");
        printf("1. ������ ������� ���� �������� ��������.\n");
        printf("2. ������� ������� ������� �� ������.\n");
        printf("3. �������� ����������.\n");

        printf("<<< �������� ����� ���� ��� ������� ���� ��� ������: ");

        if (scanf("%d", &choice) != 1)
        {
            choice = -1;
        }
        printf(">>>\n");

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        default:
            exit = 1;
            printf("END\n");
        }

        if (exit == 1)
        {
            break;
        }
        pressAnyKey();
    }

    return 0;
}
