
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

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
int print_int(va_list);
int print_unsigned(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_HEX(va_list);
int print_pointer(va_list);

#endif /* MAIN_H */



