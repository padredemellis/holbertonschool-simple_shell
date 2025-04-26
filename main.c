#include "shellminator.h"
/**
 * main - Punto de entrada del shell
 * @argc: contador de argumentos
 * @argv: argumentos
 * Return: Siempre 0 (éxito)
 */
#include "shellminator.h"
#include "shellminator.h"

int main(int argc, char **argv)
{
	char *linea;
	char **args;
	int i, status;
	int command_count = 0;
	char *shell_name = argv[0];

	(void)argc;

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
			exit(EXIT_SUCCESS);
		}
		args = analizar_entrada(linea);
		free(linea);
		if (args)
		{
			status = ejecutar_comando(args, command_count, shell_name);

			if (!isatty(STDIN_FILENO))
				exit(status);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
		}
	}
	return (0);
}
