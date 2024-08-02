#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_rot13 - Encodes a string using rot13 and prints it
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_rot13(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width)
{
    char *str = va_arg(list, char *);
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    int len, i, j, num_chars = 0;

    (void)flags; /* Flags are not used for rot13 */
    (void)length_mod;

    if (str == NULL)
        str = "(null)";

    len = strlen(str);

    if (width > len)
    {
        for (i = 0; i < width - len; i++)
        {
            _putchar(' ', buffer, index);
            num_chars++;
        }
    }

    while (*str)
    {
        for (j = 0; j < 52; j++)
        {
            if (*str == in[j])
            {
                buffer[*index] = out[j];
                (*index)++;
                num_chars++;
                break;
            }
        }
        if (j == 52)
        {
            buffer[*index] = *str;
            (*index)++;
            num_chars++;
        }
        str++;
    }

    return (num_chars);
}
