#include "main.h"
#include <stdio.h>


/**
 * print_rot13 - Prints a string in rot13 encoding
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * Return: Number of characters printed
 */
int print_rot13(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod)
{
    char *str = va_arg(list, char *);
    int i, j;

    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    (void)flags; /* Suppress unused parameter warning */
    (void)length_mod;
    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (str[i] == in[j])
            {
                _putchar(out[j], buffer, index);
                break;
            }
        }
        if (!in[j])
            _putchar(str[i], buffer, index);
    }

    return (i);
}
