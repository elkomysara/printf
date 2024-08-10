#include "main.h"

/**
* print_HEX - Prints a number in hexadecimal base
* @list: list of arguments
* @buffer: buffer to store the result
* @index: current index in the buffer
* Return: The number of characters printed
*/
int print_HEX(va_list list, char *buffer, int *index)
{
unsigned int n = va_arg(list, unsigned int);
char *str;
int num_chars;

str = convert(n, 16, 0);
if (str == NULL)
return (-1);

num_chars = _puts(str, buffer, index);
return (num_chars);
}
