#include "main.h"

/**
* format_reciever - Receives the format string and argument list,
* then calls the appropriate function to handle each format specifier.
* @format: The format string that contains the specifiers.
* @f_list: List of conversion specifiers and their associated functions.
* @arg_list: List of arguments to be formatted.
*
* Return: The total number of characters printed.
*/
int format_reciever(const char *format, conver_t f_list[], va_list arg_list)
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
printed_chars += f_list[j].f(arg_list);
i++;
break;
}
}
if (f_list[j].sym == NULL && format[i + 1] != ' ' && format[i + 1] != '\0')
{
_putchar(format[i]);
_putchar(format[i + 1]);
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
_putchar(format[i]);
printed_chars++;
}
}

return (printed_chars);
}
