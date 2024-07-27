#include "main.h"
#include <stdio.h>

/**
 * print_string - Prints a string
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_string(va_list list, char *buffer, int *index, flags_t flags)
{
    char *str = va_arg(list, char *);
    int num_chars = 0;

    (void)flags; /* Flags are not used for strings */

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
