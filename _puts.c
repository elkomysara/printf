#include "main.h"

/**
 * _puts - Prints a string
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int _puts(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);

    return (i);
}

