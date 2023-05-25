#include "shell.h"

/**
 * vreplace- handles replacement comand line
 * @argc: parameter
 * @argv: parameter
 * Return: nothing
 */

void vreplace(int argc, char *argv[])
{
	char *arg, *val;
	int count, val_int;

	for (count = 1; count < argc; count++)
	{
		arg = argv[count];
		if (strcmp(arg, "$?") == 0)
		{
			val_int = WEXITSTATUS(system(NULL));
			val = itoa(val_int, (char *)malloc(sizeof(char) * 10), 10);
			argv[count] = val;
		}
		else if (strcmp(arg, "$$") == 0)
		{
			val_int = getpid();
			val = itoa(val_int, (char *)malloc(sizeof(char) * 10), 10);
			argv[count] = val;
		}
	}
}
