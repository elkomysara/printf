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

len1 = _printf("Number: %d\n", 12345);
len2 = printf("Number: %d\n", 12345);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

len1 = _printf("Negative Number: %i\n", -12345);
len2 = printf("Negative Number: %i\n", -12345);
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
