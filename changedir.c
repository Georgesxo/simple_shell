#include "shell.h"

/**
 * change_dir- handles change in directory on command line
 * @args: parameter
 * Return: nothing
 */

void change_dir(char **args)
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
	}

	else
	{
		if (chdir(args[1] != 0))
				{
					perror("cd");
				}
	}
}
