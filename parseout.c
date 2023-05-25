#include "shell.h"

/**
 * padiro- handles output redirection
 * @comand: parameter
 * Return: a value
 */

int padiro(char *comand)
{
	int outfd, error;
	char *outfil = strchr(comand, '>');
	if (!outfil)
	{
		return (0);
	}

	*outfil++ = '\0';
	outfil = strtok(outfil, " \t");
	if (!outfil)
	{
		return (0);
	}

	outfd = open(outfil, FFLAG, FMODE);
	if (outfd == -1)
	{
		return (-1);
	}

	if (dup2(outfd, STDOUT_FILENO) == -1)
	{
		error = errno;
		close(outfd);
		errno = error;
		return (-1);
	}
	close(outfd);
	return (0);
}
