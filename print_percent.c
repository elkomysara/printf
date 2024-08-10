#include "main.h"

/**
* print_percent - Prints a percent symbol
* @list: Unused list of arguments
* @buffer: The buffer to store the formatted output
* @index: The current index in the buffer
*
* Return: Will return the amount of characters printed.
*/
int print_percent(__attribute__((unused)) va_list list, char *buffer, int *index)
{
_putchar('%', buffer, index);
return (1);
}
