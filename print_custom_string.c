#include "main.h"
#include <stdio.h>

/**
* print_custom_string - Prints a string, replacing non-printable characters
* with their hex values.
* @list: List of arguments.
* @buffer: Buffer to store the result.
* @index: Current index in the buffer.
* 
* Return: Number of characters printed.
*/
int print_custom_string(va_list list, char *buffer, int *index)
{
char *str = va_arg(list, char *);
int i, printed_chars = 0;
char hex[3];

if (str == NULL)
str = "(null)";

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < 32 || str[i] >= 127)
{
_putchar('\\', buffer, index);
_putchar('x', buffer, index);
sprintf(hex, "%02X", (unsigned char)str[i]);
_putchar(hex[0], buffer, index);
_putchar(hex[1], buffer, index);
printed_chars += 4;
}
else
{
_putchar(str[i], buffer, index);
printed_chars++;
}
}

return (printed_chars);
}
