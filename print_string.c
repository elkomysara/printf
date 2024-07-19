#include "main.h"

/**
 * print_string - Prints a string.
 * @args: Argument list.
 * 
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        _putchar(*str++);
        count++;
    }
    return (count);
}
