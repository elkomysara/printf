#include "main.h"

/**
* print_integer - Prints an integer
* @list: list of arguments
* Return: Will return the amount of characters printed.
*/
int print_integer(va_list list)
{
int num_length;
int num = va_arg(list, int);
num_length = print_number(num);
return (num_length);
}

