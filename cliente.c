#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "claves.h"

int main(int argc, char *argv[]){
    
    if (argc > 1 && strcmp(argv[1], "0") == 0){
        printf("gol");
        init();
    }
    return 0;

}

