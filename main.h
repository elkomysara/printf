#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
* @sym: The operator
* @f: The function associated
*/
struct convert
{
char *sym;
int (*f)(va_list, char *, int *);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int _putchar(char c, char *buffer, int *index);
int _puts(char *str, char *buffer, int *index);
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index);
int print_percent(va_list, char *buffer, int *index);
int print_char(va_list, char *buffer, int *index);
int print_string(va_list, char *buffer, int *index);
int print_int(va_list, char *buffer, int *index);
int print_binary(va_list, char *buffer, int *index);
char *convert_to_binary(unsigned int num);
int print_unsigned(va_list, char *buffer, int *index);
int print_octal(va_list, char *buffer, int *index);
int print_hex(va_list, char *buffer, int *index);
int print_HEX(va_list, char *buffer, int *index);

#endif /* MAIN_H */
