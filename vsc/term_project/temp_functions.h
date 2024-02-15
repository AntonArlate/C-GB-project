// Условная компиляция, которая якобы предотвращает повторную загрузку в течении одной компиляции
#ifndef LIBS_H // начало условия
#define LIBS_H // не совсем понял. Видимо по этому идентификатору компилятор проверяет был ли уже включён участок файла с данным названием

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#endif /* LIBS_H */ //конец условия

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} DataPoint;

// Общие функции main.c
void pressAnyKey(); // Ожидание нажатия клавиши

// Функции печати search_and_print_data.c
void printDataPoints(DataPoint* dataPoints, int lineCount); // Печать массива
void printDataByYear(DataPoint *dataPoints, int size, int year); // Печать за год
void printDataByMonth(DataPoint *dataPoints, int size, int year, int month); // Печать за месяц
void calculateStatistics(DataPoint *dataPoints, int start, int end); // Вывод запрошеных данных по ТЗ
void printAllYear (DataPoint *dataPoints, int start, int end);

// Функции поиска search_and_print_data.c
bool isValidFormat(char *str, int len);
bool isNumber(char *str);
int binarySearch(DataPoint *dataPoints, int left, int right, int year, int month);
void search(DataPoint *dataPoints, int size, int year, int month, int *start, int *end);

// Загрузка load_data.c
int readDataFromFile(const char *filename, DataPoint** dataPoints);
int parseLine(char *line, DataPoint *dataPoint); // Связаная с readDataFromFile()
void trim(char *str); // Связаная с parseLine()
