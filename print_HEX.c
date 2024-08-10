#include "main.h"

/**
* print_HEX - Prints an unsigned integer in hexadecimal notation (uppercase)
* @list: list of arguments
* Return: Will return the number of characters printed
*/
int print_HEX(va_list list)
{
unsigned int num = va_arg(list, unsigned int);
char buffer[12];
int i = 0;
int len;
if (num == 0)
{
_putchar('0');
return (1);
}

while (num != 0)
{
buffer[i++] = (num % 16) + (num % 16 < 10 ? '0' : 'A' - 10);
num /= 16;
}

len = i;

while (i--)
_putchar(buffer[i]);

return (len);
}
