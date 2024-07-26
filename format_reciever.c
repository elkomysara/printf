#include "main.h"
#include <stdio.h>

/**
 * format_reciever - Receives the main string and all the necessary parameters to
 * print a formatted string
 * @format: A string containing all the desired characters
 * @f_list: A list of format specifiers and their corresponding functions
 * @arg_list: A list of arguments to be printed
 * @buffer: Buffer to store the formatted string
 * @index: Current index in the buffer
 * Return: A total count of the characters printed
 */
int format_reciever(const char *format, conver_t f_list[], va_list arg_list, char *buffer, int *index)
{
    int i = 0, j, count = 0;
    int plus_flag, space_flag, hash_flag;

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            plus_flag = space_flag = hash_flag = 0;

            while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
            {
                if (format[i] == '+')
                    plus_flag = 1;
                else if (format[i] == ' ')
                    space_flag = 1;
                else if (format[i] == '#')
                    hash_flag = 1;
                i++;
            }

            for (j = 0; f_list[j].specifier != NULL; j++)
            {
                if (format[i] == f_list[j].specifier[0])
                {
                    count += f_list[j].f(arg_list, buffer, index, plus_flag, space_flag, hash_flag);
                    break;
                }
            }

            if (f_list[j].specifier == NULL)
            {
                buffer[*index] = '%';
                buffer[*index + 1] = format[i];
                *index += 2;
                count += 2;
            }
        }
        else
        {
            buffer[*index] = format[i];
            (*index)++;
            count++;
        }
        i++;
    }
    return (count);
}
