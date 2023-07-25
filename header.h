#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct spc - structure format
 * @conversion_spc: specifier
 * @f: function associated
 */

typedef struct spc{
char *conversion_spc;
int (*f)(char *format, va_list);
}spcc;

int my_putchar(char c);
int my_putchar_wrapper(va_list args);
int string_length(char *str);
int my_put_s(char *string);
int putting_string(va_list arguments);
int printing_int(va_list x);
int (*get_spc(const char *format))(va_list);
int _printf(const char *format, ...);

#endif // HEADER_H

