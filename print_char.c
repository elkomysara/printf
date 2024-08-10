#include "main.h"

/**
* print_char - Prints a character to the buffer.
* @list: List of arguments.
* @buffer: The buffer to store the formatted output.
* @index: The current index in the buffer.
*
* Return: The number of characters printed (1).
*/
int print_char(va_list list, char *buffer, int *index)
{
_putchar(va_arg(list, int), buffer, index);
return (1);
}
