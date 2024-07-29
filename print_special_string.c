#include "main.h"
#include <stdio.h>

/**
 * print_special_string - Prints a special string with non-printable characters
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * Return: Number of characters printed
 */
int print_special_string(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    char *str = va_arg(list, char *);
    int i = 0, count = 0;

    (void)flags; /* Suppress unused parameter warning */
    (void)length_mod;
    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            count += sprintf(&buffer[*index], "\\x%02X", (unsigned char)str[i]);
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

