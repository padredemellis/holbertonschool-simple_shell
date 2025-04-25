#include "shellminator.h"
#include <string.h>

/**
 * buscar_ruta_comando - Busca el comando en el PATH usando environ
 * @comando: Nombre del comando
 * Return: Ruta completa o NULL
 */
char *buscar_ruta_comando(char *comando)
{
	char *path_env = NULL;
	char *path_copy, *path_token, *ruta_completa = NULL;
	int i;

	for (i = 0; environ[i] != NULL; i++) {
		if (strncmp(environ[i], "PATH=", 5) == 0) {
			path_env = environ[i] + 5;
			break;
		}
	}

	if (strchr(comando, '/') || path_env == NULL) {
		return (strdup(comando));
	}

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	path_token = strtok(path_copy, ":");
	while (path_token) {
		int tam_ruta = strlen(path_token) + strlen(comando) + 2;
		ruta_completa = malloc(tam_ruta);

		if (!ruta_completa) {
			free(path_copy);
			return (NULL);
		}

		sprintf(ruta_completa, "%s/%s", path_token, comando);
		if (access(ruta_completa, X_OK) == 0)
			break;

		free(ruta_completa);
		ruta_completa = NULL;
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (ruta_completa);
}
