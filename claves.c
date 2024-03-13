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
    int res;
    /* Inicializar la cola del cliente */

    char q_client_name[MAX];                            // Nombre de la cola cliente  
    sprintf(q_client_name,  "/Cola-%d", getpid());      // El combre de la cola del cliente será el pid del proceso

    char q_server_name[MAX];                            // Nombre de la cola servidor  
    sprintf(q_server_name,  "/Cola-%s", getlogin());   // El combre de la cola del servidor será el nombre del usuario

    mqd_t q_client;               // Cola del cliente
    mqd_t q_server;               // Cola del servidor
    struct message mensaje;       // Mensaje a enviar
    struct mq_attributes attributes;    // Atributos de la cola

    attributes.mq_flags = 0;
    attributes.mq_maxmsg = 1;
    attributes.mq_msgsize = sizeof(mensaje);
    attributes.mq_curmsgs = 0;

    q_client = mq_open(q_client_name, O_CREAT | O_RDONLY, 0700, &attributes); // Se abre la cola del cliente para leer la respuesta del servidor
    if (q_client == -1){
        perror("Error al abrir la cola del cliente");
        return -1;
    }

    q_server = mq_open(q_server_name, O_WRONLY); // Se abre la cola del servidor del cliente para escribir en ella el mensaje
    if (q_server == -1){
        perror("Error al abrir la cola del servidor");
        return -1;
    }

    mensaje.op = 0;
    strcpy(mensaje.q_name, q_client_name);
    if (mq_send(q_server, (const char *)&mensaje, sizeof(mensaje), 0) < 0){
		perror("Error de mq_send");
		return -1;
	}
    if (mq_receive(q_client, (char *) &res, sizeof(struct message), 0) < 0){
		perror("Error mq_recv init");
        
		return -1;
	}
    printf("Resultado = %d\n", res);

    mq_close(q_server);
    mq_close(q_client);
    mq_unlink(q_client_name);
    return 0;
    
}

int set_value(int key, char *value1, int N_value2, double *V_value2){
    int res;
    /* Inicializar la cola del cliente */

    char q_client_name[MAX];                            // Nombre de la cola cliente  
    sprintf(q_client_name,  "/Cola-%d", getpid());      // El combre de la cola del cliente será el pid del proceso

    char q_server_name[MAX];                            // Nombre de la cola servidor  
    sprintf(q_server_name,  "/Cola-%s", getlogin());   // El combre de la cola del servidor será el nombre del usuario

    mqd_t q_client;               // Cola del cliente
    mqd_t q_server;               // Cola del servidor
    struct message mensaje;       // Mensaje a enviar
    struct mq_attributes attributes;    // Atributos de la cola

    attributes.mq_flags = 0;
    attributes.mq_maxmsg = 1;
    attributes.mq_msgsize = sizeof(mensaje);
    attributes.mq_curmsgs = 0;

    q_client = mq_open(q_client_name, O_CREAT | O_RDONLY, 0700, &attributes); // Se abre la cola del cliente para leer la respuesta del servidor
    if (q_client == -1){
        perror("Error al abrir la cola del cliente");
        return -1;
    }

    q_server = mq_open(q_server_name, O_WRONLY); // Se abre la cola del servidor del cliente para escribir en ella el mensaje
    if (q_server == -1){
        perror("Error al abrir la cola del servidor");
        return -1;
    }

    mensaje.op = 1;
    mensaje.key = key;
    strcpy(mensaje.value1, value1);
    mensaje.N_value2 = N_value2;
    memcpy(mensaje.V_value2, V_value2, N_value2 * sizeof(double));

    strcpy(mensaje.q_name, q_client_name);

    if (mq_send(q_server, (const char *)&mensaje, sizeof(mensaje), 0) < 0){
		perror("Error de mq_send");
		return -1;
	}
    if (mq_receive(q_client, (char *) &res, sizeof(struct message), 0) < 0){
		perror("mq_recv set_value");
		return -1;
	}
    printf("Resultado = %d\n", res);

    mq_close(q_server);
    mq_close(q_client);
    mq_unlink(q_client_name);
    return 0;
}

int get_value(int key, char *value1, int *N_value2, double *V_value2){
    
    return 0;
}

int modify_value(int key, char *value1, int N_value2, double *V_value2){
    
    return 0;
}

int delete_key(int key){

    return 0;
}
int exist(int key){

    return 0;
}
