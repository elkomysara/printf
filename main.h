#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define NUL '\0'

/**
 * struct convert - defines a structure for symbols and functions
 * @sym: The operator
 * @f: The function associated
 */
struct convert
{
    char *sym;
    int (*f)(va_list);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int _putchar(char c);
int format_reciever(const char *format, conver_t f_list[], va_list arg_list);
int print_percent(va_list);
int print_char(va_list);
int print_string(va_list);
int print_integer(va_list);
int print_number(int n);
int print_binary(va_list list);
char *convert(unsigned long int num, int base, int lowercase);
int _puts(char *str);
#endif /* MAIN_H */


