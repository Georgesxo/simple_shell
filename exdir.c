#include "shell.h"

/**
 * exedir- handles redirection in and out
 * @s: parameter
 * @ini: parameter
 * @outi: parameter
 * Return: nothing
 */

void exedir(char *s, int ini, int outi)
{
	char **argv;

	if (ini && outi)
	{
		if (padiri(s) == -1)
		{
			perror("Failed to redirect input");
			return;
		}

		if (padiro(s) == -1)
		{
			perror("Failed to redirect output");
			return;
		}
	}

	else if (ini && (padiri(s) == -1))
	{
		perror("Failed to redirect input");
		return;
	}

	else if (outi && (padiro(s) == -1))
	{
		perror("Failed to redirect output");
		return;
	}

	if (portion_argv(s, " \t", &argv) <= 0)
	{
		perror("Failed to pass command");
		return;
	}

	execve(argv[0], argv, NULL);
	perrr("Failed to execute command");
	exit(1);
}


