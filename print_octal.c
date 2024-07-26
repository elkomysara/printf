#include "main.h"

/**
 * print_octal - Prints a number in octal base
 * @list: list of arguments
 * Return: The number of characters printed
 */
int print_octal(va_list list)
{
    unsigned int n = va_arg(list, unsigned int);
    char *str;
    int num_chars;

    str = convert(n, 8, 0);
    if (str == NULL)
        return (-1);

    num_chars = _puts(str);
    return (num_chars);
}

