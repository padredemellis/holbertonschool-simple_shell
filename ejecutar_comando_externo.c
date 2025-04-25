#include "shellminator.h"
/**
 * ejecutar_comando_externo - Ejecuta el comando encontrado
 * @ruta_completa: Ruta validada
 * @args: Argumentos
 */
void ejecutar_comando_externo(char *ruta_completa, char **args)
{
	if (access(ruta_completa, X_OK) == 0)
	{
		execve(ruta_completa, args, environ);
		perror("execve error");
	}
	else
	{
		fprintf(stderr, "%s: comando no encontrado\n", args[0]);
	}
	free(ruta_completa);
	exit(EXIT_FAILURE);
}
