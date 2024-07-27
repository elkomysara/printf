#include "main.h"
#include <stdio.h>

/**
 * print_percent - Prints a percent symbol
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_percent(va_list list, char *buffer, int *index, flags_t flags)
{
    (void)list;
    (void)flags; /* Flags are not used for percent */

    buffer[*index] = '%';
    (*index)++;

    return (1);
}
