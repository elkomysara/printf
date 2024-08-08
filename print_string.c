#include "main.h"

/**
* print_string - Prints a string
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the amount of characters printed.
*/
int print_string(va_list list, char *buffer, int *index)
{
int i;
char *str;

(void)buffer; /* Avoid unused parameter warning */
(void)index;  /* Avoid unused parameter warning */

str = va_arg(list, char *);
if (str == NULL)
{
str = "(null)";
}
for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i], buffer, index);
}
return (i);
}
