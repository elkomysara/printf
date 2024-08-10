/**
 * convert - Converts a number to a string in the given base
 * @num: The number to be converted
 * @base: The base to convert to
 * @lowercase: Flag to determine if hex letters should be lowercase
 * Return: A pointer to the converted string (static buffer)
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char buffer[50];
    char *ptr;
    char *rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";

    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}
