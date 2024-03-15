#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "claves.h"
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 256
#define MAX_LINE_LENGTH 100


int main(int argc, char *argv[]){
    
    // Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    // Inicialización de los valores
    int op = atoi(argv[1]);
    int key = atoi(argv[2]);
    char *value1 = strdup(argv[3]);
	int N_value2 = atoi(argv[4]);
	double V_value2[N_value2];
    for (int i = 0; i<N_value2;i++){
        V_value2[i] = (double)rand() / rand();
    }
    

    printf("valores:\nkey:%d value1:%s N_value2:%d\n", key, value1, N_value2);
    for(int i = 0; i < N_value2; i++){
        printf("V_value2[%d]: %f\n", i, V_value2[i]);
    }

    if (op == 0){
        init();
    }
    else if (op == 1){
        printf("envio peticion set_value cliente\n");
        set_value(key, value1, N_value2, V_value2);
    }
    // else if (op == 2){
    //     char *vacio1[MAX_KEY_LENGTH];
    //     int N_vacio2 = 0;
	//     double *V_vacio2[32];
    //     printf("envio peticion get_value cliente\n");
    //     get_value(key, *vacio1, &N_vacio2, *V_vacio2);
    //     printf("valores:\nkey:%d value1:%s N_value2:%d\n", key, value1, N_value2);
    //     for(int i = 0; i < N_value2; i++){
	// 	    printf("V_value2[%d]: %f\n", i, V_value2[i]);
	//     }
    // }
    else if (op == 3){
        printf("envio peticion modify_value cliente\n");
        char value1_modify[MAX_KEY_LENGTH] = "prueba 3";
        N_value2 = 4;
        double V_value2[N_value2]; 
        V_value2[0] = 1.1234567890123456;
        V_value2[1] = 2.1;
        V_value2[2] = 5.46;
        modify_value(key, value1_modify, N_value2, V_value2);
    }
    else if (op == 4){
        printf("envio peticion delete_key cliente\n");
        delete_key(key);
    }
    else if (op == 5){
        printf("envio peticion exist_key cliente\n");
        exist(key);
    }
    return 0;

}

