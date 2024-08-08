#include "main.h"

/**
* print_char - Prints character
* @list: list of arguments
* @buffer: buffer to store the output
* @index: index in the buffer
* Return: Will return the amount of characters printed.
*/

int print_char(va_list list, char *buffer, int *index)
{
_putchar(va_arg(list, int), buffer, index);
return (1);
}
