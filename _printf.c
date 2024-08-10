#include "main.h"

/**
* _printf - Receives the main string and all the necessary parameters to
* print a formatted string
* @format: A string containing all the desired characters
* Return: A total count of the characters printed
*/

int _printf(const char *format, ...)
{
va_list arg_list;
int printed_chars = 0;
char buffer[1024];
int index = 0;

conver_t f_list[] = {
{"%", print_percent},
{"c", print_char},
{"s", print_string},
{"d", print_integer},
{"i", print_integer},
{"b", print_binary},
{"u", print_unsigned},
{"o", print_octal},
{"x", print_hex},
{"X", print_HEX},
{NULL, NULL}
};

if (format == NULL)
return (-1);

va_start(arg_list, format);
printed_chars = format_reciever(format, f_list, arg_list, buffer, &index);
va_end(arg_list);

buffer[index] = '\0';
write(1, buffer, index);

return (printed_chars);
}

