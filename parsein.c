#include "shell.h"

/**
 * padiri- handles input redirection
 * @comand: parameter
 * Return: a value
 */

int padiri(char *comand)
{
	int infd, error;
	char *infil = strchr(comand, '<');
	if (!infil)
	{
		return (0);
	}

	*infil++ = '\0';
	infil = strtok(infil, " \t");
	if (!infil)
	{
		return (0);
	}

	infd = open(infil, O_RDONLY);
	if (infd == -1)
	{
		return (-1);
	}

	if (dup2(infd, STDIN_FILENO) == -1)
	{
		error = errno;
		close(infd);
		errno = error;
		return (-1);
	}
	close(infd);
	return (0);
}
