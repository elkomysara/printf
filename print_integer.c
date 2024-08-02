

#include "main.h"
#include <stdlib.h>  /* Include stdlib.h for malloc */
#include <string.h>

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
 * @length_mod: Length modifier for formatting
 * @width: Width for formatting
 * Return: Number of characters printed
 */
int print_integer(va_list list, char *buffer, int *index, flags_t flags, length_mod_t length_mod, int width)
{
    long int num;
    char str[21]; /* Enough to hold long int in base 10 with sign */
    int i = 0, num_chars = 0;
    int len;

    if (length_mod.l)
        num = va_arg(list, long int);
    else if (length_mod.h)
        num = (short int)va_arg(list, int);
    else
        num = va_arg(list, int);

    itoa(num, str, 10);

    /* Handle width */
    len = strlen(str);
    if (width > len)
    {
        int pad = width - len;
        if (flags.plus || flags.space)
        {
            pad--;
        }
        for (i = 0; i < pad; i++)
        {
            _putchar(' ', buffer, index);
        }
    }

    /* Handle the space and plus flags */
    if (flags.plus && num >= 0)
    {
        _putchar('+', buffer, index);
        num_chars++;
    }
    else if (flags.space && num >= 0)
    {
        _putchar(' ', buffer, index);
        num_chars++;
    }

    i = 0;  /* Reset i to 0 for the next loop */
    while (str[i])
    {
        _putchar(str[i], buffer, index);
        i++;
        num_chars++;
    }

    return (num_chars + (width > len ? width - len : 0));
}
