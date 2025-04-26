#include "shellminator.h"
/**
 * ejecutar_comando_externo - Ejecuta el comando encontrado
 * @ruta_completa: Ruta validada
 * @args: Argumentos
 */
#include "shellminator.h"

void ejecutar_comando_externo(char *ruta_completa, char **args)
{
	if (execve(ruta_completa, args, environ) == -1)
	{
		fprintf(stderr, "%s: not found\n", args[0]);
		free(ruta_completa);
		exit(127);
	}
}
