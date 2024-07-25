#include "main.h"

/**
* format_reciever - Receives the main string and all the necessary parameters to
* print a formatted string
* @format: A string containing all the desired characters
* @f_list: A list of all the possible functions
* @arg_list: A list containing all the argument variables
* Return: A total count of the characters printed
*/
int format_reciever(const char *format, conver_t f_list[], va_list arg_list)
{
int i, j, printed_chars = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
for (j = 0; f_list[j].sym != NULL; j++)
{
if (format[i + 1] == f_list[j].sym[0])
{
printed_chars += f_list[j].f(arg_list);
i++;
break;
}
}
if (f_list[j].sym == NULL && format[i + 1] != ' ')
{
_putchar(format[i]);
printed_chars++;
}
}
else
{
_putchar(format[i]);
printed_chars++;
}
}
return (printed_chars);
}
