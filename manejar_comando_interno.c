#include "shellminator.h"
/**
 * manejar_comando_interno - Maneja cd, exit y env
 * @args: Argumentos del comando
 */
void manejar_comando_interno(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (!args[1])
			fprintf(stderr, "cd: falta el argumento de directorio\n");
		else if (chdir(args[1]) != 0)
			perror("cd");
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			fprintf(stderr, "exit: demasiados argumentos\n");
		}
		else
		{
			exit(0);
		}
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (char **env = environ; *env; env++)
		{
			printf("%s\n", *env);
		}
	}
}
