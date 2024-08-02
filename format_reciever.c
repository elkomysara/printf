#include "main.h"
#include <stdio.h>

/**
 * format_reciever - Receives the main string and necessary parameters to
 * print a formatted string
 * @format: A string containing all the desired characters
 * @f_list: List of format specifiers and their corresponding functions
 * @arg_list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * Return: Number of characters printed
 */
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index)
{
    int i = 0, j, printed_chars = 0;
    flags_t flags;
    length_mod_t length_mod;
    int width;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            flags = parse_flags(format, &i);
            length_mod = parse_length_mod(format, &i);
            width = parse_width(format, &i, arg_list);

            for (j = 0; f_list[j].sym != NULL; j++)
            {
                if (format[i] == f_list[j].sym[0])
                {
                    printed_chars += f_list[j].f(arg_list, buffer, index, flags, length_mod, width);
                    break;
                }
            }
            if (f_list[j].sym == NULL)
            {
                _putchar('%', buffer, index);
                _putchar(format[i], buffer, index);
                printed_chars += 2;
            }
            i++;
        }
        else
        {
            _putchar(format[i], buffer, index);
            printed_chars++;
            i++;
        }
    }
    return (printed_chars);
}
