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

len1 = _printf(NULL);
len2 = printf(NULL);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Hello %%");
len2 = printf("Hello %%");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%s", NULL);
len2 = printf("%s", NULL);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%%");
len2 = printf("%%");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Unsupported specifier: %q\n");
len2 = printf("Unsupported specifier: %q\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
