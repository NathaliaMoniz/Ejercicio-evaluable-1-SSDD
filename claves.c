/* implementacion de servicios */
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "message.h"
#include "claves.h"
#include "./lista/list.h"


int init(){
    
    // /* Inicializar la cola del cliente */

    // char q_client_name[MAX];                            // Nombre de la cola cliente  
    // sprintf(q_client_name,  "/Cola-%d", getpid());      // El combre de la cola del cliente será el pid del proceso

    // char q_server_name[MAX];                            // Nombre de la cola servidor  
    // sprintf(q_server_name,  "/Cola-%d", getplogin());   // El combre de la cola del servidor será el nombre del usuario

    // mqd_t q_client;               // Cola del cliente
    // mqd_t q_server;               // Cola del servidor
    // struct message mensaje;       // Mensaje a enviar
    // struct mq_attr attributes;    // Atributos de la cola

    // attributes.mq_flags = 0;
    // attributes.mq_maxmsg = 1;
    // attributes.mq_msgsize = sizeof(mensaje);
    // attributes.mq_curmsgs = 0;

    // q_client = mq_open(q_client_name, O_CREAT, O_RDONLY, 0700, &attributes); // Se abre la cola del cliente para leer la respuesta del servidor
    // if (q_client == -1){
    //     perror("Error al abrir la cola del cliente");
    //     return -1;
    // }

    // q_server = mq_open(q_server_name, O_WRONLY); // Se abre la cola del servidor del cliente para escribir en ella el mensaje
    // if (q_server == -1){
    //     perror("Error al abrir la cola del servidor");
    //     return -1;
    // }
    
    // return 0;

    // Usamos remove() para borrar el archivo
    if (remove("archivo.txt") == 0)
        printf("El archivo ha sido borrado exitosamente\n");
    else
        printf("No se pudo borrar el archivo\n");
}
int set_value2(){
    
    FILE *fptr;
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
int set_value(int key, char *value1, int N_value2, double *V_value2){
    
    
}

int get_value(int key, char *value1, int *N_value2, double *V_value2){
    
    
}

int modify_value(int key, char *value1, int N_value2, double *V_value2){
    
    
}

int delete_key(int key){

}
int exist(int key){

}

int main(int argc, char *argv[]){
    
}