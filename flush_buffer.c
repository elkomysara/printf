#include "main.h"
#include <unistd.h> 

/**
 * flush_buffer - Writes the content of the buffer to stdout
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * Return: void
 */
void flush_buffer(char *buffer, int *index)
{
    if (*index > 0)
    {
        write(1, buffer, *index);
        *index = 0;
    }
}
