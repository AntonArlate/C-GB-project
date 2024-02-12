// Условная компиляция, которая якобы предотвращает повторную загрузку в течении одной компиляции
#ifndef LIBS_H // начало условия
#define LIBS_H // не совсем понял. Видимо по этому идентификатору компилятор проверяет был ли уже включён участок файла с данным названием

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#endif /* LIBS_H */ //конец условия

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} DataPoint;

// Общие функции
void pressAnyKey(); // Ожидание нажатия клавиши
bool isValidFormat(char *str, int len);
bool isNumber(char *str);
int binarySearch(DataPoint *dataPoints, int left, int right, int year, int month);

// Функции печати
void printDataPoints(DataPoint* dataPoints, int lineCount); // Печать массива
void printDataByYear(DataPoint *dataPoints, int size, int year); // Печать за год
void printDataByMonth(DataPoint *dataPoints, int size, int year, int month); // Печать за месяц

// Вызов

int readDataFromFile(const char *filename, DataPoint** dataPoints);
int parseLine(char *line, DataPoint *dataPoint);
