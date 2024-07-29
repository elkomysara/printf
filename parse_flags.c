#include "main.h"

flags_t parse_flags(const char *format, int *i)
{
    flags_t flags = {0, 0, 0};

    while (format[*i])
    {
        if (format[*i] == '+')
            flags.plus = 1;
        else if (format[*i] == ' ')
            flags.space = 1;
        else if (format[*i] == '#')
            flags.hash = 1;
        else
            break;
        (*i)++;
    }

    return flags;
}
