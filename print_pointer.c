#include "main.h"
#include <stdarg.h>

/**
* print_pointer - Prints a pointer address
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the number of characters printed
*/
int print_pointer(va_list list, char *buffer, int *index)
{
unsigned long int addr = (unsigned long int)va_arg(list, void *);
char temp[17];
int i = 0, len = 0;

if (addr == 0)
{
_putchar('(', buffer, index);
_putchar('n', buffer, index);
_putchar('i', buffer, index);
_putchar('l', buffer, index);
_putchar(')', buffer, index);
return (5);
}

while (addr != 0)
{
temp[i++] = (addr % 16) + (addr % 16 < 10 ? '0' : 'a' - 10);
addr /= 16;
}

_putchar('0', buffer, index);
_putchar('x', buffer, index);
len += 2;

while (i--)
_putchar(temp[i], buffer, index);

return (len + i);
}
