#include "shell.h"

/**
 * semi- handles semicolon on comand line
 * @cmd: parameter
 * Return: nothing
 */

char semi(char *cmd)
{
	char *portion = strtok(cmd, ";");

	while (portion != NULL)
	{
		printf("Executing: %s\n", portion);
		portion = strtok(NULL, ";");
	}
}
