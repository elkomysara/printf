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


/**
 * convert - Converts a number to a string in the given base
 * @num: The number to be converted
 * @base: The base to convert to
 * @lowercase: Flag to determine if hex letters should be lowercase
 * Return: A pointer to the converted string (static buffer)
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char buffer[50];
    char *ptr;
    char *rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";

    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}
