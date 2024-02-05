// ������ 1. ���������� �� �����������
// �������� ������ ���� �������, ������� ��������� ������ �� �����������.
// ���������� ����������� ������ ���� �������, ��� ��������� ���������� ��
// ����.
// ������ �������� ���������. ��� ������� � ��� ��������� ������ ����:
// void sort_array(int size, int a[])
// ��� ��������� ��������� �� ����, ������ ���� ��� �������. ����� ������
// ���������������� ����� ���� ���������, ����� ������ �������.
// ������ �� �����: ������� ��������� �� ����, ������ �������� - ������
// �������, ������ �������� - ����� �������� ��������.
// ������ �� ������: ������� ������ �� ����������. ����������
// ���������� ����������� �� ������� �� �����������.
// ������ �1
// ������ �� �����: 20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
// ������ �� ������: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// ������ �2
// ������ �� �����: 5 4 3 2 1
// ������ �� ������: 1 2 3 4 5

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// ������ �������
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������� ��� ������ ����������
// ���������� ���������� ����������
void swap(int *a, int *b)
{
    int temp = *a; // �������������� ��������� � ���������� ��������
    *a = *b;       // ����� �������� ������ � ��������� ��������� �� ����� ���������� � ������� b � �������� � ������� a
    *b = temp;
}

// ������� ��� ���������� ������� � �������� ������� �������� ��������
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // �������� ��������� ������� � �������� �������� ��������
    int i = (low - 1);     // ������ �������� ��������

    for (int j = low; j <= high - 1; j++)
    {
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // ����� ������� ����� �������� ��� ������ pvot ����� �� i ��������� ������
    // ������ ���� pivot ��������� ��� ����� �� �������� ������ ���������
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // ���������� ������� ������ pivot
}

// ������� ������� ����������
void quickSort(int arr[], int low, int high)
{
    if (low < high) // ������� ������ �� ��������
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ������� ����� �������� ������
void sort_array(int size, int a[])
{
    quickSort(a, 0, size - 1);
}

// MAIN
int main()
{
    setlocale(LC_ALL, "Rus");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("�������� ������: \n");
    printArray(arr, n);

    sort_array(n, arr);

    printf("������ ����� ����������: \n");
    printArray(arr, n);

    printf("---------------------\n");

    int arr2[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("�������� ������: \n");
    printArray(arr2, n);

    sort_array(n, arr2);

    printf("������ ����� ����������: \n");
    printArray(arr2, n);

    return 0;
}