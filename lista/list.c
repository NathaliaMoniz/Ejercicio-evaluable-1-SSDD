#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "list.h"


int init(List *l) {

	*l = NULL;
	return (0);
}	

int set(List *l, int key, char *value1, int N_value2, double *V_value2){
	struct Node *ptr;

	ptr = (struct Node *) malloc(sizeof(struct Node));
	if (ptr == NULL) 
		return -1;

	ptr->V_value2 = (double *) malloc(N_value2 * sizeof(double));
	if (ptr->V_value2 == NULL) {
		free(ptr);
		return -1;
	}
	strcpy(ptr->value1, value1);
	ptr->key = key;
	ptr->N_value2 = N_value2;
	memcpy(ptr->V_value2, V_value2, N_value2*sizeof(double));

	if (*l == NULL) {  // emtpy list
		ptr->next = NULL;
		*l = ptr;
	}
	else {
		// insert in head
		
		ptr->next = *l;
		*l = ptr;
	}


	return 0;
}	

int get(List l, int key, char *value1, int *N_value2, double *V_value2){
	List aux;

	aux = l;	

	while (aux!=NULL) {
		if (aux->key == key) {
			strcpy(value1, aux->value1);
			*N_value2 = aux->N_value2;
			memcpy(V_value2, aux->V_value2, *N_value2*sizeof(double));
			return 0;		// found
		}
		else{
			aux = aux->next;
		}
	}

	return -1;  // not found
}	

int printList(List l){
	List aux;

	aux = l;

	while(aux != NULL){
		printf("Key=%d    value1=%s	value2=%d\n", aux->key, aux->value1, aux->N_value2);
		for(int i = 0; i<aux->N_value2; i++){
			printf("V_value2[%d]: %f\n", i, aux->V_value2[i]);
		}
		aux = aux->next;
	}
	
	return 0;
}	

int delete(List *l, int key){
	List aux, back;

	if (*l == NULL)  // lista vacia
		return 0;

	// primer elemento de la lista
	if ((*l)->key == key){
		aux = *l;
		*l = (*l)->next;
		free(aux);
		return 0;
	}
	
	aux = *l;
	back = *l;
	while (aux!=NULL) {
		if (aux->key == key) {
			back->next = aux->next;
			free (aux);
			return 0;		// found
		}
		else {
			back = aux;
			aux = aux->next;
		}
	}

	return 0;
}	

int  destroy(List *l){
	List aux; 

	while (*l != NULL){
		aux = *l;
		*l = aux->next;
		free(aux);
	}

	return 0;
}	

