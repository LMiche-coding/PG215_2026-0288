/**********************************************************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Layla Garcia                               */
/*  Matricula: 2026-0288                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Parcial #1                                 */
/*  Fecha:     13/10/2026                                 */                       
/* Link Practica: https://github.com/LMiche-coding/PG215_2026-02888 */
/**********************************************************/
/*****************************************************************************//*!
   *
   * @brief funcion principal. 
   *        
   * @param[in] recive ninguno 
   *
   * @return devuelve un entero que puede ser utilizado como indicador de error
   *
   * @Pass/ Fail criteria:  none.
*****************************************************************************/

#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
#include "reto.h" 

int main()
{ 
    int n, m, q,  i, j, total, busqueda; 
    int muestras[20][8];
    char nombre [16]; 
    Registro registros[MAX_UNIDADES]; // arreglo de registros 

    Registro ordenScore[MAX_UNIDADES]; 
    Registro ordenId[MAX_UNIDADES];  

    scanf("%d %d %d", &n, &m, &q);

    // comprueba que esta dentro del dominio
    if (n < 1 || n > MAX_UNIDADES || m < 1 || m > MAX_MUESTRAS || q < 1 || q > 9999)
    {
        printf("ERROR\n"); 
        return 0; 
    }

    for (i = 0; i < n; i++) // sirve para recorrer los registros
    {
        scanf("%d %s %d %d", &registros[i].id, nombre, &registros[i].config.tipo, &registros[i].config.p); 
        strcpy(registros[i].nombre, nombre); // guarda el nombre en el registro

        if (registros[i].id < 1 || registros[i].id > 9999) // comprueban que los registros estan en el rango
        {
            printf("ERROR"); 
            return 0; 
        
        }

        // tipo solo puede ser 0 o 1 
        if (registros[i].config.tipo != 0 && registros[i].config.tipo != 1)
        {
            printf("ERROR");
            return 0; 
        } 

        if (registros[i].config.p < 0 || registros[i].config.p > 100)
        { 
            printf("ERROR"); 
            return 0; 
        }

        for (j = 0; j < m; j++) // comprueba que las  muestras no se salgan del rango
        {
           scanf("%d", &muestras[i][j]); 

            if (muestras[i][j] < 0 || muestras[i][j] > 100)
            {
                printf("ERROR"); 
                return 0; 
            }
        }

        for (j = 0; j < i; j++) // verifica que no haya id repetidos comparandolos con los anteriores registros
        {
            if (registros[i].id == registros[j].id)
            {
                printf("ERROR");
                return 0; 
            }            
        }
        
    }

    for (i = 0; i < n; i++)
    {
        registros[i].score = calcular(
            muestras[i],
            m,
            registros[i].config.tipo,
            registros[i].config.p,
            registros[i].nombre,
            &registros[i].estado); 
    }

    total = total_rec(registros, n); // la suma de los score 
  

    for (i = 0; i < n; i++)
    {
        ordenScore[i] = registros[i]; 
        ordenId[i] = registros [i];
    }

    // funcion pues, para ordenar por score y por Id 
    ordenar(ordenScore, ordenId, n); 
    busqueda = buscar(ordenId, n, q); 


    for (i = 0; i < n; i++)
    {
        printf("%d %s %d %d\n", registros[i].id, registros[i].nombre,registros[i].score, registros[i].estado); 
    }

    printf("TOTAL %d\n", total);

    printf("ORDER");
    for (i = 0; i < n; i++)
    {
        printf(" %d", ordenScore[i].id);
    }

    printf("\n"); 

    printf("FIND %d %d\n", q, busqueda); 

    return 0;

}

int calcular(int vec[], int m, int tipo, int p, char nombre[], int *estado)
{
    int copia_list[MAX_MUESTRAS], i, j, temporal, score; 
 
    for (i = 0; i < m; i++)
    {
        copia_list[i] = vec[i];
    }

    for (i = 0; i < m - 1; i++)
    {
        int min_pos = i; 
        for (j = i + 1; j < m; j++)
        {
            if (copia_list[j] < copia_list[min_pos])
            {
                min_pos = j; 
            }
        }

          if (min_pos != i)
        {
            temporal = copia_list[i]; 
            copia_list[i] = copia_list[min_pos]; 
            copia_list[min_pos]  = temporal; 
        }
    }

   if (m % 2 != 0)
    {
        score = copia_list[m/2]; 
    } else if (tipo == 0) {
        score = copia_list[(m/2) - 1];
    } else {
        score = copia_list[m/2]; 
    }

    // convertir minusculas a mayusculas con toupper
    for (i = 0; nombre[i] != '\0'; i++)
    {
        nombre[i] = toupper((unsigned char)nombre[i]); 
    }

    // calcular estado
    *estado = 1; 

    for (i = 0; i < m; i++)
    {
        if (abs(vec[i] - score) > p)
        {
            *estado = 0; 
            break; 
        }
    }

    return score; 
}

int total_rec(Registro reg[], int n)
{
    if (n == 0) 
    {
        return 0; 
    }
    return reg[n - 1].score + total_rec(reg,  n - 1);
}

void ordenar(Registro reg[], Registro regId[], int n)
{
    int i, j; 
    Registro temporal; 

    for (i = 0; i < n - 1; i++)
    {
        int min_pos = i; 
        for (j = i + 1; j < n ; j++)
        {
            if (reg[j].score > reg[min_pos].score || reg[j].score == reg[min_pos].score && reg[j].id < reg[min_pos].id)
            {
                min_pos = j; 
            }
        }

          if (min_pos != i)
        {
            temporal = reg[i]; 
            reg[i] = reg[min_pos]; 
            reg[min_pos] = temporal; 
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        int min_pos = i; 
        for (j = i + 1; j < n ; j++)
        {
            if (regId[j].id < regId[min_pos].id)
            {
                min_pos = j; 
            }
        }

          if (min_pos != i)
        {
            temporal = regId[i]; 
            regId[i] = regId[min_pos]; 
            regId[min_pos] = temporal; 
        }
    }

}

int buscar(Registro reg[] ,int n, int id)
{
    int inicio, mitad, fin; 
    inicio = 0; 
    fin = n - 1; 

    while(inicio <= fin)
    {
        mitad = (inicio + fin) / 2; 
        if(reg[mitad].id == id)
        {
            return reg[mitad].score;
        } else if (id < reg[mitad].id){
            fin = mitad - 1;
        } else{ 
            inicio = mitad + 1;
        }
    } 
    return -1; 
}