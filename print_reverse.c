#include "main.h"
#include <stdio.h>

/**
 * print_reverse - Prints a string in reverse
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting 
 * Return: Number of characters printed
 */

int print_reverse(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    char *str = va_arg(list, char *);
    int len = 0, i;

    (void)flags; /* Suppress unused parameter warning */
    (void)length_mod;
    while (str[len])
        len++;

    for (i = len - 1; i >= 0; i--)
        _putchar(str[i], buffer, index);

    return (len);
}

