/*
Задача 3. Изменить расширение
В файле in.txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
out.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.html
*/

#include "../func.h"

#define MAX_LENGTH 100

void task3()
{
// Открываем файлы для чтения и записи
    FILE *inFile = fopen("task_3/in.txt", "r");
    FILE *outFile = fopen("task_3/out.txt", "w");

    // Проверяем, успешно ли открыли файлы
    if (inFile == NULL || outFile == NULL) {
        printf("Ошибка открытия файлов\n");
        return;
    }

    // Считываем строку из файла
    char newName[MAX_LENGTH];
    fgets(newName, MAX_LENGTH, inFile);
    
    // char* oldName = (char*)malloc(strlen(newName) + 1);
    char* oldName = calloc(strlen(newName) + 1, sizeof(char));
    strcpy(oldName, newName);
    

    // Определяем позицию последней точки в строке (если нет точки, полагаем, что расширение не указано)
    char *dot = strrchr(newName, '.'); // функция возвращает указатель на ПОСЛЕДНЕЕ вхождение
    if (dot != NULL) {
        // Заменяем расширение на ".html"
        strcpy(dot, ".txt");
        // strncpy(dot, ".html", MAX_LENGTH - (dot - line));
    } else {
        // Добавляем расширение ".html" в конец строки
        strcat(newName, ".txt");
    }

    // Записываем новую строку в файл
    fprintf(outFile, "%s", newName);

    // Закрываем файлы
    fclose(inFile);
    fclose(outFile);

    printf("oldName: %s\n", oldName);
    printf("newName: %s\n", newName);

    // Используем функцию rename() для изменения имени файла
    int result = rename(oldName, newName);

    // Проверяем, успешно ли произошло переименование
    if (result == 0) {
        printf("Имя файла успешно изменено.\n");
    } else {
        perror("Ошибка при изменении имени файла");
    }

    free(oldName);
    printf("Задача выполнена");
}