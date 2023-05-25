#include "shell.h"

/**
 * alias- handles alias on comand line
 * @args: parameter
 * Return: nothing
 */

void alias(char **args)
{
	if (args[1] == NULL)
	{
		printf("Usage: alias <name><value>\n");
	}

	else if (args[2] == NULL)
	{
		printf("%s = %s\n", args[1], getenv(args[1]));
	}

	else
	{
		setenv(args[1], args[2], 1);
	}
}
