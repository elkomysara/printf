
#include "main.h"

/**
* handle_percent - Handles the percent format
* @format: The format string
* @i: Pointer to the current position in the format string
* @f_list: List of conversion specifiers and associated functions
* @arg_list: Argument list
* @buffer: Buffer to store the output
* @index: Index in the buffer
* @printed_chars: Pointer to the total number of characters printed
*/
void handle_percent(const char *format, int *i, conver_t f_list[],
va_list arg_list, char *buffer, int *index,
int *printed_chars)
{
int j, found = 0;
for (j = 0; f_list[j].sym != NULL; j++)
{
if (format[*i + 1] == f_list[j].sym[0])
{
*printed_chars += f_list[j].f(arg_list, buffer, index);
(*i)++;
found = 1;
break;
}
}
if (!found)
{
if (format[*i + 1] != '\0')
{
_putchar(format[*i], buffer, index);
_putchar(format[*i + 1], buffer, index);
*printed_chars += 2;
(*i)++;
}
else
{
*printed_chars = -1;
}
}
}
