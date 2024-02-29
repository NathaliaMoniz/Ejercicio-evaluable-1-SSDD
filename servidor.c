#include <mqueue.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "claves.h"
#include "message.h"



void tratar_peticion(){

}

int main(void){
    mqd_t q_servidor;       /* Cola del servidor */
    struct mq_attr q_attr;  /* Atributos de la cola*/
    pthread_attr_t t_attr;  /* Atributos de los hilos*/
    pthread_t thid;         /* ID del hilo*/

    // abrir la cola
    q_servidor = mq_open("/COLA_SERVIDOR", O_CREAT|O_RDONLY, 0700, &q_attr);

    // tratamiento de error
    if(q_servidor == -1){
        perror("No se ha podido crear la cola del servidor");
        return -1;
    }

    // recibir el mensaje de la cola
    mq_receive(q_servidor, "donde se va a guardar el mensaje", "tamaño del sitio donde se va a guardar el mensaje", 0);

}

