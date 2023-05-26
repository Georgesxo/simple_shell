#include "shell.h"

/**
 * portion- tokenises command line arguments
 * @lineptr: parameter
 * @args: parameter
 * @max: parameter
 * Return: nothing
 */

void portion(char *lineptr, char **args, int max)
{
	int counter = 0;
	char *token = strtok(lineptr, " \t\n");

	max = MAX;

	while (token != NULL && counter < max - 1)
	{
		args[counter++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[counter] = NULL;
}

