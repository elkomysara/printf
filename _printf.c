#include "main.h"

/**
* _printf - Receives the main string and all the necessary parameters to
* print a formatted string.
* @format: A string containing all the desired characters.
*
* Return: The total number of characters printed.
*/
int _printf(const char *format, ...)
{
int printed_chars;
char buffer[1024];
int index = 0;

conver_t f_list[] = {
{"%", print_percent},
{"c", print_char},
{"s", print_string},
{"d", print_int},
{"i", print_int},
{"b", print_binary},
{"u", print_unsigned},
{"o", print_octal},
{"x", print_hex},
{"X", print_HEX},
{NULL, NULL},
};
va_list arg_list;

if (format == NULL)
return (-1);

va_start(arg_list, format);
printed_chars = format_reciever(format, f_list, arg_list, buffer, &index);
va_end(arg_list);

if (index > 0)
write(1, buffer, index);

return (printed_chars);
}
