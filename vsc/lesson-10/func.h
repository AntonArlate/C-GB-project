// Условная компиляция, которая якобы предотвращает повторную загрузку в течении одной компиляции
#ifndef LIBS_H // начало условия
#define LIBS_H // не совсем понял. Видимо по этому идентификатору компилятор проверяет был ли уже включён участок файла с данным названием

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#endif /* LIBS_H */ //конец условия

// Общие функции
void printArray(int arr[], int size); // Печать массива
void pressAnyKey(); // Ожидание нажатия клавиши

// Вызов tasks
void task1();
void task2();
void task3();