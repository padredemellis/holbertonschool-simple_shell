#include "shellminator.h"
/**
 * main - Punto de entrada del shell
 * Return: Siempre 0 (éxito)
 */
int main(void)
{
	char *linea;
	char **args;

	while (1)
	{
		mostrar_prompt();
		linea = leer_entrada();
		if (!linea)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		args = analizar_entrada(linea);
		if (args)
		{
			ejecutar_comando(args);
			for (int i = 0; args[i] != NULL; i++)
				free(args[i]);
		free(args);
		}
		free(linea);
	}
	return (0);
}
