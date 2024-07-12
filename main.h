#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_char(char c);
int handle_string(char *str);
int handle_format(const char *format, va_list args);
int handle_int(int n);

#endif /* MAIN_H */





