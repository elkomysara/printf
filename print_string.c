#include "main.h"

int print_string(va_list list, char *buffer, int *index)
{
    char *str = va_arg(list, char *);

    if (str == NULL)
        str = "(null)";

    return (_puts(str, buffer, index));
}

