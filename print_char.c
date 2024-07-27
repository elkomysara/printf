#include "main.h"
#include <stdio.h>

/**
 * print_char - Prints a character
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_char(va_list list, char *buffer, int *index, flags_t flags)
{
    char c = va_arg(list, int);

    (void)flags; /* Flags are not used for characters */
    
    buffer[*index] = c;
    (*index)++;

    return (1);
}
