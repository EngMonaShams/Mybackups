#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * format_char - formats char
 * @separator: string separator
 * @ap: arg pointer
 */
void format_char(char *separator, va_list ap)
{
	printf("%s%c", separator, va_arg(ap, int));
}

/**
 * format_int - formats char
 * @separator: string separator
 * @ap: arg pointer
 */
void format_int(char *separator, va_list ap)
{
	printf("%s%d", separator, va_arg(ap, int));
}

/**
 * format_float - formats char
 * @separator: string separator
 * @ap: arg pointer
 */
void format_float(char *separator, va_list ap)
{
	printf("%s%f", separator, va_arg(ap, double));
}
/**
 * format_string - formats char
 * @separator: string separator
 * @ap: arg pointer
 */
void format_string(char *separator, va_list ap)
{
	char *str = va_arg(ap, char *);

	printf("%s%s", separator, str ? str : "(nil)");
}
/**
 * print_all - function to print all typer of data
 *
 * @format: function select
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *separator;
	token_t tokens[] = {
		{"c", format_char},
		{"i", format_int},
		{"f", format_float},
		{"s", format_string},
		{NULL, NULL}
	};

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (tokens[j].token)
		{
			if (format[i] == tokens[j].token[0])
			{
				tokens[j].f(separator, ap);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
