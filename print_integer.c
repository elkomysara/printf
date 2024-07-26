#include "main.h"
#include <stdio.h>

/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * @buffer: buffer to store characters
 * @index: current index in the buffer
 * @plus_flag: flag for '+' character
 * @space_flag: flag for ' ' character
 * @hash_flag: flag for '#' character
 * Return: The number of characters printed
 */
int print_integer(va_list list, char *buffer, int *index, int plus_flag, int space_flag, int hash_flag)
{
    int n = va_arg(list, int);
    int num_chars = 0;
    char temp[50];
    int temp_index = 0;

    if (plus_flag && n >= 0)
    {
        buffer[*index] = '+';
        (*index)++;
        num_chars++;
    }
    else if (space_flag && n >= 0)
    {
        buffer[*index] = ' ';
        (*index)++;
        num_chars++;
    }

    if (n < 0)
    {
        buffer[*index] = '-';
        (*index)++;
        num_chars++;
        n = -n;
    }

    do {
        temp[temp_index++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    for (temp_index--; temp_index >= 0; temp_index--)
    {
        buffer[*index] = temp[temp_index];
        (*index)++;
        num_chars++;
    }

    return (num_chars);
}
