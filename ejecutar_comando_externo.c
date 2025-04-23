#include "shellminator.h"
/**
 * ejecutar_comando_externo - Ejecuta el comando encontrado
 * @ruta_completa: Ruta validada
 * @args: Argumentos
 */
void ejecutar_comando_externo(char *ruta_completa, char **args)
{
	execve(ruta_completa, args, environ);
	perror("execve error");
	free(ruta_completa);
	exit(EXIT_FAILURE);
}
