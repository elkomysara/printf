#include "main.h"

/**
* _puts - Prints a string to stdout
* @str: The string to be printed
* @buffer: The buffer to store the formatted output
* @index: The current index in the buffer
*
* Return: The number of characters printed
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
