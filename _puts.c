#include "main.h"

/**
* _puts - Writes a string to the buffer
* @str: The string to write
* @buffer: The buffer to write to
* @index: The current index in the buffer
* Return: The number of characters written
*/
int _puts(char *str, char *buffer, int *index)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i], buffer, index);
}

return (i);
}

