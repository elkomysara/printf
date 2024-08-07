#include "main.h"
#include <stdio.h>

/**
 * print_percent - Prints a percent symbol
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * @precision: precision handling 
 * Return: Number of characters printed
 */
int print_percent(va_list list, char *buffer, int *index, flags_t flags,length_mod_t length_mod, int width, int precision)
{
    (void)list;
    (void)flags; /* Flags are not used for percent */
    (void)length_mod; 
    (void)precision;


  if (width > 1)  
    {
        int i;
        for (i = 0; i < width - 1; i++)  
        {
            _putchar(' ', buffer, index);
        }
    }
    buffer[*index] = '%';
    (*index)++;

  return (width > 1 ? width : 1);
}
