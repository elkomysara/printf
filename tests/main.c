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
int num = -12345;
int max = INT_MAX;
int min = INT_MIN;

len1 = _printf("Hello %%\n");
len2 = printf("Hello %%\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%s\n", NULL);
len2 = printf("%s\n", NULL);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("%%\n");
len2 = printf("%%\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Unsupported specifier: %q\n");
len2 = printf("Unsupported specifier: %q\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Number: %d\n", num);
len2 = printf("Number: %d\n", num);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Number: %i\n", num);
len2 = printf("Number: %i\n", num);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Max int: %d\n", max);
len2 = printf("Max int: %d\n", max);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Min int: %d\n", min);
len2 = printf("Min int: %d\n", min);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
