#include <unistd.h>

/**
* _putchar - writes a character to stdout
* @c: character to write
* @buffer: the buffer to write the character to
* @index: the index in the buffer
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
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
