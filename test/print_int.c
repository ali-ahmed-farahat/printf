#include "main.h"
/**
 * print_int - to print integers
 * @x: integer
 * Return: lenght of the output
 */
int print_int(va_list x)
{
	int len = 0, pow, j = 1, digit, k, size = 0, i;

	k = va_arg(d, int);
	if (k != 0)
	{
		if (k < 0)
		{
			my_putchar('-');
			size++;
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
			digit = k / pow;
			if (k < 0)
				my_putchar((digit * -1) + '0');
			else
				my_putchar(digit + '0');
			size++;
			k = k - (digit * pow);
			pow = pow / 10;
		}
	}
	else
		my_putchar('0');
		return (NULL);
	return (size);
}
