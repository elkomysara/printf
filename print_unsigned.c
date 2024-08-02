#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_unsigned - Prints an unsigned integer
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_unsigned(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width)
{
    unsigned long int num;
    int num_chars = 0;
    char *str;

    (void)flags; /* Suppress unused parameter warning */
    (void)width; /* Suppress unused parameter warning */

    if (length_mod.l)
        num = va_arg(list, unsigned long int);
    else if (length_mod.h)
        num = (unsigned short int)va_arg(list, unsigned int);
    else
        num = va_arg(list, unsigned int);

    str = convert(num, 10, 0);

    if (width > (int)strlen(str))  
    {
        int i;
        for (i = 0; i < width - (int)strlen(str); i++)  
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

    return num_chars;
}
