#include "header.h"

/**
 * my_putchar - printing a character
 * @c: the character to be printed
 * Return: void
 */

int my_putchar(char c)
{
write(1, &c, 1);
return (1);
}

/**
 * my_putchar_wrapper - converting data type to send to my_putchar
 * @args: the list to get the character from
 * Return: (1)
 */

int my_putchar_wrapper(va_list args)
{
    char c = va_arg(args, int);
    return my_putchar(c);
}
