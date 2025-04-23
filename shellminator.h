#ifndef SHELLMINATOR_H
#define SHELLMINATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void mostrar_prompt(void);
char *leer_entrada(void);
char **analizar_entrada(char *linea);
void ejecutar_comando(char **args);
void manejar_comando_interno(char **args);
char *buscar_ruta_comando(char *comando);
void ejecutar_comando_externo(char *ruta_completa, char **args);

#endif /* SHELLMINATOR_H */
