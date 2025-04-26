#include "shellminator.h"

/**
 * buscar_ruta_comando - Busca el comando en el PATH
 * @comando: Nombre del comando
 * Return: Ruta completa o NULL
 */
char *buscar_ruta_comando(char *comando)
{
	char *path_env = NULL, *path_copy, *path_token, *ruta_completa = NULL;
	char *saveptr = NULL;
	int i, tam_ruta;

	if (strchr(comando, '/'))
	{
		if (access(comando, X_OK) == 0)
			return (strdup(comando));
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	path_token = strtok_r(path_copy, ":", &saveptr);
	while (path_token)
	{
		tam_ruta = strlen(path_token) + strlen(comando) + 2;
		ruta_completa = malloc(tam_ruta);

		if (!ruta_completa)
		{
			free(path_copy);
			return (NULL);
		}

		snprintf(ruta_completa, tam_ruta, "%s/%s", path_token, comando);
		if (access(ruta_completa, X_OK) == 0)
			break;

		free(ruta_completa);
		ruta_completa = NULL;
		path_token = strtok_r(NULL, ":", &saveptr);
	}

	free(path_copy);
	return (ruta_completa);
}
