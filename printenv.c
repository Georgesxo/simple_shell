#include "shell.h"

/**
 * print_env- prints environment
 * Return: nothing
 */

void print_env(void)
{
	int counter;
	extern char **environ;

	for (counter = 0; environ[counter] != NULL; i++)
	{
		printf("%s\n", environ[counter]);
	}
}
