#include "main.h"

/**
* _printf - Receives the main string and all the necessary parameters to
* print a formatted string
* @format: A string containing all the desired characters
* Return: A total count of the characters printed
*/
int _printf(const char *format, ...)
{
int printed_chars;
conver_t f_list[] = {
{"%", print_percent},
{"c", print_char},
{"s", print_string},
{"d", print_int},
{"i", print_int},
{"b", print_binary},  /* Add the 'b' specifier here */
{NULL, NULL},
};
va_list arg_list;

if (format == NULL)
return (-1);

va_start(arg_list, format);
printed_chars = format_reciever(format, f_list, arg_list);
va_end(arg_list);

return (printed_chars);
}
