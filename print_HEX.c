#include "main.h"
#include <stdio.h>

/**
 * print_HEX - Prints a number in hexadecimal (uppercase)
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @plus_flag: Flag for '+' character
 * @space_flag: Flag for ' ' character
 * @hash_flag: Flag for '#' character
 * Return: Number of characters printed
 */
int print_HEX(va_list list, char *buffer, int *index)
{
    unsigned int num = va_arg(list, unsigned int);
    int num_chars = 0;
    char *str;

    if (hash_flag && num != 0)
    {
        buffer[*index] = '0';
        buffer[*index + 1] = 'X';
        *index += 2;
        num_chars += 2;
    }

    str = convert(num, 16, 0);
    while (*str)
    {
        buffer[*index] = *str;
        (*index)++;
        str++;
        num_chars++;
    }

    return (num_chars);
}
