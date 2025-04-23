#include "shellminator.h"
/**
 * manejar_comando_interno - Maneja cd y exit
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
		exit(0);
	}
}
