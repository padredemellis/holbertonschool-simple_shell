#include "shellminator.h"
/**
 * ejecutar_comando - Función principal
 * @args: Array de argumentos
 * @command_count: Contador de comandos
 * @shell_name: nombre de la Shellminator
 */
int ejecutar_comando(char **args, int command_count, char *shell_name)
{
	pid_t pid;
	int status, exit_status;
	char *ruta_completa;

	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "exit") == 0)
	{
		manejar_comando_interno(args);
		return (0);
	}

	ruta_completa = buscar_ruta_comando(args[0]);
	if (!ruta_completa)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", shell_name, command_count, args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(ruta_completa);
		return (1);
	}

	if (pid == 0)
	{
		ejecutar_comando_externo(ruta_completa, args);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		free(ruta_completa);
	}
	return (exit_status);
}

