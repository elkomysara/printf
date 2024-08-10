#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
* print_int - Prints an integer.
* @list: List of arguments.
* @buffer: The buffer to store the formatted output.
* @index: The current index in the buffer.
*
* Return: The number of characters printed.
*/
int print_int(va_list list, char *buffer, int *index)
{
int num = va_arg(list, int);
char buffer_temp[12];
int i = 0, len = 0, negative = 0;

if (num == INT_MIN)
{
_putchar('-', buffer, index);
_putchar('2', buffer, index);
num = 147483648; /* INT_MIN = -2147483648, so we need to handle 147483648 */
negative = 2; /*  Count '-' and '2' */
}
else if (num < 0)
{
_putchar('-', buffer, index);
num = -num;
negative = 1;
}

if (num == 0)
{
_putchar('0', buffer, index);
return (1);
}

while (num != 0)
{
buffer_temp[i++] = (num % 10) + '0';
num /= 10;
}

len = i;
while (i--)
{
_putchar(buffer_temp[i], buffer, index);
len++;
}

return (len + negative);
}
