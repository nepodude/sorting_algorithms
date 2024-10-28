#include "sort.h"

/**
* print_char - prints a character.
* @c: character.
 */

void print_char(char c) {
    write(1, &c, 1);
}

/**
* print_string - prints string
* @str: string to print.
 */

void print_string(const char *str) {
    while (*str) {
        print_char(*str++);
    }
}

/**
* print_int - prints integer
* @n: integer to print.
 */

void print_int(int n) {
    if (n < 0) {
        print_char('-');
        n = -n;
    }
    if (n / 10) {
        print_int(n / 10);
    }
    print_char((n % 10) + '0');
}

/**
* my_printf - real printf function I'll use.
* @format: a formated string inside the "" to print.
 */

void my_printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) != '\0') {
            format++;
            if (*format == 'd') {
                int num = va_arg(args, int);
                print_int(num);
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                print_string(str);
            } else {
                print_char('%');
                print_char(*format);
            }
        } else {
            print_char(*format);
        }
        format++;
    }

    va_end(args);
}

