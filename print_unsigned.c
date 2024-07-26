#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @list: list of arguments
 * Return: The number of characters printed
 */
int print_unsigned(va_list list)
{
    unsigned int n = va_arg(list, unsigned int);
    char *str;
    int num_chars;

    str = convert(n, 10, 0);
    if (str == NULL)
        return (-1);

    num_chars = _puts(str);
    return (num_chars);
}
