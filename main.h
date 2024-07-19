#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct convert - defines a structure for symbols and functions
 *
 * @sym: The symbol (format specifier)
 * @f: The function associated with the symbol
 */
struct convert
{
    char *sym;
    int (*f)(va_list);
};
typedef struct convert conver_t;

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int format_reciever(const char *format, conver_t f_list[], va_list arg_list);
int print_percent(va_list args);
int print_char(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */
