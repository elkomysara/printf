#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  /* for va_list */

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_format(const char *format, int *i, va_list args, char *buffer, int *buff_ind);
int handle_char(char c, char *buffer, int *buff_ind);
int handle_string(char *s, char *buffer, int *buff_ind);
int handle_int(int n, char *buffer, int *buff_ind, int flags);
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind, int flags);
int handle_octal(unsigned int n, char *buffer, int *buff_ind, int flags);
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind, int flags);
int handle_pointer(void *p, char *buffer, int *buff_ind, int flags);
void buffer_flush(char *buffer, int *buff_ind);

/* Define flag constants */
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4

#endif /* MAIN_H */










