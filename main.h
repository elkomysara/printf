#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_char(char c, char *buffer, int *buff_ind);
int handle_string(char *str, char *buffer, int *buff_ind);
int handle_format(const char *format, va_list args, char *buffer, int *buff_ind);
int handle_int(int n, char *buffer, int *buff_ind);
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind);
int handle_octal(unsigned int n, char *buffer, int *buff_ind);
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind);
int handle_pointer(void *p, char *buffer, int *buff_ind);
int handle_binary(unsigned int n, char *buffer, int *buff_ind);
int handle_custom_string(char *str, char *buffer, int *buff_ind);
void buffer_flush(char *buffer, int *buff_ind);

#endif /* MAIN_H */









