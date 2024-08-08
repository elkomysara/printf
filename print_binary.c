#include "main.h"
#include <stdarg.h>

/**
* print_binary - Converts an unsigned int to binary
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the number of characters printed
*/
int print_binary(va_list list, char *buffer, int *index)
{
unsigned int num = va_arg(list, unsigned int);
char bin_str[32];
int i = 0, len = 0;

if (num == 0)
{
_putchar('0', buffer, index);
return (1);
}

while (num != 0)
{
bin_str[i++] = (num % 2) + '0';
num /= 2;
}

while (i--)
{
_putchar(bin_str[i], buffer, index);
len++;
}

return (len);
}
