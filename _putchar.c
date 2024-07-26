#include "main.h"

/**
 * _putchar - Writes a character to the buffer and flushes it if necessary
 * @c: The character to write
 * @buffer: The buffer to write to
 * @index: The current index in the buffer
 * Return: Always 1
 */
#include "main.h"

int _putchar(char c, char *buffer, int *index)
{
    buffer[(*index)++] = c;
    if (*index >= 1024)
    {
        write(1, buffer, *index);
        *index = 0;
    }
    return (1);
}

