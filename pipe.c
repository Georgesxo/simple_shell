#include "shell.h"

/**
 * h_pipe- handles pipes on the command line
 * @comands: parameter
 * Return: nothing
 */

void h_pipe(char *comands)
{
	int counter, child, fd[2], i;
	char *plist;

	counter = portion_argv(comands, "|", &plist);
	if (counter <= 0)
	{
		perror("portion_argv");
		exit(1);
	}

	for (i = 0; i < counter - 1; i++)
	{
		if (pipe(fd) == -1)
		{
			perror("Failed to create pipes");
			exit(1);
		}

		child = fork();
		if (child == -1)
		{
			perror("Failed to create process to run command");
			exit(1);
		}

		if (child)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			executedirect(plist[i + 1], 0, 1);
		}
	}
	executedirect(plist[i - 1], i == 1, 1);
	exit(1);
}
