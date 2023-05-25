#include "shell.h"

/**
 * main- handles command line arguments
 * @argc: parameter
 * @argv: parameter
 * Return: a value
 */

int main(int argc, char **argv)
{
	char *cmpompt = " $ ";
	char *lineptr;
	size_t n = 0;
	ssize_t char_read;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s ", cmpompt);
		char_read = getline(&lineptr, &n, stdin);

		if (char_read == -1)
		{
			printf("Exiting Gshell......\n");
			return (-1);
		}
		printf("%s \n", lineptr);
	}

	free(lineptr);
	return (0);
}
