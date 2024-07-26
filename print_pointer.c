#include "main.h"
#include <stdio.h>

/**
 * print_pointer - Prints a pointer address
 * @list: list of arguments
 * @buffer: buffer to store characters
 * @index: current index in the buffer
 * Return: The number of characters printed
 */
int print_pointer(va_list list, char *buffer, int *index)
{
    void *ptr = va_arg(list, void *);
    unsigned long int addr = (unsigned long int)ptr;
    char *hex_str;
    int num_chars = 0;

    if (ptr == NULL)
    {
        return (_puts("(nil)", buffer, index));
    }

    _puts("0x", buffer, index);
    num_chars += 2;

    hex_str = convert(addr, 16, 1);
    num_chars += _puts(hex_str, buffer, index);

    return (num_chars);
}
