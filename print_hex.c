#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_hex - Prints a number in hexadecimal (lowercase)
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_hex(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width, int precision)
{
    unsigned long int num;
    char *str;
    int num_chars = 0, len, i;

     (void)precision;
    if (length_mod.l)
        num = va_arg(list, unsigned long int);
    else if (length_mod.h)
        num = (unsigned short int)va_arg(list, unsigned int);
    else
        num = va_arg(list,unsigned int);

    str = convert(num, 16, 1); 
    len = strlen(str);

    if (flags.hash && num != 0)
    {
      _putchar('0', buffer, index);
      _putchar('x', buffer, index);
      num_chars += 2;
     if (width > 0)
        width -= 2;
    }


    if (width > (int)strlen(str)) 
    {
        
        for (i = 0; i < width - len; i++)
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

    return (num_chars);
}
