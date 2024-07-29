#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/**
 * struct convert - struct for symbols and functions
 * @sym: The operator
 * @f: The function associated
 */
typedef struct convert
{
    char *sym;
    int (*f)(va_list, char *, int *, flags_t);
} conver_t;

int _printf(const char *format, ...);
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index);
int _putchar(char c, char *buffer, int *index);
char *convert(unsigned long int num, int base, int lowercase);
flags_t parse_flags(const char *format, int *i);

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(va_list l, char *buf, int *i, flags_t);
int print_string(va_list l, char *buf, int *i, flags_t);
int print_percent(va_list l, char *buf, int *i, flags_t);
int print_integer(va_list l, char *buf, int *i, flags_t);
int print_unsigned(va_list l, char *buf, int *i, flags_t);
int print_binary(va_list l, char *buf, int *i, flags_t);
int print_octal(va_list l, char *buf, int *i, flags_t);
int print_hex(va_list l, char *buf, int *i, flags_t);
int print_HEX(va_list l, char *buf, int *i, flags_t);
int print_pointer(va_list l, char *buf, int *i, flags_t);
int print_reverse(va_list l, char *buf, int *i, flags_t);
int print_rot13(va_list l, char *buf, int *i, flags_t);
int print_non_printable(va_list l, char *buf, int *i, flags_t);
int print_special_string(va_list, char *, int *, flags_t);

#endif /* MAIN_H */
