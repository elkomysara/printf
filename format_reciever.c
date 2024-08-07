#include "main.h"

/**
* format_reciever - Receives the format and the argument list, then calls the appropriate function
* @format: The format string
* @f_list: List of conversion specifiers and associated functions
* @arg_list: Argument list
* Return: The number of characters printed
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
