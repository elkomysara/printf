#include "main.h"
#include <stdio.h>

/**
 * print_char - Prints a character
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @plus_flag: Flag for '+' character
 * @space_flag: Flag for ' ' character
 * @hash_flag: Flag for '#' character
 * Return: Number of characters printed
 */
int print_char(va_list list, char *buffer, int *index, int plus_flag, int space_flag, int hash_flag)
{
    char c = va_arg(list, int);

    buffer[*index] = c;
    (*index)++;

    return (1);
}
