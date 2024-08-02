#include "main.h"

length_mod_t parse_length_mod(const char *format, int *i)
{
    length_mod_t length_mod = {0, 0};

    if (format[*i] == 'l')
    {
        length_mod.l = 1;
        (*i)++;
    }
    else if (format[*i] == 'h')
    {
        length_mod.h = 1;
        (*i)++;
    }

    return length_mod;
}
