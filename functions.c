#include "main.h"

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
 * print_number - print an integer recursively
 * @n: The integer to print
 *
 * Return: the number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int printed_chars = 0;

	if (n < 0)
	{
		printed_chars += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10 != 0)
		printed_chars += print_number(num / 10);

	printed_chars += _putchar(num % 10 + '0');

	return (printed_chars);
}

/**
 * print_string - print a string
 * @str: The string to print
 *
 * Return: the number of characters printed
 */
int print_string(char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		printed_chars += _putchar(*str);
		str++;
	}

	return (printed_chars);
}

/**
 * print_char - print a character
 * @c: The character to print
 *
 * Return: the number of characters printed
 */
int print_char(char c)
{
	return (_putchar(c));
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
	int num;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' character */
			switch (*format)
			{
				case 'c':
					printed_chars += print_char(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					printed_chars += print_string(str);
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					printed_chars += print_number(num);
					break;
				case '%':
					printed_chars += print_char('%');
					break;
				default:
					printed_chars += print_char('%');
					printed_chars += print_char(*format);
					break;
			}
		}
		else
		{
			printed_chars += print_char(*format);
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}
