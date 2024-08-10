#include "main.h"

/**
 * format_reciever - Receives the format and argument list,
 * then calls the appropriate function.
 * @format: The format string containing the specifiers.
 * @f_list: List of conversion specifiers and their associated functions.
 * @arg_list: List of arguments to be formatted.
 * @buffer: The buffer to store the formatted output.
 * @index: The current index in the buffer.
 * Return: The total number of characters printed.
 */
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index)
{
int i, j, printed_chars = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
for (j = 0; f_list[j].sym != NULL; j++)
{
if (format[i + 1] == f_list[j].sym[0])
{
printed_chars += f_list[j].f(arg_list, buffer, index);
i++;
break;
}
}
if (f_list[j].sym == NULL && format[i + 1] != ' ' && format[i + 1] != '\0')
{
_putchar(format[i], buffer, index);
_putchar(format[i + 1], buffer, index);
printed_chars += 2;
i++;
}

else if (f_list[j].sym == NULL && format[i + 1] == '\0')
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

return (printed_chars);
}
