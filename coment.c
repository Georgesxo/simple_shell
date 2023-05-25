#include "shell.h"

/**
 * coment- handles comments on comand line
 * @argc: parameter
 * @argv: parameter
 * Return: nothing
 */

void coment(int *argc, char *argv[])
{
	int init, jee;

	for (init = 1; init < *argc; init++)
	{
		if (argv[init][0] == '#')
		{
			for (jee = init; jee < *argc - 1; jee++)
			{
				argv[jee] = argv[jee + 1];
			}
			(*argc)--;
			init--;
		}
	}
}
