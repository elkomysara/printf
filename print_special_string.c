#include "main.h"
#include <stdio.h>  

/**
 * print_special_string - Prints a string, replacing non-printable characters
 * @list: list of arguments
 * @buffer: buffer to store the result
 * @index: current index in the buffer
 * Return: The number of characters printed
 */
int print_special_string(va_list list, char *buffer, int *index)
{
    char *str = va_arg(list, char *);
    int i, count = 0;
    char hex[3];

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            _putchar('\\', buffer, index);
            _putchar('x', buffer, index);
            count += 2;

            sprintf(hex, "%02X", (unsigned char)str[i]);
            _putchar(hex[0], buffer, index);
            _putchar(hex[1], buffer, index);
            count += 2;
        }
        else
        {
            _putchar(str[i], buffer, index);
            count++;
        }
    }

    return (count);
}
