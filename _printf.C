
#include "main.h"
#include <stdarg.h> 

/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format); 

    while (*format)
    {
        if (*format == '%') 
        {
            format++; 
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int)); 
                    break;
                case 's':
                    count += _puts(va_arg(args, char *)); 
                    break;
                case '%':
                    count += _putchar('%'); 
                    break;
                default:
                    count += _putchar('%'); 
                    count += _putchar(*format);
                    break;
            }
        }
        else
        {
            count += _putchar(*format); 
        }
        format++; 
    }

    va_end(args); 
    return count; 
}
