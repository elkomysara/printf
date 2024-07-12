#include "main.h"

int handle_char(char c);
int handle_string(char *str);
int handle_format(const char *format, va_list args);

/**
* _printf - Produces output according to a format
* @format: A character string composed of zero or more directives
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1);

va_start(args, format);
count = handle_format(format, args);
va_end(args);

return (count);
}

/**
* handle_format - Handles the format string and calls appropriate handlers
* @format: The format string
* @args: The variadic arguments list
*
* Return: The number of characters printed
*/
int handle_format(const char *format, va_list args)
{
int count = 0;
const char *p;

for (p = format; *p != '\0'; p++)
{
if (*p == '%')
{
p++;
if (*p == 'c')
count += handle_char(va_arg(args, int));
else if (*p == 's')
count += handle_string(va_arg(args, char *));
else if (*p == '%')
count += write(1, "%", 1);
else
{
count += write(1, "%", 1);
count += write(1, p, 1);
}
}
else
{
count += write(1, p, 1);
}
}

return (count);
}

/**
* handle_char - Writes a character to stdout
* @c: The character to write
*
* Return: The number of characters written
*/
int handle_char(char c)
{
return (write(1, &c, 1));
}

/**
* handle_string - Writes a string to stdout
* @str: The string to write
*
* Return: The number of characters written
*/
int handle_string(char *str)
{
int count = 0;

while (*str)
{
count += write(1, str++, 1);
}

return (count);
}
