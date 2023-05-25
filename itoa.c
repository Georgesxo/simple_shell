#include "shell.h"

/**
 * itoa- handles integer value to a null terminated string
 * @str: parameter
 * @bas: parameter
 * @val: parameter
 * Return: a string
 */

char *itoa(int val, char *str, int bas)
{
	char *alphanum = "0123456789ABCDEF";
	char *container = str, tempo, *p;
	int a = value < 0;
	int b = base == 10;

	if (a && b)
	{
		*container++ = '-';
		val = -val;
	}

	do {
		*container++ = alphanum[val % bad];
		val /= bas;
	} while (val);

	*container-- = '\0';

	p = str;
	while (p < container)
	{
		tempo = *p;
		*p++ = *container;
		*container-- = tempo;
	}
	return (str);
}
