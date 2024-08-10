#include "main.h"

/**
 * print_binary - Converts an unsigned int argument to binary
 * @list: list of arguments
 * @buffer: buffer to store the result
 * @index: current index in the buffer
 * Return: The number of characters printed
 */
int print_binary(va_list list, char *buffer, int *index)
{
    unsigned int n = va_arg(list, unsigned int);
    char *binary_str;
    int num_chars;

    binary_str = convert(n, 2, 0);
    if (binary_str == NULL)
        return (-1);

    num_chars = _puts(binary_str, buffer, index);
    return (num_chars);
}


