#include "shellminator.h"

/**
 * analizar_entrada - Divide la entrada en tokens.
 * @linea: Cadena de entrada a analizar.
 * Return: Array de argumentos, NULL en caso de error.
 */
char **analizar_entrada(char *linea)
{
	int i = 0, j;
	const int max_args = 64;
	char **args = malloc(max_args * sizeof(char *));
	char *token;

	if (!args)
	{
		perror("Error de asignacion de memoria");
		return (NULL);
	}
	token = strtok(linea, " ");

	while (token && i < max_args - 1)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup error");
			for (j = 0; j < i; j++)
				free(args[j]);
		free(args);
		return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}
