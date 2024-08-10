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

len1 = _printf("Hello %%\n");
len2 = printf("Hello %%\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%s\n", "This is a string");
len2 = printf("%s\n", "This is a string");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%c\n", 'A');
len2 = printf("%c\n", 'A');
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

/* Testing unknown specifier */
len1 = _printf("Unknown: [%r]\n");
len2 = printf("Unknown: [%%r]\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
