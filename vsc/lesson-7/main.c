/*
������ 1. ������� �������������� �����
������ � ���������� ������ �� 5 ���������, ����� ������� ��������������
���� ��������� �������.
������ �� �����: 5 ����� ��������� ����� ����� ������
������ �� ������: ���� ����� � ������� "%.3f"
������ �1
������ �� �����: 4 15 3 10 14
������ �� ������: 9.200
������ �2
������ �� �����: 1 2 3 4 5
������ �� ������: 3.000

-----
������ 2. ����� �������
������ � ���������� ������ �� 5 ���������, ����� ����������� �� ���.
������ �� �����: 5 ����� ����� ����� ������
������ �� ������: ���� ������������ ����� �����
������ �1
������ �� �����: 4 15 3 10 14
������ �� ������: 3
������ �2
������ �� �����: 1 2 3 4 -5
������ �� ������: -5

-----
������ 3. ����������� ����� ������� ������ �� 4
������� ������ �� 12 ��������� � ��������� ����������� ����� ������ �� 4
��������.
������ �� �����: 12 ����� ����� ����� ������
������ �� ������: 12 ����� ����� ����� ������
������ �1
������ �� �����: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
������ �� ������: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
������ �2
������ �� �����: 1 2 3 4 5 6 7 8 9 10 11 12
������ �� ������: 9 10 11 12 1 2 3 4 5 6 7 8

-----
������ 4. ������������� �� ��������� �����
������� ������ �� 10 ��������� � ������������� ��� �� ��������� �����.
������ �� �����: 10 ����� ����� ����� ������
���� �� ������ ��������������� �� ��������� �����
������ �1
������ �� �����: 14 25 13 30 76 58 32 11 41 97
������ �� ������: 30 11 41 32 13 14 25 76 97 58
������ �2
������ �� �����: 109 118 100 51 62 73 1007 16 4 555
������ �� ������: 100 51 62 73 4 555 16 1007 118 109

-----
������ 5. ������ � ����� ����
������� ������ �� 10 ��������� � �������� � ������ ������ ��� �����, �
������� ������ � ����� ����� (����� ��������) � ����.
������ �� �����: 10 ����� ����� ����� ������.
������ �� ������: ����� ����� ����� ������, � ������� ������ � �����
����� - ����
������
������ �� �����: 40 105 203 1 14 1000 22 33 44 55
������ �� ������: 105 203 1 1000

-----
������ 6. ���� ������
��� ������ �� 10 ���������. ����������, ����� ����� � ������� �����������
���� �����. �������������, ��� ����� ����� ����� 1.
������ �� �����: 10 ����� ����� ����� ������
������ �� ������: ���� �����, ������� ����������� ���� ������.
������
������ �� �����: 4 1 2 1 11 2 34 11 0 11
������ �� ������: 11

*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// 1. ������� �������������� �����
void task1()
{
    printf("������� � ����� 'task1.c'");
}

// 2. ������ � ���������� ������ �� 5 ���������, ����� ����������� �� ���.
int findMin(int arr[], int size)
{
    int min = arr[0]; // ������������, ��� ������ ������� �������� �����������

    // ���� ����������� �������, ��������� ������ ������� � ������� �����������
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

void task2()
{
    int arr[5]; // ������� ������ �� 5 ���������
    printf("������� 5 ����� ����� ����� ������: ");

    // ��������� ��������� ����� � ������
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    // ������� ����������� ������� � ������� �������
    int min = findMin(arr, 5);

    printf("����������� �������: %d\n", min);
}

// 3. ������� ������ �� 12 ��������� � ��������� ����������� ����� ������ �� 4 ��������.
void rightRotate(int arr[], int n, int k)
{
    // ������� ��������� ������ ��� ���������� ��������� k ���������
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        // ��������� ��������� k �������� �� ��������� ������
        temp[i] = arr[n - k + i];
    }
    // �������� �������� ������� �� k ������� ������
    for (int i = n - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }
    // ���������� ����������� �������� �� ���������� ������� � ������ �������
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

#define TASK3_ELEMENTS 4

void task3()
{
    int arr[12];

    printf("������� 12 ����� ����� ����� ������: ");
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &arr[i]);
    }

    rightRotate(arr, 12, TASK3_ELEMENTS);

    printf("������ ����� ������������ ������ ������ �� %d ��������:\n", TASK3_ELEMENTS);
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }
}

// 4. ������� ������ �� 10 ��������� � ������������� ��� �� ��������� �����.
void sortByLastDigit(int arr[], int size)
{
    // ��������� �������� ���������� ���������
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // �������� ��������� ����� �����
            int lastDigit1 = arr[j] % 10;
            int lastDigit2 = arr[j + 1] % 10;

            // ���� ��������� ����� � ��������� ����� ������,
            // ������ ������� �������� � �������
            if (lastDigit1 > lastDigit2)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void task4()
{
    int arr[10];

    // ������ ������ �� 10 ���������
    printf("������� 10 ����� �����: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    // ��������� ������ �� ��������� �����
    sortByLastDigit(arr, 10);

    // ������� ��������������� ������
    printf("��������������� ������: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}

// 5. ������� ������ �� 10 ��������� � �������� � ������ ������ ��� �����, � ������� ������ � ����� ����� (����� ��������) � ����.
void task5()
{
    int arr[10];                          // ������� ������ �� 10 ���������
    int n = sizeof(arr) / sizeof(arr[0]); // ���������� ������ �������

    // ��������� 10 ����� �� ������� ������
    printf("������� 10 ����� �����: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result[n]; // ������� ������ ��� �������� ���������� �����
    int count = 0; // ������� ���������� �����

    // �������� ����� � ������� ������ � ����� ����� - ����
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int tens = (num / 10) % 10; // ������� ������ � ����� �����

        if (tens == 0)
        {
            result[count] = num; // ��������� ����� � ����������
            count++;
        }
    }

    // ������� ���������� �����
    printf("result: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// 6. ��� ������ �� 10 ���������. ����������, ����� ����� � ������� ����������� ���� �����.
void task6()
{
    int arr[10];
    int frequency[20] = {0}; // ����� ������ ��� �������� ���������� ����� � �� ���������

    printf("������� 10 ����� ����� ����� ������: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);

        // ���������� �������� ����� ��� ��������, ���� �� ��� ����� � ����� �������
        int index = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == frequency[2 * j])
            {
                index = j;
                break;
            }
        }

        // ���� ����� ��� ����, ����������� ��� ������� � ����� �������
        // ����� ��������� ����� ����� � ����� ������
        if (index != -1)
        {
            frequency[2 * index + 1]++;
        }
        else
        {
            frequency[2 * i] = arr[i];
            frequency[2 * i + 1] = 1;
        }
    }

    // ������� ����� � ���������� ��������� � ����� �������
    int maxCount = frequency[1];
    int mostFrequentNum = frequency[0];

    for (int i = 3; i < 20; i += 2)
    {
        if (frequency[i] > maxCount)
        {
            maxCount = frequency[i];
            mostFrequentNum = frequency[i - 1];
        }
    }

    printf("�������� ����� ������������� �����: %d\n", mostFrequentNum);
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
        printf("1. ������� �������������� �����.\n");
        printf("2. ������ � ���������� ������ �� 5 ���������, ����� ����������� �� ���.\n");
        printf("3. ��������� ����������� ����� ������ �� 4 ��������.\n");
        printf("4. ������������� ��� �� ��������� �����.\n");
        printf("5. �������� � ������ ������ ��� �����, � ������� ������ � ����� ����� (����� ��������) � ����.\n");
        printf("6. ����������, ����� ����� � ������� ����������� ���� �����.\n");

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

        case 4:
            task4();
            break;

        case 5:
            task5();
            break;

        case 6:
            task6();
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