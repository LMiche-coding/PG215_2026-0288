#ifndef RETO_H
#define RETO_H 

#define MAX_NOMNRE 16
#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8 

typedef struct
{
    int tipo, p; 
} Configuracion;

typedef struct 
{
    int id, score, estado; 
    char nombre[MAX_NOMNRE];
    Configuracion config; 
} Registro; 


int calcular(int vec, int m, int tipo, int p, char nombre[], int *estado); 
int total_rec(Registro reg[], int n); 
void ordenar(Registro reg[] ,int n); 
void buscar(Registro reg[] ,int n); 

#endif 