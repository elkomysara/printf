#include "main.h"

/**
 * format_reciever - Receives the format string and calls appropriate functions.
 * @format: The format string.
 * @f_list: The array of format specifiers and their handling functions.
 * @arg_list: The list of arguments.
 * 
 * Return: The number of characters printed.
 */
int format_reciever(const char *format, conver_t f_list[], va_list arg_list)
{
    int i, j, count = 0;

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            for (j = 0; f_list[j].sym; j++)
            {
                if (format[i] == f_list[j].sym[0])
                {
                    count += f_list[j].f(arg_list);
                    break;
                }
            }
            if (!f_list[j].sym)
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }
    return (count);
}
