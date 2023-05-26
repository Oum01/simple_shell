#include "shell.h"

/**
 * _put_number_helper - function that helps
 * _put_number to print given number
 *
 * @fd: file descriptor
 * @number: number to be printed
 * Return: (void)
 */
void _put_number_helper(int fd, int number)
{
	char c;

	if (!number)
		return;
	_put_number_helper(fd, number / 10);
	c = number % 10 + 48;
	write(fd, &c, 1);
}

/**
 * _put_number - function that will print
 * number to fd
 *
 * @fd: file descriptor
 * @number: number to be printed
 * Return: (void)
 */
void _put_number(int fd, int number)
{
	char c;

	if (number == 0)
	{
		c = number + '0';
		write(fd, &c, 1);
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	_put_number_helper(fd, number);
}

/**
 * _puts - function that print given string
 * into given file descriptor
 * @fd: file descriptor
 * @s: string
 * Return: (void)
 */
void _puts(int fd, char *s)
{
	write(fd, s, _strlen(s));
}

/**
 * _fprintf - function that will print given
 * string and parameters following
 * the given format and specifiers
 *
 * @fd: file descriptor
 * @format: format to follow
 * Return: (void)
 */
void _fprintf(int fd, const char *format, ...)
{
	int iter;
	int is_percent;
	va_list ap;

	iter = 0;
	is_percent = 0;
	va_start(ap, format);
	while (format[iter])
	{
		if (format[iter] == '%')
			is_percent = 1;
		else if (is_percent)
		{
			if (format[iter] == 'd')
				_put_number(fd, va_arg(ap, int));
			else if (format[iter] == 's')
				_puts(fd, va_arg(ap, char *));
			else
			{
				write(fd, &format[iter], 1);
			}
			is_percent = 0;
		}
		else
			write(fd, &format[iter], 1);

		iter++;
	}
	va_end(ap);
}
