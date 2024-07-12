#include "main.h"

/**
* _printf - Produces output according to a format
* @format: The format string
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, printed_chars = 0;
int (*handler)(va_list);

if (!format)
return (-1);

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
return (-1);
handler = NULL;

switch (format[i])
{
case 'c':
handler = handle_char;
break;
case 's':
handler = handle_string;
break;
case '%':
printed_chars += handle_percent();
i++;
continue;
default:
printed_chars += write(1, &format[i - 1], 1);
printed_chars += write(1, &format[i], 1);
i++;
continue;
}
if (handler)
printed_chars += handler(args);
}
else
{
printed_chars += write(1, &format[i], 1);
}
i++;
}

va_end(args);
return (printed_chars);
}
