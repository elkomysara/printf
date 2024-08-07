#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_reverse - Prints a string in reverse
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting 
 * @width: Width for formatting
 * Return: Number of characters printed
 */

int print_reverse(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width, int precision)
{
    char *str = va_arg(list, char *);
    int len, i, num_chars = 0;

    (void)flags; /* Flags are not used for strings */
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

    for (i = len - 1; i >= 0; i--)
    {
        _putchar(str[i], buffer, index);
        num_chars++;
    }

    return (num_chars);
}
