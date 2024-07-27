#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints a number in binary
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_binary(va_list list, char *buffer, int *index, flags_t flags)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str = convert(num, 2, 0);

    (void)flags; /* Flags are not used for binary */

    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
