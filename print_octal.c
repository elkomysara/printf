#include "main.h"

/**
* print_octal - Prints an unsigned integer in octal notation.
* @list: List of arguments.
* @buffer: The buffer to store the formatted output.
* @index: The current index in the buffer.
*
* Return: The number of characters printed.
*/
int print_octal(va_list list, char *buffer, int *index)
{
unsigned int num = va_arg(list, unsigned int);
char buffer_temp[12];
int i = 0, len;

if (num == 0)
{
_putchar('0', buffer, index);
return (1);
}

while (num != 0)
{
buffer_temp[i++] = (num % 8) + '0';
num /= 8;
}

len = i;
while (i--)
{
_putchar(buffer_temp[i], buffer, index);
}

return (len);
}
