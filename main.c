#include "shellminator.h"

/**
 * main - Punto de entrada principal
 * @argc: Contador de argumentos
 * @argv: Argumentos
 * Return: Estado de salida
 */
int main(int argc, char **argv)
{
	char *linea;
	char **args;
	int i, last_status = 0;
	int command_count = 0;
	char *shell_name = argv[0];

	(void)argc;
	atexit(liberar_recursos);
	signal(SIGINT, manejar_sigint);

	while (1)
	{
		command_count++;
		if (isatty(STDIN_FILENO))
			mostrar_prompt();
		linea = leer_entrada();
		if (!linea)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(last_status);
		}
		args = analizar_entrada(linea);
		free(linea);
		if (args)
		{
			last_status = ejecutar_comando(args, command_count, shell_name);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
		}
	}
	return (0);
}
