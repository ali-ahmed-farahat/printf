#include "main.h"
/**
 * printing_int - function printing int and decimal nums
 * @x: the list to get the number from
 * Return: the number of characters (digits) printed
 */

int printing_int(va_list x)
{
int len = 0;
int pow = 0;
int j = 1;
int digit = 0;
int k = 0;
int size = 0;
int i = 0;

k = va_arg(x, int);
if (k != 0)
{
if (k < 0)
{
my_putchar('-');
size++;
k *= -1;
}
i = k;
while (i)
{
i = i / 10;
len++;
}
pow = 1;
while (j <= len - 1)
{
pow = pow * 10;
j++;
}
j = 1;
while (j <= len)
{
if (pow != 0)
digit = k / pow;
else
break;
my_putchar(digit + '0');
size++;
k = k - (digit * pow);
pow = pow / 10;
}
}
else
{
my_putchar('0');
return (1);
}
return (size);
}
