#include "main.h"
#include <stdio.h>

/**
 * print_special_string - Prints a string and converts non-printable
 * characters to their hexadecimal representation.
 * @list: list of arguments
 * @buffer: buffer to store the result
 * @index: current index in the buffer
 * Return: The number of characters printed
 */
int print_special_string(va_list list, char *buffer, int *index)
{
    char *str = va_arg(list, char *);
    char hex[5];
    int i, j, num_chars = 0;

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            sprintf(hex, "\\x%02X", (unsigned char)str[i]);
            for (j = 0; hex[j] != '\0'; j++)
            {
                _putchar(hex[j], buffer, index);
                num_chars++;
            }
        }
        else
        {
            _putchar(str[i], buffer, index);
            num_chars++;
        }
    }
    return (num_chars);
}
