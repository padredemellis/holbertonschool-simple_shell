#include "shellminator.h"
/**
 * manejar_comando_interno - Maneja cd, exit y env
 * @args: Argumentos del comando
 */
#include "shellminator.h"

void manejar_comando_interno(char **args)
{
	char *oldpwd = NULL;
	char *new_pwd;

	if (strcmp(args[0], "cd") == 0)
	{
		if (!args[1] || strcmp(args[1], "~") == 0)
		{
			new_pwd = getenv("HOME");
		}
		else if (strcmp(args[1], "-") == 0)
		{
			new_pwd = oldpwd ? oldpwd : getenv("PWD");
		}
		else
		{
			new_pwd = args[1];
		}
		if (chdir(new_pwd) != 0)
		{
			perror("cd");
			return;
		}
		free(oldpwd);
		oldpwd = getenv("PWD");
		if (oldpwd)
			oldpwd = strdup(oldpwd);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (char **env = environ; *env; env++)
		{
			printf("%s\n", *env);
		}
	}
}
