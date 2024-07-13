#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4

int handle_char(char c, char *buffer, int *buff_ind);
int handle_string(char *str, char *buffer, int *buff_ind);
int handle_format(const char *format, int *i, va_list args, char *buffer, int *buff_ind);
int handle_int(int n, char *buffer, int *buff_ind, int flags);
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind, int flags);
int handle_octal(unsigned int n, char *buffer, int *buff_ind, int flags);
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind, int flags);
int handle_pointer(void *p, char *buffer, int *buff_ind, int flags);
int handle_binary(unsigned int n, char *buffer, int *buff_ind);
int handle_custom_string(char *str, char *buffer, int *buff_ind);
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
int i, total_count = 0;
char buffer[BUFFER_SIZE];
int buff_ind = 0;

va_start(args, format);

for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
{
total_count += handle_format(format, &i, args, buffer, &buff_ind);
}
else
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFFER_SIZE)
buffer_flush(buffer, &buff_ind);
total_count++;
}
}
buffer_flush(buffer, &buff_ind);
va_end(args);
return (total_count);
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
int handle_format(const char *format, int *i, va_list args, char *buffer, int *buff_ind)
{
int flags = 0;

while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
{
if (format[*i] == '+')
flags |= FLAG_PLUS;
if (format[*i] == ' ')
flags |= FLAG_SPACE;
if (format[*i] == '#')
flags |= FLAG_HASH;
(*i)++;
}

if (format[*i] == 'd' || format[*i] == 'i')
return (handle_int(va_arg(args, int), buffer, buff_ind, flags));
if (format[*i] == 'u')
return (handle_unsigned(va_arg(args, unsigned int), buffer, buff_ind, flags));
if (format[*i] == 'o')
return (handle_octal(va_arg(args, unsigned int), buffer, buff_ind, flags));
if (format[*i] == 'x')
return (handle_hex(va_arg(args, unsigned int), 0, buffer, buff_ind, flags));
if (format[*i] == 'X')
return (handle_hex(va_arg(args, unsigned int), 1, buffer, buff_ind, flags));
if (format[*i] == 'p')
return (handle_pointer(va_arg(args, void *), buffer, buff_ind, flags));
if (format[*i] == 'c')
return (handle_char(va_arg(args, int), buffer, buff_ind));
if (format[*i] == 's')
return (handle_string(va_arg(args, char *), buffer, buff_ind));
if (format[*i] == '%')
{
buffer[*buff_ind] = '%';
(*buff_ind)++;
return (1);
}

return (0); /* if no match, just return 0 */
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
* handle_int - Writes an integer to buffer with flags
* @n: The integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
* @flags: The flags for formatting
*
* Return: The number of characters written
*/
int handle_int(int n, char *buffer, int *buff_ind, int flags)
{
int len = 0;
int is_negative = n < 0;
unsigned int num = is_negative ? -n : n;
char num_buffer[20];  /* Temporary buffer for number conversion */
int num_index = 0;

/* Handle sign */
if (is_negative)
{
buffer[*buff_ind] = '-';
(*buff_ind)++;
len++;
}
else if (flags & FLAG_PLUS)
{
buffer[*buff_ind] = '+';
(*buff_ind)++;
len++;
}
else if (flags & FLAG_SPACE)
{
buffer[*buff_ind] = ' ';
(*buff_ind)++;
len++;
}

/* Convert number to string in reverse */
do {
num_buffer[num_index++] = num % 10 + '0';
num /= 10;
} while (num > 0);

/* Copy number to buffer in correct order */
while (num_index--)
{
buffer[*buff_ind] = num_buffer[num_index];
(*buff_ind)++;
len++;
}

return (len);
}

/**
* handle_unsigned - Writes an unsigned integer to buffer with flags
* @n: The unsigned integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
* @flags: The flags for formatting
*
* Return: The number of characters written
*/
int handle_unsigned(unsigned int n, char *buffer, int *buff_ind)
{
int len = 0;
char num_buffer[20];
int num_index = 0;

do {
num_buffer[num_index++] = n % 10 + '0';
n /= 10;
} while (n > 0);

while (num_index--)
{
buffer[*buff_ind] = num_buffer[num_index];
(*buff_ind)++;
len++;
}

return (len);
}

/**
* handle_octal - Writes an unsigned integer in octal to buffer with flags
* @n: The unsigned integer to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
* @flags: The flags for formatting
*
* Return: The number of characters written
*/
int handle_octal(unsigned int n, char *buffer, int *buff_ind, int flags)
{
char num_buffer[20];
int count = 0, i = 0;

if (flags & 4 && n != 0)
{
buffer[*buff_ind] = '0';
(*buff_ind)++;
count++;
}

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
* handle_hex - Writes an unsigned integer in hexadecimal to buffer with flags
* @n: The unsigned integer to write
* @uppercase: 1 for uppercase, 0 for lowercase
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
* @flags: The flags for formatting
*
* Return: The number of characters written
*/
int handle_hex(unsigned int n, int uppercase, char *buffer, int *buff_ind, int flags)
{
char num_buffer[20];
int count = 0, i = 0;
char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

if (flags & 4 && n != 0)
{
buffer[*buff_ind] = '0';
(*buff_ind)++;
buffer[*buff_ind] = uppercase ? 'X' : 'x';
(*buff_ind)++;
count += 2;
}

if (n == 0)
{
num_buffer[i++] = '0';
}
else
{
while (n > 0)
{
num_buffer[i++] = hex_digits[n % 16];
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
* @flags: The flags for formatting
*
* Return: The number of characters written
*/
int handle_pointer(void *p, char *buffer, int *buff_ind)
{
unsigned long int addr = (unsigned long int)p;
int len = 0;
char hex_buffer[20];
int hex_index = 0;

buffer[*buff_ind] = '0';
(*buff_ind)++;
buffer[*buff_ind] = 'x';
(*buff_ind)++;
len += 2;

do {
int digit = addr % 16;
hex_buffer[hex_index++] = digit < 10 ? digit + '0' : digit - 10 + 'a';
addr /= 16;
} while (addr > 0);

while (hex_index--)
{
buffer[*buff_ind] = hex_buffer[hex_index];
(*buff_ind)++;
len++;
}

return (len);
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
* handle_custom_string - Writes a string to buffer with custom formatting
* @str: The string to write
* @buffer: The buffer to store characters
* @buff_ind: The current index in the buffer
*
* Return: The number of characters written
*/
int handle_custom_string(char *str, char *buffer, int *buff_ind)
{
int count = 0;

while (*str)
{
if (*str < 32 || *str >= 127)
{
buffer[*buff_ind] = '\\';
(*buff_ind)++;
count++;
buffer[*buff_ind] = 'x';
(*buff_ind)++;
count++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);

buffer[*buff_ind] = (*str / 16) < 10 ? ((*str / 16) + '0') : ((*str / 16) - 10 + 'A');
(*buff_ind)++;
count++;
buffer[*buff_ind] = (*str % 16) < 10 ? ((*str % 16) + '0') : ((*str % 16) - 10 + 'A');
(*buff_ind)++;
count++;
}
else
{
buffer[*buff_ind] = *str;
(*buff_ind)++;
count++;
}

str++;

if (*buff_ind >= BUFFER_SIZE)
buffer_flush(buffer, buff_ind);
}

return (count);
}

/**
* buffer_flush - Flushes the buffer by writing its content to stdout
* @buffer: The buffer to flush
* @buff_ind: The current index in the buffer
*/
void buffer_flush(char *buffer, int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, buffer, *buff_ind);
*buff_ind = 0;
}
}

