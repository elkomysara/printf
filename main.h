#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct converter {
    char *specifier;
    int (*f)(va_list, char *, int *);
} conver_t;

int _printf(const char *format, ...);
int _putchar(char c, char *buffer, int *index);
int _puts(char *str, char *buffer, int *index);
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index);
int print_char(va_list list, char *buffer, int *index);
int print_string(va_list list, char *buffer, int *index);
int print_percent(va_list list, char *buffer, int *index);
int print_integer(va_list list, char *buffer, int *index);
int print_number(int n, char *buffer, int *index);
int print_binary(va_list list, char *buffer, int *index);
int print_unsigned(va_list list, char *buffer, int *index);
int print_octal(va_list list, char *buffer, int *index);
int print_hex(va_list list, char *buffer, int *index);
int print_HEX(va_list list, char *buffer, int *index);
int print_special_string(va_list list, char *buffer, int *index);
char *convert(unsigned long int num, int base, int lowercase);
int print_pointer(va_list list, char *buffer, int *index);

#endif /* MAIN_H */
