#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    int arr[15] = {4, 9, 21, 7, 22, 6, 1, 8, 5, 17, 11, 14, 13, 10, 12}; // ����������� ������
    int *result[2] = {&arr[0], &arr[1]};                              // ������ ���������� �� �������� ������������ �������
    int i;

    // ����� ��������� �������
    printf("����������� ������: ");
    for (i = 0; i < 15; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ������� ������������ ������� � 3-�� �������� � �� �����
    for (i = 2; i < 15; i++)
    {
        // ��������� �������� � ���������� ������� result
        if (arr[i] < *result[0] || arr[i] < *result[1])
        {
            // ����������� �������� �������� � ������
            if (*result[0] > *result[1])
                *result[0] = arr[i];
            else
                *result[1] = arr[i];
        }
    }

    // ����� ����������
    printf("����������� ��������: %d %d\n", *result[0], *result[1]);

    printf("����� result[0]: %x\n", (void *)&result[0]);
    printf("����� result[1]: %x\n", (void *)&result[1]);
    printf("����� ������������ ��������: %x\n", (void *)&arr[6]);

    return 0;
}