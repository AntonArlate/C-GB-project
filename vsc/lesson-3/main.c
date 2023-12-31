/*
������ 1. ���������� �� ���� �����
������ ���� ����� � ������� ���������� �� ���
����� ���������� ���������� �����
������ �� �����: ���� ����� ����� ����������� ��������
������ �� ������: ���� ����� �����
������ �� �����: 4 15 9 56 4
������ �� ������: 56
-----
������ 2. ���������� �� ���� �����
������ ���� ����� � ������� ���������� �� ���
����� ���������� ���������� �����
������ �� �����: ���� ����� ����� ����������� ��������
������ �� ������: ���� ����� �����
������ �� �����: 4 15 9 56 4
������ �� ������: 4
-----
������ 3. � ������� �����������
������ ��� ����� � ����������, ����� ��, ��� ��� ��������� � �������
�����������.
������ �� �����: ��� ����� �����
������ �� ������: ���� ����� YES ��� NO
������
������ �� �����: 4 5 17
������ �� ������: YES
-----
������ 4. ����� ����� ����
������ ����� ������ � ������� �������� ������� ����.
������ �� �����: ����� ����� �� 1 �� 12 - ����� ������.
������ �� ������: ����� ���� �� ����������: winter, spring, summer, autumn
������ �1
������ �� �����: 4
������ �� ������: spring
������ �2
������ �� �����: 1
������ �� ������: winter

*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// 1. ������ ���� ����� � ������� ���������� �� ���
void task1()
{
    int a, b, c, d, e;
    int max;

    printf("������� ���� ����� �����, ����������� ��������: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // ������� ������������ �����
    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    if (d > max)
    {
        max = d;
    }
    if (e > max)
    {
        max = e;
    }

    printf("���������� �����: %d\n", max);
}

// 2. ������ ���� ����� � ������� ���������� �� ���
void task2()
{
    int a, b, c, d, e;
    int min;

    printf("������� ���� ����� �����, ����������� ��������: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // ������� ����������� �����
    min = INT_MAX;
    if (a < min)
    {
        min = b;
    }
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    if (d < min)
    {
        min = d;
    }
    if (e < min)
    {
        min = e;
    }

    printf("���������� �����: %d\n", min);
}

// 3. ������ ��� ����� � ����������, ����� ��, ��� ��� ��������� � ������� �����������.
void task3()
{
    int a, b, c;

    printf("������� ��� �����: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

// 4. ������ ����� ������ � ������� �������� ������� ����.
void task4()
{
    int month;

    printf("������� ����� ������: ");
    scanf("%d", &month);

    if (month == 12 || month == 1 || month == 2)
    {
        printf("winter\n");
    }
    else if (month >= 3 && month <= 5)
    {
        printf("spring\n");
    }
    else if (month >= 6 && month <= 8)
    {
        printf("summer\n");
    }
    else if (month >= 9 && month <= 11)
    {
        printf("autumn\n");
    }
    else
    {
        printf("������������ ����� ������\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int choice;
    int exit = 0;

    while (!exit)
    {
        printf("\n-----------------------------\n");
        printf("1. ������ ���� ����� � ������� ���������� �� ���\n");
        printf("2. ������ ���� ����� � ������� ���������� �� ���\n");
        printf("3. ������ ��� ����� � ����������, ����� ��, ��� ��� ��������� � ������� �����������.\n");
        printf("4. ������ ����� ������ � ������� �������� ������� ����.\n");

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

        default:
            exit = 1;
            printf("END\n");
        }
    }

    return 0;
}
