#include "main.h"

/**
* handle_char - handles the %c format specifier
* @args: argument list
*
* Return: number of characters printed
*/
int handle_char(va_list args)
{
_putchar(va_arg(args, int));
return (1);
}

/**
* handle_string - handles the %s format specifier
* @args: argument list
*
* Return: number of characters printed
*/
int handle_string(va_list args)
{
int count = 0;
char *str = va_arg(args, char *);

if (!str)
str = "(null)";
while (*str)
{
_putchar(*str++);
count++;
}
return (count);
}

/**
* handle_format - handles the format string
* @format: format string containing the characters and specifiers
* @args: argument list
*
* Return: number of characters printed
*/
int handle_format(const char *format, va_list args)
{
int i = 0, count = 0;

while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += handle_char(args);
break;
case 's':
count += handle_string(args);
break;
case '%':
_putchar('%');
count++;
break;
default:
_putchar('%');
_putchar(format[i]);
count += 2;
break;
}
}
else
{
_putchar(format[i]);
count++;
}
i++;
}
return (count);
}

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
*
* Return: the number of characters printed
*         (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
va_list args;
int count;

if (!format)
return (-1);

va_start(args, format);
count = handle_format(format, args);
va_end(args);
return (count);
}
