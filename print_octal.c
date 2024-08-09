
#include "main.h"

/**
* print_octal - Prints an unsigned integer in octal notation
* @list: list of arguments
* Return: Will return the number of characters printed
*/

int print_octal(va_list list)
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
buffer[i++] = (num % 8) + '0';
num /= 8;
}

while (i--)
_putchar(buffer[i]);

return (len + i);
}
