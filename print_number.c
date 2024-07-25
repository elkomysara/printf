#include "main.h"

/**
 * print_number - Prints a number
 * @n: The number to print
 * Return: The number of characters printed
 */
int print_number(int n)
{
    int length = 0;
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        num = -n;
        length++;
    }
    else
    {
        num = n;
    }

    if (num / 10)
    {
        length += print_number(num / 10);
    }

    _putchar((num % 10) + '0');
    length++;

    return (length);
}


