#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    int arr[15] = {4, 9, 21, 7, 22, 6, 1, 8, 5, 17, 11, 14, 13, 10, 12}; // исследуемый массив
    int *result[2] = {&arr[0], &arr[1]};                              // массив указателей на значения исследуемого массива
    int i;

    // Вывод исходного массива
    printf("Исследуемый массив: ");
    for (i = 0; i < 15; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Перебор исследуемого массива с 3-го элемента и до конца
    for (i = 2; i < 15; i++)
    {
        // Сравнение значения с элементами массива result
        if (arr[i] < *result[0] || arr[i] < *result[1])
        {
            // Определение большего значения и замена
            if (*result[0] > *result[1])
                *result[0] = arr[i];
            else
                *result[1] = arr[i];
        }
    }

    // Вывод результата
    printf("Минимальные значения: %d %d\n", *result[0], *result[1]);

    printf("Адрес result[0]: %x\n", (void *)&result[0]);
    printf("Адрес result[1]: %x\n", (void *)&result[1]);
    printf("Адрес минимального значения: %x\n", (void *)&arr[6]);

    return 0;
}