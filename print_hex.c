#include "main.h"
#include <stdio.h>

/**
 * print_hex - Prints a number in hexadecimal (lowercase)
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_hex(va_list list, char *buffer, int *index, flags_t flags)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str;

    if (flags.hash && num != 0)
    {
        buffer[*index] = '0';
        buffer[*index + 1] = 'x';
        *index += 2;
        num_chars += 2;
    }

    str = convert(num, 16, 1);
    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
