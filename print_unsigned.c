#include "main.h"

/**
* print_unsigned - Prints an unsigned integer
* @list: list of arguments
* Return: Will return the number of characters printed
*/
int print_unsigned(va_list list)
{
unsigned int num = va_arg(list, unsigned int);
char buffer[12];
int i = 0, len = 0;

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

return (len + i + 1);
}
