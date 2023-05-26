#include "shell.h"

/**
 * spawn_f- function that create child process and execute commands
 * @comand: parameter
 * @args: parameter
 * Return: a value
 */

int spawn_f(char *comand, char **args)
{
	pid_t pid;
	int status;
	char *full_path = get_fpath(comand);

	if (full_path == NULL)
	{
		perror("Command not found");
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	else if (pid == 0)
	{
		execve(full_path, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}

	else
	{
		do {
			waitpid(pid, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(full_path);
	return (0);
}
