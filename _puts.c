#include "main.h"

/**
 * _puts - Prints a string to stdout
 * @str: The string to print
 * Return: The number of characters printed
 */
int _puts(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
}
