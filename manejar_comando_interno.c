#include "shellminator.h"
char *oldpwd = NULL;
/**
 * liberar_recursos - Libera memoria de variables globales
 */
void liberar_recursos(void)
{
	free(oldpwd);
	oldpwd = NULL;
}

/**
 * manejar_comando_interno - Maneja cd, exit y env
 * @args: Argumentos del comando
 */
void manejar_comando_interno(char **args)
{
	char *new_pwd, **env;

	if (strcmp(args[0], "cd") == 0)
	{
		if (!args[1] || strcmp(args[1], "~") == 0)
			new_pwd = getenv("HOME");
		else if (strcmp(args[1], "-") == 0)
			new_pwd = oldpwd ? oldpwd : getenv("PWD");
		else
			new_pwd = args[1];
		if (chdir(new_pwd) != 0)
			perror("cd");
		else
		{
			free(oldpwd);
			oldpwd = strdup(getenv("PWD"));
		}
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		liberar_recursos();
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (env = environ; *env; env++)
			printf("%s\n", *env);
	}
}
