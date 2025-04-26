#include "shellminator.h"
/**
 * main - Punto de entrada del shell
 * Return: Siempre 0 (éxito)
 */
int main(void)
{
	char *linea;
	char **args;
	int i;

	signal(SIGINT, manejar_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			mostrar_prompt();
		}
		linea = leer_entrada();
		if (!linea)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
		}
		args = analizar_entrada(linea);
		free(linea);
		if (args)
		{
			ejecutar_comando(args);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
		free(args);
		}
	}
	return (0);
}
