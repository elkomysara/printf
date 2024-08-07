#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_pointer - Prints a pointer address
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_pointer(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width, int precision)
{
    void *ptr = va_arg(list, void *);
    unsigned long int addr = (unsigned long int)ptr;
    char hex[17];
    int i, digit, num_chars = 2; 

    (void)flags; /* Suppress unused parameter warning */
    (void)length_mod;
    (void)precision;

    _putchar('0', buffer, index);
    _putchar('x', buffer, index);

    i = 15;
    while (addr)
    {
        digit = addr % 16;
        hex[i--] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
        addr /= 16;
    }
    i++;
    while (i < 16)
    {
        _putchar(hex[i++], buffer, index);
        num_chars++;
    }

    /* Handle width */
    if (width > num_chars)
    {
        for (i = 0; i < width - num_chars; i++)
        {
            _putchar(' ', buffer, index);
            num_chars++;
        }
    }

    return num_chars;
}
