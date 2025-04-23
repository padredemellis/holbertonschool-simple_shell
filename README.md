# Simple_Shell: Shellminator

¡Es hora conocer a Shellminator! Este no es un androide del futuro, ¡pero nos ayuda como si fuera uno!
Shellminator es un intérprete de comandos sencillito, o sea, el traductor personal entre el usuario y la computadora.

Tú le escribes las órdenes a Shellminator y él, ¡zas!, se las pasa claritas a la PC para que se ponga manos a la obra.


## Instalación

*Compilación*

gcc -Wall -Werror -Wextra -pedantic *.c -o shellminatorgcc -Wall -Werror -Wextra -pedantic *.c -o shellminator

*Ejecución*

./shellminator
## Características principales

*Prompt interactivo:*
 Muestra el directorio actual seguido de SHELLMINATOR>.

Ejemplo:

/home/user/projects SHELLMINATOR> 

*Comandos Internos:*

cd [directorio]: Cambia de directorio.
Ejemplo:

cd Documents
exit: Cierra el shell.

*Comandos Externos: Ejecuta programas del sistema*
(ej: ls, echo, gcc).
Ejemplo:

ls -l

*Manejo de Errores:*

Si un comando no existe, muestra: <comando>: comando no encontrado.

Si cd falla, muestra el error del sistema.

Al salir con exit, muestra el estado de terminación.
## Uso básico


*Ejecutar un comando externo:*

/home/user SHELLMINATOR> ls -l
Salida:

total 4
-rw-r--r-- 1 user user  123 Jan 1 10:00 main.c

*Cambiar de directorio:*

/home/user SHELLMINATOR> cd Documents

*Nuevo prompt:*

/home/user/Documents SHELLMINATOR> 

*Salir del shell:*

/home/user SHELLMINATOR> exit

## Diagrama de flujo

[![shellminator.jpg](https://i.postimg.cc/grFwd4Ng/shellminator.jpg)](https://postimg.cc/FkpFVbtS)

## Corrida de escritorio

# Inicio del shell
/home/user SHELLMINATOR> ls
main.c  shellminator
# Ejecuta 'ls'
Estado: 0

/home/user SHELLMINATOR> cd no_existo
cd: No such file or directory  # Error de chdir()

/home/user SHELLMINATOR> hola
hola: comando no encontrado    # Comando inexistente
Estado: 127

/home/user SHELLMINATOR> exit  # Salir
## Pseudocódigo

FUNCIÓN main():
    MIENTRAS verdadero:
        mostrar_prompt()
        linea = leer_entrada()
        SI linea es NULL:
            imprimir("\n")
            salir(0)
        args = analizar_entrada(linea)
        SI args no es NULL:
            ejecutar_comando(args)
            liberar_memoria(args)
        liberar(linea)

FUNCIÓN ejecutar_comando(args):
    SI args[0] es "cd" o "exit":
        manejar_comando_interno(args)
    SINO:
        pid = fork()
        SI pid == 0:  # Proceso hijo
            ruta = buscar_ruta_comando(args[0])
            SI ruta existe:
                ejecutar_comando_externo(ruta, args)
            SINO:
                imprimir_error("comando no encontrado")
                salir(127)
        SINO:  # Proceso padre
            esperar_a_hijo(pid)
            mostrar_estado_salida()

FUNCIÓN buscar_ruta_comando(comando):
    SI comando contiene "/":
        retornar strdup(comando)
    path = obtener_variable("PATH")
    PARA cada directorio en path:
        ruta = directorio + "/" + comando
        SI archivo existe y es ejecutable:
            retornar ruta
    retornar NULL

##Autores
Emanuel Romero
Nahuel Bica

##Hasta la vista baby!
