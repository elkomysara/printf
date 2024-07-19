#include "main.h"

/**
* _putchar - writes a character to stdout
* @c: character to write
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
*
* Return: the number of characters printed (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;

if (!format)
return (-1);

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
_putchar(*str++);
count++;
}
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

va_end(args);
return (count);
}

