#ifndef RETO_H
#define RETO_H 

typedef struct 
{
    int id; 
    char nombre[16];
    int score; 
    int estado;  
} Registro; 


int calcular(int vec, int m, int tipo, int p, char nombre[], int *estado); 
int total_rec(int n); 
void ordenar(); 
void buscar(); 

#endif 