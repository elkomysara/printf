#include "main.h"

/**
* print_HEX - Prints an unsigned integer in hexadecimal notation (uppercase).
* @list: List of arguments.
* @buffer: The buffer to store the formatted output.
* @index: The current index in the buffer.
*
* Return: The number of characters printed.
*/
int print_HEX(va_list list, char *buffer, int *index)
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
buffer_temp[i++] = (num % 16) + (num % 16 < 10 ? '0' : 'A' - 10);
num /= 16;
}

len = i;
while (i--)
{
_putchar(buffer_temp[i], buffer, index);
}

return (len);
}
