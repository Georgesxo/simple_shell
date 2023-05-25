#include "shell.h"

/**
 * _getline-  handles line arguments
 * @array: parameter
 * @maxim: parameter
 * Return: a value
 */

int _getline(char array[], int maxim)
{
	int z, y = 0;

	while (--maxim > 0 && (z = getchar()) != EOF && z !='\n')
	{
		array[y++] = z;
		array[y] = '\0';
		return (y);
	}
