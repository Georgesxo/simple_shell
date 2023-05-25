#include "shell.h"

/**
 * portion_argv- apportion command line arguments
 * @str: parameter
 * @dilim: parameter
 * @argvp: parameter
 * Return: number of tokens apportioned
 */

int portion_argv(const char *str, const char *dilim, char ***argvp)
{
	int counter, tokens = 0;
	char *tbuffer;
	const char *newstring;

	if ((dilim == NULL) || (str == NULL) || (argvp == NULL))
	{
		return (-1);
	}

	*argvp = NULL;
	newstring = str + strspn(str, dilim);
	if ((tbuffer = malloc(strlen(newstring) + 1)) == NULL)
	{
		return (-1);
	}

	strcpy(tbuffer, newstring);
	if (strtok(tbuffer, dilim) != NULL)
	{
		for (tokens = 1; strtok(NULL, dilim) != NULL; tokens++);
	}

	if ((*argvp = malloc((tokens + 1) * sizeof(char *)) == NULL))
	{
		free(tbuffer);
		return (-1);
	}

	if (tokens == 0)
	{
		free(tbuffer);
	}
	else
	{
		strcpy(tbuffer, newstring);
		**argvp = strtok(tbuffer, dilim);
		for (counter = 1; counter < tokens; counter++)
		{
			*((*argvp) + i) = strtok(NULL, dilim);
		}
	}

	*((*argvp) + tokens) = NULL;
	return (tokens);
}
