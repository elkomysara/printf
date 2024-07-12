#include "main.h"

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
const char *p;

if (!format)
return (-1);

va_start(args, format);

for (p = format; *p != '\0'; p++)
{
if (*p == '%')
{
p++;
if (*p == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*p == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
count += write(1, str++, 1);
}
}
else if (*p == '%')
{
count += write(1, "%", 1);
}
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

va_end(args);
return (count);
}

