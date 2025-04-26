#include "shellminator.h"

/**
 * analizar_entrada - Divide la entrada en tokens
 * @linea: Cadena de entrada a analizar
 * Return: Array de argumentos, NULL en caso de error
 */
char **analizar_entrada(char *linea)
{
	int i = 0, j;
	const int max_args = 64;
	char **args = malloc(max_args * sizeof(char *));
	char *copy_linea = strdup(linea);
	char *token;

	if (!args || !copy_linea)
	{
		perror("Error de asignacion de memoria");
		free(args);
		free(copy_linea);
		return (NULL);
	}

	token = strtok(copy_linea, " \t");
	while (token && i < max_args - 1)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup error");
			for (j = 0; j < i; j++)
				free(args[j]);
			free(args);
			free(copy_linea);
			return (NULL);
		}
		token = strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
	free(copy_linea);
	return (args);
}
