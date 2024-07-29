#include "main.h"
#include <stdio.h>

/**
 * print_octal - Prints a number in octal
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * Return: Number of characters printed
 */
int print_octal(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str;

    if (length_mod.l)
        num = va_arg(list, long int);
    else if (length_mod.h)
        num = (short int)va_arg(list, int);
    else
        num = va_arg(list, int);

    if (flags.hash && num != 0)
    {
        buffer[*index] = '0';
        (*index)++;
        num_chars++;
    }

    str = convert(num, 8, 0);
    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
