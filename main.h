#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* Helper function prototypes */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);

#endif /* MAIN_H */

