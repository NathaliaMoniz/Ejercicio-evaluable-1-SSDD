#define MAX 256

struct message 
{
    // peticion 
    int    key;             // Clave
    char   value1[MAX];    // Cadena
    int    N_value2;        // Número de elementos del vector
    double *V_value2;       // Vector de doubles, tamaño variable (entre 1 y 32 elems)
    char   q_name[MAX];     // Nombre de la cola
} ;