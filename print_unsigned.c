#include "main.h"
#include <stdarg.h>

/**
* print_unsigned - Prints an unsigned integer
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the number of characters printed
*/

int print_unsigned(va_list list, char *buffer, int *index)
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
temp[i++] = (num % 10) + '0';
num /= 10;
}

while (i--)
_putchar(temp[i], buffer, index);

return (len + i);
}
