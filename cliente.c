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
	double *V_value2 = (double *)malloc(N_value2 * sizeof(double));
	V_value2[0] = 1.1234567890123456;
	V_value2[1] = 2.1;

    if (argc > 1 && strcmp(argv[1], "0") == 0){
        init();
    }
    else if (argc > 1 && strcmp(argv[1], "1") == 0){
        printf("envio\n");
        set_value(key, value1, N_value2, V_value2);
    }
    return 0;

}

