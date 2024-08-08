#include "main.h"
#include <stdarg.h>

/**
* print_hex - Prints an unsigned integer in hexadecimal notation (lowercase)
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the number of characters printed
*/
int print_hex(va_list list, char *buffer, int *index)
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
temp[i++] = (num % 16) + (num % 16 < 10 ? '0' : 'a' - 10);
num /= 16;
}

while (i--)
_putchar(temp[i], buffer, index);

return (len + i);
}
