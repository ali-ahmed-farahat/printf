#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
typedef struct spc{
char *conversion_spc;
int (*f)(char *format, va_list);
}spcc;

int my_putchar(char c)
{
write(1, &c, 1);
return (1);
}

int my_putchar_wrapper(va_list args)
{
    char c = va_arg(args, int);
    return my_putchar(c);
}

int string_length(char *str)
{
int i, size = 0;

for (i = 0; str[i] != '\0'; i++)
size++;

return (size);
}


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

int (*get_spc(const char *format))(va_list)
{
int i = 0;
spcc sppc[] = {
{"c", my_putchar_wrapper},
{"s", putting_string},
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

int main(void)
{
int printed;
char *name1 = "anas";
char *name2 = "ali";
char character = 'a';
printed += _printf("%%");
printed += _printf("This is a simple sentence\n");
printed += _printf("%s - %s\n", name1, name2);
printed += _printf("%% is the key\n");
printed += _printf("my intials are %c and %c\n", character, 'a');
printed += _printf("%c is printed, %c", character, character);
printf("%d is the number of characters printed", printed);
return (0);
