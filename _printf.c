#include "main.h"

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
*
* Return: the number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list arguments;
const char *p;
int count = 0;

if (!format)
return (-1);

va_start(arguments, format);

for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
count += _putchar('%');
continue;
}
else if (*p == 'c')
{
count += handle_char(arguments);
}
else if (*p == 's')
{
count += handle_string(arguments);
}
else
{
/* Handle unknown specifier */
count += _putchar('%');
count += _putchar(*p);
}
}
else
{
count += _putchar(*p);
}
}

va_end(arguments);
return (count);
}

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
