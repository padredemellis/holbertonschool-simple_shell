#include "shellminator.h"
/**
 * ejecutar_comando_externo - Ejecuta el comando encontrado
 * @ruta_completa: Ruta validada
 * @args: Argumentos
 */
void ejecutar_comando_externo(char *ruta_completa, char **args)
{
	if (execve(ruta_completa, args, environ) == -1)
	{
		fprintf(stderr, "%s: comando no encontrado\n", args[0]);
	}
	free(ruta_completa);
	exit(EXIT_FAILURE);
}
