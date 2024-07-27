#include "main.h"
#include <stdio.h>

/**
 * print_non_printable - Prints non-printable characters in hexadecimal format
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_non_printable(va_list list, char *buffer, int *index, flags_t flags)
{
    char *str = va_arg(list, char *);
    int i = 0, count = 0;

    (void)flags; /* Suppress unused parameter warning */

    while (str[i])
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            count += sprintf(&buffer[*index], "\\x%02X", str[i]);
            *index += 4;
        }
        else
        {
            _putchar(str[i], buffer, index);
            count++;
        }
        i++;
    }

    return (count);
}
