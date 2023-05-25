#include "shell.h"

/**
 * exec_cmd- implements shell builtins
 * @args: parameter
 * Return: nothing
 */

void exec_cmd(char **args)
{
	if (strcmp(args[0], "alias") == 0)
	{
		alias(args);
	}

	else if (strcmp(args[0], "cd") == 0)
	{
		change_dir(args);
	}

	else if (strcmp(args[0], "exit") == 0)
	{
		exit_prog();
	}

	else
	{
		if (spawn(args[0], args) == -1)
		{
			perror(args[0]);
		}
	}
}

