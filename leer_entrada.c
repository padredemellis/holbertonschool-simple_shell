#include "shellminator.h"
/**
 * leer_entrada - Lee una línea de entrada estándar.
 * Return: Cadena leída o NULL en error.
 */
char *leer_entrada(void)
{
	char *linea = NULL;
	size_t tam_buff = 0;
	ssize_t resultado_getline;

	resultado_getline = getline(&linea, &tam_buff, stdin);

	if (resultado_getline == -1)
	{
		free(linea);
		return (NULL);
	}
	linea[strcspn(linea, "\n")] = '\0';
	return (linea);
}
