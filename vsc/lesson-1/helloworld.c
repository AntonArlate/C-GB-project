/*
Задание 1. Вывести на экран “Hello world!”


Задание 2. Вывести на экран текст "лесенкой"
    Let’s
        go
            to walk

Задание 3. Вывести на экран рисунок из букв
   *
  ***
 *****
*******
 HH HH
 ZZZZZ

Задание 4*. Нарисовать соты
 __    __
/  \__/  \
\__/  \__/
/  \__/  \
\__/  \__/
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    printf("\n<<TASK 1>>\n\n");
    printf("Hellow world!\n");

    printf("\n<<TASK 2>>\n\n");
    const char *spaceL = "   ";
    printf("%sLet’s\n", spaceL);
    printf("%s%sgo\n", spaceL, spaceL);
    printf("%s%s%sto walk\n", spaceL, spaceL, spaceL);

    printf("\n<<TASK 3>>\n\n");
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf(" HH HH\n");
    printf(" ZZZZZ\n");

    printf("\n<<TASK 4>>\n\n");
    // const char *space = " ";
    const char *underline = "__";
    const char *right_slash = "/";
    const char *left_slash = "\\";

    int width = 5;
    int height = 4;
    int colum = width * 3 - 1;
    int row = height * 1 + 2;

    for (int current_row = 1; current_row <= row; current_row++) {
        for (int current_colum = 1; current_colum <= colum; current_colum += 6) {
            if (current_row % 2 == 1 && current_row != 1) {
                printf("%s", left_slash);
                printf("%s", underline);
                printf("%s", right_slash);
                printf("  "); 
            } else if (current_row == 1) {
                printf(" %s ", underline);
                printf("  "); 
            }

             if (current_row % 2 != 1) {
                printf("%s", right_slash);
                printf("  "); 
                printf("%s", left_slash);
                if (colum - current_colum >= 6){
                    printf("%s", underline);
                }
                if (current_row == row && colum - current_colum < 6 ) {
                    printf("\b \r ");
                }
            } 
        }
        printf("\n");
    }

    return 0;
}
