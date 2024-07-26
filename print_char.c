#include "main.h"

int print_char(va_list list, char *buffer, int *index)
{
    _putchar(va_arg(list, int), buffer, index);
    return (1);
}

