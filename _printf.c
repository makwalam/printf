#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to the standard output (stdout)
 * @c: The character to print
 *
 * Return: On success, 1 is returned. On error, -1 is returned,
 * and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' character */
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						printed_chars += _putchar(*str);
						str++;
					}
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}
