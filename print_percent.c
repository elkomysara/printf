#include "main.h"

/**
* print_percent - Prints a percent symbol
* @list: list of arguments (unused)
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the amount of characters printed.
*/
int print_percent(va_list list, char *buffer, int *index)
{
(void)list; /* Avoid unused parameter warning */
_putchar('%', buffer, index);
return (1);
}
