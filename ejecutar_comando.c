#include "shellminator.h"
/**
 * ejecutar_comando - Función principal
 * @args: Array de argumentos
 */
void ejecutar_comando(char **args)
{
	pid_t pid;
	int status;
	char *ruta_completa;

	if (!args || !args[0])
		return;

	if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "exit") == 0)
	{
		manejar_comando_interno(args);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		return;
	}
	if (pid == 0)
	{
		ruta_completa = buscar_ruta_comando(args[0]);
		if (ruta_completa)
		{
			ejecutar_comando_externo(ruta_completa, args);
			return;
		}
		fprintf(stderr, "%s: not found\n", args[0]);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
