#include "main.h"
#include <stdio.h>

/**
 * print_pointer - Prints a pointer address
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_pointer(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    void *ptr = va_arg(list, void *);
    unsigned long int addr = (unsigned long int)ptr;
    char hex[17];
    int i, digit;

    (void)flags; /* Suppress unused parameter warning */
    (void)length_mod;
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
    }

    return (2 + 15 - i);
}
