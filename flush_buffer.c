#include "main.h"

/**
 * flush_buffer - Writes the buffer to stdout and resets the buffer index
 * @buffer: The buffer containing the characters to be written
 * @index: The current index in the buffer
 */
void flush_buffer(char *buffer, int *index)
{
    if (*index > 0)
    {
        write(1, buffer, *index);
        *index = 0;
    }
}
