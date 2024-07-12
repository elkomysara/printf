#include "main.h"

int handle_char(char c);
int handle_string(char *str);
int handle_format(const char *format, va_list args);
int handle_int(int n);
int handle_unsigned(unsigned int n);
int handle_octal(unsigned int n);
int handle_hex(unsigned int n, int uppercase);
int handle_pointer(void *p);

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
switch (*p)
{
case 'c':
count += handle_char(va_arg(args, int));
break;
case 's':
count += handle_string(va_arg(args, char *));
break;
case '%':
count += write(1, "%", 1);
break;
case 'd':
case 'i':
count += handle_int(va_arg(args, int));
break;
case 'u':
count += handle_unsigned(va_arg(args, unsigned int));
break;
case 'o':
count += handle_octal(va_arg(args, unsigned int));
break;
case 'x':
count += handle_hex(va_arg(args, unsigned int), 0);
break;
case 'X':
count += handle_hex(va_arg(args, unsigned int), 1);
break;
case 'p':
count += handle_pointer(va_arg(args, void *));
break;
default:
count += write(1, "%", 1);
count += write(1, p, 1);
break;
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

/**
* handle_int - Writes an integer to stdout
* @n: The integer to write
*
* Return: The number of characters written
*/
int handle_int(int n)
{
char buffer[20];
int count = 0;
int i = 0;
int sign = n < 0;

if (n == 0)
{
buffer[i++] = '0';
}
else
{
if (sign)
n = -n;
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
if (sign)
buffer[i++] = '-';
}

while (i--)
count += write(1, &buffer[i], 1);

return (count);
}

/**
* handle_unsigned - Writes an unsigned integer to stdout
* @n: The unsigned integer to write
*
* Return: The number of characters written
*/
int handle_unsigned(unsigned int n)
{
char buffer[20];
int count = 0;
int i = 0;

if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
}

while (i--)
count += write(1, &buffer[i], 1);

return (count);
}

/**
* handle_octal - Writes an unsigned integer in octal format to stdout
* @n: The unsigned integer to write
*
* Return: The number of characters written
*/
int handle_octal(unsigned int n)
{
char buffer[20];
int count = 0;
int i = 0;

if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n > 0)
{
buffer[i++] = (n % 8) + '0';
n /= 8;
}
}

while (i--)
count += write(1, &buffer[i], 1);

return (count);
}

/**
* handle_hex - Writes an unsigned integer in hexadecimal format to stdout
* @n: The unsigned integer to write
* @uppercase: Whether to use uppercase letters for hex digits
*
* Return: The number of characters written
*/
int handle_hex(unsigned int n, int uppercase)
{
char buffer[20];
int count = 0;
int i = 0;
char a = uppercase ? 'A' : 'a';

if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n > 0)
{
int digit = n % 16;
if (digit < 10)
buffer[i++] = digit + '0';
else
buffer[i++] = digit - 10 + a;
n /= 16;
}
}

while (i--)
count += write(1, &buffer[i], 1);

return (count);
}

/**
* handle_pointer - Writes a pointer address to stdout
* @p: The pointer to write
*
* Return: The number of characters written
*/
int handle_pointer(void *p)
{
unsigned long int addr = (unsigned long int)p;
char buffer[20];
int count = 0;
int i = 0;

if (!p)
{
return (write(1, "(nil)", 5));
}

while (addr > 0)
{
int digit = addr % 16;
if (digit < 10)
buffer[i++] = digit + '0';
else
buffer[i++] = digit - 10 + 'a';
addr /= 16;
}

count += write(1, "0x", 2);
while (i--)
count += write(1, &buffer[i], 1);

return (count);
}
