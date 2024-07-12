#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_char(char c);
int handle_string(char *str);
int handle_format(const char *format, va_list args);
int handle_int(int n);
int handle_unsigned(unsigned int n);
int handle_octal(unsigned int n);
int handle_hex(unsigned int n, int uppercase);
int handle_pointer(void *p);

#endif /* MAIN_H */




