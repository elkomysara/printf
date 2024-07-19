#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_format(const char *format, va_list args);

#endif /* MAIN_H */
