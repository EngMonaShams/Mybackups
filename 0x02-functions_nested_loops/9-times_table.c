#include "main.h"

/**
 *  times_table- a prototype that prints the 9 times table
 *
 */

void times_table(void)
{
	int t, n, pr;

	for (t = 0; t < 10; t++)
	{
		_putchar(48);
		for (n = 1; n < 10; n++)
		{
			_putchar(',');
			_putchar(' ');
			pr = n * t;
			if (pr / 10 == 0)
				_putchar(' ');
			else
				_putchar('0' + pr / 10);
			_putchar('0' + pr % 10);
		}
	}
}
