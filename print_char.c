#include "main.h"

/**
 * print_char - Prints a single character.
 * @args: Argument list.
 * 
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
    return (_putchar(va_arg(args, int)));
}
