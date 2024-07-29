#include "main.h"
#include <stdio.h>

/**
 * print_unsigned - Prints an unsigned integer
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * Return: Number of characters printed
 */
int print_unsigned(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    unsigned long int num;
      int num_chars = 0;
      char *str;

    if (length_mod.l)
        num = va_arg(list, unsigned long int);
    else if (length_mod.h)
        num = (unsigned short int)va_arg(list, unsigned int);
    else
        num = va_arg(list, unsigned int);

  
    str = convert(num, 10, 0);

    (void)flags; /* Flags are not used for unsigned integers */

    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
