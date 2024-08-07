#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_non_printable - Prints a string with non-printable characters in hex
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_non_printable(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width, int precision)
{
    char *str = va_arg(list, char *);
    char hex[5];
    int len, i, num_chars = 0;

    (void)flags; /* Flags are not used for non-printable characters */
    (void)length_mod;
     (void)precision;

    if (str == NULL)
        str = "(null)";

    len = strlen(str);

    if (width > len)
    {
        for (i = 0; i < width - len; i++)
        {
            _putchar(' ', buffer, index);
            num_chars++;
        }
    }

    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            sprintf(hex, "\\x%02X", (unsigned char)*str);
            for (i = 0; hex[i]; i++)
            {
                buffer[*index] = hex[i];
                (*index)++;
                num_chars++;
            }
        }
        else
        {
            buffer[*index] = *str;
            (*index)++;
            num_chars++;
        }
        str++;
    }

    return (num_chars);
}
