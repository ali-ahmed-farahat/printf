#include "main.h"

/**
 * string_length - counting the string length
 * @str: the string to count
 * Return: the number of characters
 */

int string_length(char *str)
{
int i, size = 0;

for (i = 0; str[i] != '\0'; i++)
size++;

return (size);
}

/**
 * my_put_s - printing string
 * @string: the string to be printed
 * Return: the number of characters
 */

int my_put_s(char *string)
{
int counter = 0;

while (*string)
{
counter += my_putchar(*string);
string++;
}
return (counter);
}

/**
 * putting_string - delivering a string to my_put_s FUNC
 * @arguments: the list to get the string from
 * Return: the number of characters
 */

int putting_string(va_list arguments)
{
int counter = 0;
char *str = va_arg(arguments, char *);

if (str != NULL)
{
counter += my_put_s(str);
}
return (counter);
}
