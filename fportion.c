#include "shell.h"

/**
 * freeargv- free space that was dynamically allocated
 * @argv: parameter
 * Return: nothing
 */
void freeargv(char **argv)
{
	if (argv == NULL)
	{
		return;
	}
	if (*argv != NULL)
	{
		free(*argv);
	}
	free(argv);
}
