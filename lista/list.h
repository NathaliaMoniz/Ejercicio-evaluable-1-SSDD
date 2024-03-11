#ifndef _LISTA_H
#define _LISTA_H        1

#define MAX_KEY_LENGTH	256

struct Node{ 
	int 	key;
	char 	value1[MAX_KEY_LENGTH];
	int 	N_value2;
	double	*V_value2;
	struct 	Node *next; 
};


typedef struct Node * List;


int init(List *l);
int set(List *l, int key,  char *value1, int N_value2, double *V_value2);
int get(List l, char *key,  int *value);
int printList(List l);
int delete(List *l, char *key);
int destroy(List *l);

#endif

