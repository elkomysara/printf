#include "main.h"
#include <unistd.h> 

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, char *buffer, int *index)
{
    if (*index >= 1024)
    {
        write(1, buffer, *index);
        *index = 0;
    }

    buffer[*index] = c;
    (*index)++;

    return (1);
}
