#include "main.h"

#define BUFFER_SIZE 1024

int handle_char(char c, char *buffer, int *buff_ind);
int handle_string(char *str, char *buffer, int *buff_ind);
int handle_format(const char *format, va_list args, char *buffer, int *buff_ind);
int handle_int(int n, char *buffer, int *buff_ind);
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind);
int handle_octal(unsigned int n, char *buffer, int *buff_ind);
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind);
int handle_pointer(void *p, char *buffer, int *buff_ind);
int handle_binary(unsigned int n, char *buffer, int *buff_ind);
void buffer_flush(char *buffer, int *buff_ind);

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
int buff_ind = 0;
char buffer[BUFFER_SIZE];

if (!format)
return (-1);

va_start(args, format);
count = handle_format(format, args, buffer, &buff_ind);
va_end(args);

buffer_flush(buffer, &buff_ind);

return (count);
}

/**
* handle_format - Handles the format string and calls appropriate handlers
* @format: The format string
* @args: The variadic arguments list
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters printed
*/
int handle_format(const char *format, va_list args, char *buffer, int *buff_ind)
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
count += handle_char(va_arg(args, int), buffer, buff_ind);
break;
case 's':
count += handle_string(va_arg(args, char *), buffer, buff_ind);
break;
case '%':
buffer[*buff_ind] = '%';
(*buff_ind)++;
count++;
break;
case 'd':
case 'i':
count += handle_int(va_arg(args, int), buffer, buff_ind);
break;
case 'u':
count += handle_unsigned(va_arg(args, unsigned int), buffer, buff_ind);
break;
case 'o':
count += handle_octal(va_arg(args, unsigned int), buffer, buff_ind);
break;
case 'x':
count += handle_hex(va_arg(args, unsigned int), 0, buffer, buff_ind);
break;
case 'X':
count += handle_hex(va_arg(args, unsigned int), 1, buffer, buff_ind);
break;
case 'p':
count += handle_pointer(va_arg(args, void *), buffer, buff_ind);
break;
case 'b':
count += handle_binary(va_arg(args, unsigned int), buffer, buff_ind);
break;
default:
buffer[*buff_ind] = '%';
(*buff_ind)++;
buffer[*buff_ind] = *p;
(*buff_ind)++;
count += 2;
break;
}
}
else
{
buffer[*buff_ind] = *p;
(*buff_ind)++;
count++;
}

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_char - Writes a character to buffer
* @c: The character to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_char(char c, char *buffer, int *buff_ind)
{
buffer[*buff_ind] = c;
(*buff_ind)++;
return (1);
}

/**
* handle_string - Writes a string to buffer
* @str: The string to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_string(char *str, char *buffer, int *buff_ind)
{
int count = 0;

while (*str)
{
buffer[*buff_ind] = *str;
(*buff_ind)++;
count++;
str++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_int - Writes an integer to buffer
* @n: The integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_int(int n, char *buffer, int *buff_ind)
{
char num_buffer[20];
int count = 0, i = 0, sign = n < 0;

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
if (sign)
n = -n;
while (n > 0)
{
num_buffer[i++] = (n % 10) + '0';
n /= 10;
}
if (sign)
num_buffer[i++] = '-';
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_unsigned - Writes an unsigned integer to buffer
* @n: The unsigned integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind)
{
char num_buffer[20];
int count = 0, i = 0;

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
while (n > 0)
{
num_buffer[i++] = (n % 10) + '0';
n /= 10;
}
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_octal - Writes an unsigned integer in octal to buffer
* @n: The unsigned integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_octal(unsigned int n, char *buffer, int *buff_ind)
{
char num_buffer[20];
int count = 0, i = 0;

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
while (n > 0)
{
num_buffer[i++] = (n % 8) + '0';
n /= 8;
}
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_hex - Writes an unsigned integer in hexadecimal to buffer
* @n: The unsigned integer to write
* @uppercase: Whether to use uppercase letters
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind)
{
char num_buffer[20];
int count = 0, i = 0;
char offset = uppercase ? 'A' - 10 : 'a' - 10;

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
while (n > 0)
{
int digit = n % 16;
num_buffer[i++] = digit < 10 ? digit + '0' : digit + offset;
n /= 16;
}
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_pointer - Writes a pointer address to buffer
* @p: The pointer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_pointer(void *p, char *buffer, int *buff_ind)
{
unsigned long int addr = (unsigned long int)p;
char num_buffer[20];
int count = 0, i = 0;

if (!p)
return (handle_string("(nil)", buffer, buff_ind));

buffer[*buff_ind] = '0';
(*buff_ind)++;
buffer[*buff_ind] = 'x';
(*buff_ind)++;
count += 2;

while (addr > 0)
{
int digit = addr % 16;
num_buffer[i++] = digit < 10 ? digit + '0' : digit - 10 + 'a';
addr /= 16;
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* handle_binary - Writes an unsigned integer in binary to buffer
* @n: The unsigned integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_binary(unsigned int n, char *buffer, int *buff_ind)
{
char num_buffer[32];
int count = 0, i = 0;

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
while (n > 0)
{
num_buffer[i++] = (n % 2) + '0';
n /= 2;
}
}

while (i--)
{
buffer[*buff_ind] = num_buffer[i];
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* buffer_flush - Flushes the buffer to standard output
* @buffer: The buffer to flush
* @buff_ind: The current index in the buffer
*/
void buffer_flush(char *buffer, int *buff_ind)
{
write(1, buffer, *buff_ind);
*buff_ind = 0;
}

