#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function implementation.
 * @format: The format string containing the placeholders.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char ch = va_arg(args, int);
                write(1, &ch, 1);
                chars_printed++;
            }
        }
        else
        {
            write(1, format, 1);
            chars_printed++;
        }

        format++;
    }

    va_end(args);
    return (chars_printed);
}

