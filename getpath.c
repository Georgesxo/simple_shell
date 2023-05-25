#include "shell.h"

/**
 * get_fpath- get full path to user command
 * @comand: parameter
 * Return: null
 */

char *get_fpath(char *comand)
{
	char *cmd_path = NULL, *fpath = NULL, *path = getenv("PATH");
	size_t fpath_len, cmd_len;
	char *p, *q;

	fpath = strtok(path, ":");
	while (fpath)
	{
		fpath_len = strlen(fpath);
		cmd_len = strlen(comand);
		cmd_path = malloc(fpath_len + cmd_len + 2);
		if (cmd_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		*p++ = '/';
		for (q = comand; *q != '\0'; ++q)
		{
			*p++ = *q;
		}

		*p = '\0';
		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}

		free(cmd_path);
		fpath = strtok(NULL, ":");
	}
	return (NULL);
}
