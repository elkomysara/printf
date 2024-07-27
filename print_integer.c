
#include "main.h"
#include <stdlib.h>  /* Include stdlib.h for malloc */

/* Helper function to implement itoa since it's not standard in C */
void itoa(int num, char *str, int base) {
    int i = 0;
    int is_negative = 0;
    int start, end;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    /* Handle negative numbers for base 10 */
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    /* Process individual digits */
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    /* Append '-' for negative numbers */
    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    /* Reverse the string */
    start = 0;
    end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/**
 * print_integer - Prints an integer
 * @list: List of arguments
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @flags: Flags for formatting
 * Return: Number of characters printed
 */
int print_integer(va_list list, char *buffer, int *index, flags_t flags)
{
    int num = va_arg(list, int);
    char str[12];
    int i = 0;

    itoa(num, str, 10);
    (void)flags; /* Suppress unused parameter warning */

    while (str[i])
    {
        _putchar(str[i], buffer, index);
        i++;
    }
    return (i);
}
