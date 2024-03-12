#define MAX 256

struct message 
{
    // peticion 
    int    op;
    int    key;             // Clave
    char   value1[MAX];     // Cadena
    int    N_value2;        // Número de elementos del vector
    double *V_value2;       // Vector de doubles, tamaño variable (entre 1 y 32 elems)
    char   q_name[MAX];     // Nombre de la cola
} ;

struct mq_attributes
{
    long mq_flags;      // Flags del mensaje (actualmente no utilizados, deben ser 0)
    long mq_maxmsg;     // Número máximo de mensajes en la cola
    long mq_msgsize;    // Tamaño máximo de un mensaje en la cola
    long mq_curmsgs;    // Número de mensajes actualmente en la cola

};
