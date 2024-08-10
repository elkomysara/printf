#include "main.h"

/**
 * format_reciever - Receives the main string and all the necessary parameters to
 * print a formatted string
 * @format: A string containing all the desired characters
 * @f_list: A list of conversion specifiers
 * @arg_list: A list containing all the arguments passed to the program
 * @buffer: The buffer to write to
 * @index: The current index in the buffer
 * Return: A total count of the characters printed
 */
#include "main.h"

int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index)
{
    int i, j, printed_chars = 0;
    int (*func)(va_list, char *, int *);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            for (j = 0; f_list[j].specifier != NULL; j++)
            {
                if (format[i + 1] == f_list[j].specifier[0])
                {
                    func = f_list[j].f;
                    printed_chars += func(arg_list, buffer, index);
                    break;
                }
            }
            if (f_list[j].specifier == NULL && format[i + 1] != ' ')
            {
                _putchar(format[i], buffer, index);
                _putchar(format[i + 1], buffer, index);
                printed_chars += 2;
            }
            i++;
        }
        else
        {
            _putchar(format[i], buffer, index);
            printed_chars++;
        }
    }

    return (printed_chars);
}

