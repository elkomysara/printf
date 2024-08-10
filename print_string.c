#include "main.h"

/**
* print_string - Prints a string.
* @list: List of arguments.
* @buffer: The buffer to store the formatted output.
* @index: The current index in the buffer.
*
* Return: The number of characters printed.
*/
int print_string(va_list list, char *buffer, int *index)
{
int i;
char *str;

str = va_arg(list, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
_putchar(str[i], buffer, index);
return (i);
}
