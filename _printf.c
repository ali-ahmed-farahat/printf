#include "main.h"
/**
 * get_spc - function getting the specifier and
 * the function needed to print this specifer data type
 * @format: the string containing the specifier
 * Return: the number of characters (digits) printed
 */

int (*get_spc(const char *format))(va_list)
{
int i = 0;
spcc sppc[] = {
{"c", my_putchar_wrapper},
{"s", putting_string},
{"i", printing_int},
{"d", printing_int},
{NULL, NULL}
};

while (sppc[i].conversion_spc)
{
if (sppc[i].conversion_spc[0] == (*format))
return (sppc[i].f);
i++;
}
return (NULL);
}

/**
 * _printf - function printing int,decimal, strings and characters
 * @format: the string of passed arguments
 * Return: the number of characters (digits) printed
 */

int _printf(const char *format, ...)
{
va_list args;
int (*func_getter)(va_list);
int j = 0;
int counter = 0;

if (format == NULL)
return (-1);

va_start(args, format);
while (format[j])
{

while (format[j] != '%' && format[j])
{
my_putchar(format[j]);
counter++;
j++;
}
if (format[j] == '\0')
return (counter);

func_getter = get_spc(&format[j + 1]);
if (func_getter != NULL)
{
counter += func_getter(args);
j += 2;
continue;
}

if (!format[j + 1])
return (-1);

my_putchar(format[j]);
counter++;

if (format[j + 1] == '%')
j += 2;

else
j++;
}

va_end(args);
return (counter);
}
