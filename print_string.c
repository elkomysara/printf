#include "main.h"
#include <stdio.h>

/**
 * print_string - Prints a string
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_string(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width)
{
    char *str = va_arg(list, char *);
    int len, i, num_chars = 0;

    (void)flags; /* Flags are not used for strings */
    (void)length_mod;

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
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
