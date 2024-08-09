
#include "main.h"
#include <stdarg.h>

/**
* print_pointer - Prints a pointer address
* @list: list of arguments
* Return: Will return the number of characters printed
*/
int print_pointer(va_list list)
{
unsigned long int addr = (unsigned long int)va_arg(list, void *);
char buffer[17];
int i = 0, len = 0;

if (addr == 0)
{
_putchar('(');
_putchar('n');
_putchar('i');
_putchar('l');
_putchar(')');
return (5);
}

while (addr != 0)
{
buffer[i++] = (addr % 16) + (addr % 16 < 10 ? '0' : 'a' - 10);
addr /= 16;
}

_putchar('0');
_putchar('x');
len += 2;

while (i--)
_putchar(buffer[i]);

return (len + i);
}
