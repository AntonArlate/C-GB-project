/*
Задача 2. Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо
заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
строчные. Результат записать в .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов.
Данные на выходе: Строка из маленьких и больших английских
букв, знаков препинания и пробелов.
Пример
Данные на входе: aabbccddABCD
Данные на выходе: bbaaccddBACD
*/

#include <locale.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main()
{
    setlocale(LC_ALL, "Rus");
    
    FILE *inputFile = fopen("in.txt", "r");
    FILE *outputFile = fopen("out.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Ошибка при открытии файлов!\n");
        return 1;
    }

    char line[MAX_LENGTH + 1];
    if (fgets(line, (MAX_LENGTH + 1), inputFile) == NULL)
    {
        printf("Ошибка при чтении строки из файла!\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == 'a' || line[i] == 'A')
        {
            line[i] = (line[i] == 'a') ? 'b' : 'B';
        }
        else if (line[i] == 'b' || line[i] == 'B')
        {
            line[i] = (line[i] == 'b') ? 'a' : 'A';
        }
    }

    fputs(line, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}