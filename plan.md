# PSEUDOCODIGO


#librerias 

define Estructura configuracion 
inicio 
    entero tipo, p
fin 

define Estructura Registro
inicio
    entero id, score, estado; 
    caracter nombre[16]
    Configuracion config
fin

entero calcular(entero vector, entero m, entero tipo, entero p, caracter nombre, entero *estado)

entero total_rec(Registro reg, entero n)

nada ordenar(Registro reg, Registro regId, entero n)

entero buscar(Registro reg, entero n, entero id)

principal ()
inicio 
    entero n, m, q, i, j, total, busqueda
    entero muestras[20][8]
    caracter nombre [16]
    Registro registro[20]

    Registro ordenScore[20]
    Registro ordenId[20]

    leer n, m, q 

    si (n < 1 o n > 20 o m < 1 o m > 8 o q < 1 o q > 9999)
        imprimir "ERROR" 
    
    desde (i <- 0, i < n, i+1)

        leer registros[i].id, nombre, registros[i].config.tipo. registros[i].config.p 
        copiar string nombre a registros[i].nombre 

        si (registros[i].id < 1 o registros[i].id > 9999)
            imprimir "ERROR"

        si (registros[i].config.p < 0 o registros[i].config.p > 100)
            imprimir "ERROR"
        
        desde (j <- 0, j < m, j+1)
            leer muestras[i][j]

            si (muestras[i][j] < 0 o muestras[i][j] > 100)
                imprimir ERROR
        
        desde (j <- 0, j < 1, j+1)
            si (registros[i].id es igual registros[j].id)
                imprimir ERROR

    desde (i <- 0, i < n, i+1)

        registro.[i].score <- calcular(muestras[i], m, registros[i].config.tipo,  registros[i].config.p, registros[i].nombre, registros[i].estado)
    
    total <- total_rec(registros, n)

    desde (i <- 0, i < n, i+1)
        ordenScore[i] <- registros[i]
        ordenId[i] <- registros[i]
    
    ordenar(ordenScore, ordenId, n)
    busqueda <- buscar(ordenId, n, q)

    desde (i <- 0, i < n, i+1)
        imprimir registros[i].id, registros[i].nombre,registros[i].score, registros[i].estado

    imprimir "TOTAL"

    imprimir "ORDER"

    desde (i <- 0, i < n, i+1)
        imprimir orderScore[i].id
    
    salto de linea

    imprimir "FIND" q, busqueda

fin 


entero calcular(entero vector, entero m, entero tipo, entero p, caracter nombre, entero *estado)
inicio 
    entero copia_list[8], i,j, temporal, score

    desde (i <- 0, i < m, i+1)
        copia_list[i] = vec[i]

    desde (i <- 0, i < m - 1, i+1)
        entero min_pos <- i

        desde (j <- i + 1, j < m, j+1)
            si (copia_list[j] < copia_list[min_pos])
                min_pos <- j 

        si (min_pos no es igual i)
            temporal <- copia_list[i]
            copia_list <- copia_list[min_pos]
            copia_list[min_pos] <- temporal

    si (m % 2 no es igual a 0)
        score <- copia_list[m/2]
    si no, pero (tipo es igual 0)
        score <- copia_list[(m/2) - 1]
    si no 
        score <- copia_list[m/2]
    
    desde (i <- 0, nombre[i] != '\0', i+1)
        nombre[i] = mayusculas(nombre[i])

    *estado = 1

    desde (i <- 0, i < m, i+1)
        si (absoluto(vec[i] - score) > p)
            *estado = 0 

    retornar score

fin 

entero total_rec(Registro reg, entero n) 
inicio

    si (n es igual 0)
        retornar 0
    
    retornar reg[n-1].score + total_rec(reg, n-1)

fin

nada ordenar(Registro reg, Registro regId, entero n)
inicio
    entero i, j 
    Registro temporal 

    desde (i <- 0, i < m, i+1)
        entero min_pos <- i 
        desde (j <- 1 + 1, j < n, j+1)
            si (reg[j].score > reg[min_pos].score || reg[j].score == reg[min_pos].score && reg[j].id < reg[min_pos].id)
                min_pos <- j
        
        if (min_pos no es igual i)
            temporal <- reg[i]; 
            reg[i] <- reg[min_pos]; 
            reg[min_pos] <- temporal; 

    desde (i <- 0, i < m, i+1)
        entero min_pos <- i 
        desde (j <- 1 + 1, j < n, j+1)
            si (regId[j].id < regId[min_pos].id)
                min_pos <- j;

         if (min_pos no es igual i)
            temporal <- regID[i]; 
            regID[i] <- regID[min_pos]; 
            regID[min_pos] <- temporal; 

            

fin

entero buscar(Registro reg, entero n, entero id)
inicio
    entero inicio, mitad, fin 
    inicio <- 0 
    fin <- n - 1

    mientras(inicio <= fin)
        mitad = inicio + fin / 2
        si (reg[mitad].id == id)
            retornar reg[mitad].score
        si no, pero (id < reg[mitad].id)
            fin <- mitad - 1
        si no 
            inicio <- mitad + 1 

    
    retornar -1
         
fin


