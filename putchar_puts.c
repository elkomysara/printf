
#include "main.h"
#include <unistd.h> 

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, returns the character written as an unsigned char cast to an int.
 *         On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1); 
}

/**
 * _puts - Writes a string to the standard output
 * @str: The string to be written
 *
 * Return: On success, returns the number of characters written (excluding the null byte).
 *         On error, returns -1 and sets errno appropriately.
 */
int _puts(char *str)
{
    int len = 0;

    while (*str)
    {
        if (_putchar(*str) == -1) 
            return -1;
        len++;
        str++;
    }

    return len; 
}
