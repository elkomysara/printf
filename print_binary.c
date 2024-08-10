#include "main.h"

/**
* print_binary - Converts an unsigned int argument to binary
* @list: list of arguments
* @buffer: The buffer to store the formatted output
* @index: The current index in the buffer
* Return: The number of characters printed
*/
int print_binary(va_list list, char *buffer, int *index)
{
unsigned int n = va_arg(list, unsigned int);
char *binary_str;
int num_chars;

binary_str = convert_to_binary(n);
if (binary_str == NULL)
return (-1);

num_chars = _puts(binary_str, buffer, index);
return (num_chars);
}


/**
* convert_to_binary - Converts an unsigned int to a binary string.
* @num: The unsigned int to convert.
*
* Return: A pointer to the binary string (static buffer).
*/
char *convert_to_binary(unsigned int num)
{
static char buffer[33];
char *ptr = &buffer[32];
*ptr = '\0';

do {
*--ptr = (num % 2) + '0';
num /= 2;
} while (num > 0);

return (ptr);
}
