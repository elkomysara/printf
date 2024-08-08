#include "main.h"

/**
* print_octal - Prints an unsigned integer in octal notation
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the number of characters printed
*/

int print_octal(va_list list, char *buffer, int *index)
{
unsigned int num = va_arg(list, unsigned int);
char temp[12];
int i = 0, len = 0;

if (num == 0)
{
_putchar('0', buffer, index);
return (1);
}

while (num != 0)
{
temp[i++] = (num % 8) + '0';
num /= 8;
}

while (i--)
_putchar(temp[i], buffer, index);

return (len + i);
}
