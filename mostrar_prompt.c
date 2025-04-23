#include "shellminator.h"

/**
 * mostrar_prompt - Muestra el prompt con el directorio actual.
 */
void mostrar_prompt(void)
{
	char ubicacion_actual[256];

	if (getcwd(ubicacion_actual, sizeof(ubicacion_actual)))
	{
		printf("%s SHELLMINATOR> ", ubicacion_actual);
	}
	else
	{
		perror("getcwd() error");
		printf("SHELLMINATOR> ");
	}
	fflush(stdout);
}
