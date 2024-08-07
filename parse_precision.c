#include "main.h"
#include <ctype.h>

/**
 * parse_precision - Parses the precision from the format string
 * @format: The format string
 * @i: Pointer to the current index in the format string
 * Return: The precision
 */
int parse_precision(const char *format, int *i)
{
    int precision = -1; /* Default precision is not set */

    if (format[*i] == '.')
    {
        (*i)++;
        precision = 0;
        while (isdigit(format[*i]))
        {
            precision = precision * 10 + (format[*i] - '0');
            (*i)++;
        }
    }

    return precision;
}
