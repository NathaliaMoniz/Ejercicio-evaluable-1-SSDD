#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "claves.h"



#include <stdio.h>

int main() {
    FILE *fptr;

    // Usamos "w" para crear un archivo para escritura
    fptr = fopen("archivo.txt", "w");

    if (fptr == NULL) {
        printf("Error al abrir el archivo!");
        return 1;
    }

    // Escribimos en el archivo
    fprintf(fptr, "Hola, mundo!");

    // Cerramos el archivo
    fclose(fptr);

    return 0;
}


