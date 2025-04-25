#include "shellminator.h"
#include <stdio.h>

/**
 * manejar_sigint - Maneja la señal SIGINT (Ctrl+C)
 * @sig: Número de la señal (no usado)
 */
void manejar_sigint(int sig)
{
	(void)sig;
	printf("\n");
	mostrar_prompt();
	fflush(stdout);
}
