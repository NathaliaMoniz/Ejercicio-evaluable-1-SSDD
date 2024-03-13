#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "claves.h"
#include <stdlib.h>
#define MAX_KEY_LENGTH 256

int main(int argc, char *argv[]){
    int key = 86;
	char value1[MAX_KEY_LENGTH] = "prueba 1";
	int N_value2 = 2;
	double V_value2[N_value2];
	V_value2[0] = 1.1234567890123456;
	V_value2[1] = 2.1;

    if (argc > 1 && strcmp(argv[1], "0") == 0){
        init();
    }
    else if (argc > 1 && strcmp(argv[1], "1") == 0){
        printf("envio peticion set_value cliente\n");
        set_value(key, value1, N_value2, V_value2);
    }
    else if (argc > 1 && strcmp(argv[1], "2") == 0){
        printf("envio peticion get_value cliente\n");
        int N_value2_puntero[32];
        get_value(key, value1, N_value2_puntero, V_value2);
    }
    else if (argc > 1 && strcmp(argv[1], "3") == 0){
        printf("envio peticion modify_value cliente\n");
        char value1_modify[MAX_KEY_LENGTH] = "prueba 3";
        N_value2 = 4;
        double V_value2[N_value2];
        V_value2[0] = 1.1234567890123456;
        V_value2[1] = 2.1;
        V_value2[2] = 5.46;
        modify_value(key, value1_modify, N_value2, V_value2);
    }
    else if (argc > 1 && strcmp(argv[1], "4") == 0){
        printf("envio peticion delete_key cliente\n");
        delete_key(key);
    }
    else if (argc > 1 && strcmp(argv[1], "5") == 0){
        printf("envio peticion exist_key cliente\n");
        exist(key);
    }
    return 0;

}

