#include "../main.h"
#include <stdio.h>

/**
* main - Entry point for testing the _printf function
*
* Return: Always 0
*/
int main(void)
{
int len1, len2;
unsigned int ui = 4294967295; /* UINT_MAX */

len1 = _printf("Unsigned: %u\n", ui);
len2 = printf("Unsigned: %u\n", ui);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Octal: %o\n", ui);
len2 = printf("Octal: %o\n", ui);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Hex (lowercase): %x\n", ui);
len2 = printf("Hex (lowercase): %x\n", ui);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Hex (uppercase): %X\n", ui);
len2 = printf("Hex (uppercase): %X\n", ui);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
