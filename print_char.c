#include "main.h"
#include <stdio.h>

/**
 * print_char - Prints a character
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_char(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width, int precision)
{
    char c = va_arg(list, int);
    int i;

    (void)flags; /* Flags are not used for characters */
    (void)length_mod;
    (void)precision;

    if (width > 1)
    {
        for (i = 1; i < width; i++)
        {
            _putchar(' ', buffer, index);
        }
    }

    buffer[*index] = c;
    (*index)++;

    return (width > 1 ? width : 1);
}
