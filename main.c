// Se desea desarrollar un programa que me permita conocer el ganador de un torneo de box,
// en los cuales participaran 6 competidores👍
// La primera etapa consistira en llaves establecidas👍
// La segunda etapa que sera la final sera entre aquellos competidores que
// hayan alcanzado los dos mejhores puntajes.
// Los puntos se asiganaran de la siguiente manera
// Gnador de combate 1pto👍
// Y si la ganancia es por knockout 3 puntos👍
// Ingresar los nombres de los competidores verificar valores👍
// la llave inicial de la que salieron pesa más mientras sea más alta
/*
ejemplo: luchador a sale de llave 1 por ko => tiene 3 ptos
luchador b sale de llave 3 por ko tambien == 3ptos
como llave 3 > llave2, luchador b pasa primero que luchador a por llave mayor
*/

#include <stdio.h>
#include <string.h>

void getnames(char luchadores[6][30]);

int main(int argc, char *argv[])
{
    char luchadores[6][30], finalistas[3][30];
    char finalista1[30], finalista2[30]; // Simplifiqué las dimensiones
    int val, scores[3], cont_llaves = 0, key[3];
    int cont_finalistas = 0;
    printf("======================================\n");
    printf("SISTEMA DE GESTION DE LLAVES DE BOX\n");
    printf("======================================\n");
    getnames(luchadores);
    printf("\n");
    printf("======================================\n");
    printf("-----------------COMBATES--------------\n");
    printf("======================================\n");

    // Peleas
    for (int i = 0; i < 6; i += 2)
    {
        printf("Pelea: %s vs %s\n", luchadores[i], luchadores[i + 1]);
        printf("Quien gano?\n");
        fflush(stdin);
        fgets(finalistas[cont_finalistas], 30, stdin);
        finalistas[cont_finalistas][strcspn(finalistas[cont_finalistas], "\n")] = 0; // Elimina salto de línea
        printf("1. victoria normal 3. victoria por ko. Elija\n");
        do
        {
            fflush(stdin);
            val = scanf("%d", &scores[cont_finalistas]);
            if (val != 1 || (scores[cont_finalistas] != 1 && scores[cont_finalistas] != 3))
            {
                printf("Por favor ingrese un numero valido (1 o 3).\n");
            }
        } while (val != 1 || (scores[cont_finalistas] != 1 && scores[cont_finalistas] != 3));
        key[cont_finalistas] = (i / 2) + 1; // Determinar llave
        cont_finalistas++;
    }

    // Lógica para determinar los finalistas
    // =====================================

    // Caso 1: `3, 1, 1`
    if (scores[0] > scores[1] && scores[0] > scores[2])
    {
        strcpy(finalista1, finalistas[0]); // Puntaje más alto
        if (scores[1] == scores[2])
        {
            if (key[1] > key[2])
            {
                strcpy(finalista2, finalistas[1]); // Llave más alta
            }
            else
            {
                strcpy(finalista2, finalistas[2]);
            }
        }
        else if (scores[1] > scores[2])
        {
            strcpy(finalista2, finalistas[1]); // Segundo puntaje más alto
        }
        else
        {
            strcpy(finalista2, finalistas[2]); // Segundo puntaje más alto
        }
    }
    // Caso 2: `1, 3, 1`
    else if (scores[1] > scores[0] && scores[1] > scores[2])
    {
        strcpy(finalista1, finalistas[1]); // Puntaje más alto
        if (scores[0] == scores[2])
        {
            if (key[0] > key[2])
            {
                strcpy(finalista2, finalistas[0]); // Llave más alta
            }
            else
            {
                strcpy(finalista2, finalistas[2]);
            }
        }
        else if (scores[0] > scores[2])
        {
            strcpy(finalista2, finalistas[0]); // Segundo puntaje más alto
        }
        else
        {
            strcpy(finalista2, finalistas[2]); // Segundo puntaje más alto
        }
    }
    // Caso 3: `1, 1, 3`
    else if (scores[2] > scores[1] && scores[2] > scores[0])
    {
        strcpy(finalista1, finalistas[2]); // Puntaje más alto
        if (scores[0] == scores[1])
        {
            if (key[0] > key[1])
            {
                strcpy(finalista2, finalistas[0]); // Llave más alta
            }
            else
            {
                strcpy(finalista2, finalistas[1]);
            }
        }
        else if (scores[0] > scores[1])
        {
            strcpy(finalista2, finalistas[0]); // Segundo puntaje más alto
        }
        else
        {
            strcpy(finalista2, finalistas[1]); // Segundo puntaje más alto
        }
    }
    // Otros casos: Empates con puntaje más alto
    else
    {
        if (scores[0] == scores[1] && scores[0] > scores[2])
        {
            if (key[0] > key[1])
            {
                strcpy(finalista1, finalistas[0]);
                strcpy(finalista2, finalistas[1]);
            }
            else                                           // ej 3 3 1
            {
                strcpy(finalista1, finalistas[1]);
                strcpy(finalista2, finalistas[0]);
            }                                                       
        }
        else if (scores[0] == scores[2] && scores[0] > scores[1])
        {
            if (key[0] > key[2])
            {
                strcpy(finalista1, finalistas[0]);
                strcpy(finalista2, finalistas[2]);
            }
            else                                            // ej 3 1 3
            {
                strcpy(finalista1, finalistas[2]);
                strcpy(finalista2, finalistas[0]);
            }
        }
        else if (scores[1] == scores[2] && scores[1] > scores[0])
        {
            if (key[1] > key[2])
            {
                strcpy(finalista1, finalistas[1]);
                strcpy(finalista2, finalistas[2]);
            }
            else                                               // ej 1 3 3
            {
                strcpy(finalista1, finalistas[2]);
                strcpy(finalista2, finalistas[1]);
            }
        }
    }

    // Mostrar finalistas
    printf("\n==================\n");
    printf("FINALISTAS DEL TORNEO\n");
    printf("=====================\n");
    printf("Primer finalista: %s\n", finalista1);
    printf("Segundo finalista: %s\n", finalista2);

    // Final
    char campeon[30];
    int opci;
    printf("Por favor indique que finalista gano:\n");
    fflush(stdin);
    fgets(campeon, 30, stdin);
    campeon[strcspn(campeon, "\n")] = 0; // Elimina salto de línea
    printf("1. victoria comun 2. victoria por ko\n");
    do
    {
        fflush(stdin);
        val = scanf("%d", &opci);
        if (val != 1 || opci < 1 || opci > 2)
        {
            printf("El valor no es correcto o esta fuera de rango. Ingrese otra vez..\n");
        }
    } while (val != 1 || opci < 1 || opci > 2);
    if (opci == 1)
    {
        printf("Felicidades!! %s es campeon por victoria normal!", campeon);
    }
    else
    {
        printf("Felicidades!! %s es campeon por K.O.!", campeon);
    }
    
    if ((scores[0] == scores[1]) && (scores[0] == scores[2]) && (scores[2] == scores[1])) // o es 1 1 1 o 3 3 3
    {
        strcpy(finalista1, finalistas[2]);
        strcpy(finalista2, finalistas[1]);
    }

    return 0;
}

void getnames(char luchadores[6][30])
{
    int len;
    for (int i = 0; i < 6; i++)
    {
        printf("Ingrese por favor el nombre del luchador %d\n", i + 1);
        fflush(stdin);
        fgets(luchadores[i], 30, stdin);
        // Eliminar salto de línea 👍
        len = strlen(luchadores[i]) - 1;
        if (luchadores[i][len] == '\n')
        {
            luchadores[i][len] = '\0';
        }
    }
}
