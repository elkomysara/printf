#include "main.h"

int print_integer(va_list list, char *buffer, int *index)
{
    int n = va_arg(list, int);
    int num_chars = 0;

    if (n == 0)
    {
        _putchar('0', buffer, index);
        return (1);
    }

    if (n < 0)
    {
        _putchar('-', buffer, index);
        num_chars++;
        n = -n;
    }

    num_chars += print_number(n, buffer, index);

    return (num_chars);
}

int print_number(int n, char *buffer, int *index)
{
    int num_chars = 0;
    unsigned int num = n;

    if (num / 10)
        num_chars += print_number(num / 10, buffer, index);

    _putchar((num % 10) + '0', buffer, index);
    num_chars++;

    return (num_chars);
}
