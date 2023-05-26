#include "shell.h"

/**
 * main- handles command line arguments
 * @argc: parameter
 * @argv: parameter
 * Return: a value
 */

int main(int argc, char **argv, char *envp[])
{
	char *cmpompt = "#cisfun$ ";
	char *lineptr = malloc(maxlines * sizeof(char));
	size_t n = 0;
	ssize_t char_read;
	int child_process;
	char *path;
	char const *args[MAX];
	args = (char *)malloc(sizeof(char *) * argc);
	(void)argv;

	path = get_fpath(envp);
	if (path == NULL)
	{
		perror("path");
		return (-1);
	}

	if (lineptr == NULL)
	{
		perror("lineptr");
		return (-1);
	}

	if (args == NULL)
	{
		perror("args");
		return (-1);
	}

	while (1)
	{
		printf("%s ", cmpompt);
		char_read = getline(&lineptr, &n, stdin);

		if (char_read == -1)
		{
			printf("Exiting Shell......\n");
			return (-1);
		}
		portion(lineptr, args, MAX);
		if (args[0] != NULL && access(args[0], X_OK) == -1)
		{
			printf("%s: command not found\n", args[0]);
			continue;
		}

		child_process = spawn_f(lineptr, args);

		if (child_process == -1)
		{
			perror("spawn");
			return (-1);
		}
	}

	free(lineptr);
	free(path);
	return (0);
}
