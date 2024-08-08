#include "main.h"
#include <stdarg.h>
/**
* format_reciever - Receives the format and
* the argument list, then calls the appropriate function
* @format: The format string
* @f_list: List of conversion specifiers and associated functions
* @arg_list: Argument list
* @buffer: Buffer to store the output
* @index: Index in the buffer
* Return: The number of characters printed
*/

int format_reciever(const char *format, conver_t f_list[], va_list arg_list,
char *buffer, int *index)
{
int i, printed_chars = 0;

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
handle_percent(format, &i, f_list, arg_list, buffer, index, &printed_chars);
if (printed_chars == -1)
{
return (-1);
}
}
else
{
_putchar(format[i], buffer, index);
printed_chars++;
}
}
if (*index > 0)
{
write(1, buffer, *index);
}
return (printed_chars);
}
