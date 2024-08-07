#include "main.h"
#include <stdarg.h>

/**
* print_int - Prints an integer
* @list: list of arguments
* Return: Will return the number of characters printed
*/
int print_int(va_list list)
{
int num = va_arg(list, int);
char buffer[12];
int i = 0, len = 0, negative = 0;

if (num < 0)
{
_putchar('-');
num = -num;
negative = 1;
len++;
}

if (num == 0)
{
_putchar('0');
return (1);
}

while (num != 0)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}

while (i--)
_putchar(buffer[i]);

return (len + i + negative);
}
