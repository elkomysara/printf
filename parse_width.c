#include "main.h"
#include <ctype.h>

/**
 * parse_width - Parses the width from the format string
 * @format: The format string
 * @i: Pointer to the current index in the format string
 * @arg_list: The list of arguments
 * Return: The width
 */
int parse_width(const char *format, int *i, va_list arg_list)
{
    int width = 0;

    if (isdigit(format[*i]))
    {
        while (isdigit(format[*i]))
        {
            width = width * 10 + (format[*i] - '0');
            (*i)++;
        }
    }
    else if (format[*i] == '*')
    {
        width = va_arg(arg_list, int);
        (*i)++;
    }

    return (width);
}
