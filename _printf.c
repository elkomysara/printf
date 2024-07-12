#include <stdarg.h>
#include "main.h"

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
while (*str)
{
count += _putchar(*str);
str++;
}
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(format[i]);
break;
}
}
else
{
count += _putchar(format[i]);
}
i++;
}
va_end(args);
return (count);
}
