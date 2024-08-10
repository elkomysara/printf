
#include "main.h"

/**
* print_percent - Prints a percent symbol
* @list: list of arguments (unused)
* @buffer: The buffer to write to
* @index: The current index in the buffer
* Return: Always 1
*/
int print_percent(va_list list __attribute__((unused)), char *buffer, int *index)
{
return _putchar('%', buffer, index);
}
