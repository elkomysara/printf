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
    unsigned int n = va_arg(list, unsigned int);
    int num_chars = 0;
    char temp[50];
    int temp_index = 0;

    (void)flags; /* Flags are not used for unsigned integers */
    (void)length_mod;
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
