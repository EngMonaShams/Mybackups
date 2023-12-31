#include <stdlib.h>
#include "main.h"

/**
 * get_sign - function to get sign
 * @s: input string
 *
 * Return: sign
 */
int get_sign(const char *s)
{
	unsigned long int i;
	int sign = 1;

	for (i = 0; !(s[i] >= 48 && s[i] <= 57); i++)
		if (s[i] == '-')
			sign *= -1;
	return (sign);
}
/**
 * _atoi - afunction that convert srting to int
 * @s: input string
 *
 * Return: n
 */
unsigned long int _atoi(const char *s)
{
	unsigned long int resp = 0, i;
	int sign = 1;

	for (i = 0; !(s[i] >= 48 && s[i] <= 57); i++)
		if (s[i] == '-')
			sign *= -1;
	for (; s[i] >= 48 && s[i] <= 57; i++)
	{
		resp *= 10;
		resp += (s[i] - 48);
	}
	return (resp);
}

/**
 * _puts - a function that prints string
 *
 * @m: string
 */
void _puts(char *m)
{
	int i = 0;

	while (m[i])
	{
		_putchar(m[i]);
		i++;
	}
}

/**
 * print_int - function that prints an int
 *
 * @n: int
 */

void print_int(unsigned long int n)
{
	unsigned long int divisor = 1, i, resp;

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;
	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
}

/**
 * main -  a program that multiplies two positive numbers.
 *
 * @argc: int
 * @argv: list
 * Return: 0
 */

int main(int argc, char const *argv[])
{
	int si = 1;
	(void)argc;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}
	si = get_sign(argv[1]) * get_sign(argv[2]);
	if (si == -1)
		_putchar('-');
	print_int(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');

	return (0);
}
