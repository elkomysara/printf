#include "main.h"
#include <stdio.h>

/**
 * print_hex - Prints a number in hexadecimal (lowercase)
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @plus_flag: Flag for '+' character
 * @space_flag: Flag for ' ' character
 * @hash_flag: Flag for '#' character
 * Return: Number of characters printed
 */
int print_hex(va_list list, char *buffer, int *index, int plus_flag, int space_flag, int hash_flag)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str;

    if (hash_flag && num != 0)
    {
        buffer[*index] = '0';
        buffer[*index + 1] = 'x';
        *index += 2;
        num_chars += 2;
    }

    str = convert(num, 16, 1);
    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
