#include "main.h"

/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * Return: Will return the number of characters printed
 */
int print_integer(va_list list)
{
    int n = va_arg(list, int);
    int num_chars = 0;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }
    if (n < 0)
    {
        _putchar('-');
        num_chars++;
        n = -n;
    }
    num_chars += print_number(n);
    return (num_chars);
}

/**
 * print_number - Helper function to print an integer number
 * @n: The integer to print
 * Return: Number of characters printed
 */
int print_number(int n)
{
    int num_chars = 0;
    unsigned int num;

    if (n < 0)
        num = -n;
    else
        num = n;

    if (num / 10)
        num_chars += print_number(num / 10);

    _putchar((num % 10) + '0');
    num_chars++;

    return (num_chars);
}
