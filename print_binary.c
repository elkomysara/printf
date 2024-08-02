#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_binary - Prints a number in binary
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_binary(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str = convert(num, 2, 0);

    (void)flags; /* Flags are not used for binary */
    (void)length_mod;
    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

     if (width > (int)strlen(str))  
    {
        int i;
        for (i = 0; i < width - (int)strlen(str); i++)  
        {
            _putchar(' ', buffer, index);
        }
    }

    return (num_chars);
}
