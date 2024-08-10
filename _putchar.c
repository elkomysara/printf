#include "main.h"

/**
* _putchar - Writes a character to the buffer, and flushes the buffer if full.
* @c: The character to write
* @buffer: The buffer to write to
* @index: The current index in the buffer
*
* Return: 1 on success, -1 on error.
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
