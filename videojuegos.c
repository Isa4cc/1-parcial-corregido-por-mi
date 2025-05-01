/*
Programa que evalúa un torneo de 6 jugadores de videojuegos👍. Cada jugador recibe puntos según:
Victorias directas (3 puntos).
Empates (1 punto).
Si hay empate en puntos:
1. desempate por cant de partidas
2. por cant de armas obtenidas
*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

    char players[4][30];
    int puntajes[4] = {0}, cant_armas[4] = {0}, len;

    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese el nombre del jugador %d\n", i + 1);
        fflush(stdin);
        fgets(players[i], 30, stdin);
        len = strlen(players[i]) - 1;
        if (players[i][len] == '\n')
        {
            players[i][len] = '\0';
        }
    }
    int opcivic = 0; // opcion de quien gano (vic = victoria)
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {

            printf("Enfrentamiento: %s vs %s\n", players[i], players[j]);
            // pedir quien gano y la cant de armas obtenida por jugador
            printf("quien gano? 1. %s o 2. %s\n 3. empate\n", players[i], players[j]);
            fflush(stdin);
            scanf("%d", &opcivic);
            if (opcivic == 1)
            {
                puntajes[i] += 3; // Acumular puntos
                printf("Ingrese en numeros la cant de armas obtenidas del jugador %s.\n", players[i]);
                fflush(stdin);
                int armas_obtenidas = 0;
                scanf("%d", &armas_obtenidas);
                cant_armas[i] += armas_obtenidas; // Acumular armas obtenidas
            
                printf("Ingrese en numeros la cant de armas obtenidas del jugador %s.\n", players[j]);
                fflush(stdin);
                scanf("%d", &armas_obtenidas);
                cant_armas[j] += armas_obtenidas; // Acumular armas obtenidas
            }
            if (opcivic == 2)
            {
                puntajes[j] += 3;
                printf("Ingrese en numeros la cant de armas obtenidas del juagdor %s.\n", players[i]);
                fflush(stdin);
                int armas_obtenidas = 0;
                scanf("%d", &cant_armas[i]);
                cant_armas[i] += armas_obtenidas; // Acumular armas obtenidas
                printf("Ingrese en numeros la cant de armas obtenidas del juagdor %s.\n", players[j]);
                fflush(stdin);
                scanf("%d", &cant_armas[j]);
                cant_armas[j] += armas_obtenidas;
            }
            else if (opcivic == 3)
            {
                puntajes[i] += 1;
                puntajes[j] += 1;
                printf("Ingrese en numeros la cant de armas obtenidas del juagdor %s.\n", players[i]);
                fflush(stdin);
                int armas_obtenidas = 0;
                scanf("%d", &cant_armas[i]);
                cant_armas[i] += armas_obtenidas;
                printf("Ingrese en numeros la cant de armas obtenidas del juagdor %s.\n", players[j]);
                fflush(stdin);
                scanf("%d", &cant_armas[j]);
                cant_armas[j] += armas_obtenidas;
            }
        }
    }
    // lógica de diferenciación de armas y victorias(puntaje) con bubble sort
    //  Ordenar los jugadores por puntaje y, si hay empate, por armas

    int temp_P, temp_A;
    char temp_name[30];

    for (int i = 0; i < 4 - 1; i++) // Hasta el penúltimo jugador
{
    for (int j = 0; j < 4 - i - 1; j++) // Comparar jugadores consecutivos
    {
        // Comparar puntajes y armas para decidir el orden
        if (puntajes[j] < puntajes[j + 1] || 
           (puntajes[j] == puntajes[j + 1] && cant_armas[j] < cant_armas[j + 1]))
        {
            // Intercambiar puntajes
            temp_P = puntajes[j];
            puntajes[j] = puntajes[j + 1];
            puntajes[j + 1] = temp_P;

            // Intercambiar armas
            temp_A = cant_armas[j];
            cant_armas[j] = cant_armas[j + 1];
            cant_armas[j + 1] = temp_A;

            // Intercambiar nombres
            //ya estác hecho fuera la inicializacion de temp
            strcpy(temp_name, players[j]);
            strcpy(players[j], players[j + 1]);
            strcpy(players[j + 1], temp_name);
        }
    }
}


    printf("TABLA FINAL DE POSICIONES:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d. %s\tPuntos: %d\tArmas: %d\n", i + 1, players[i], puntajes[i], cant_armas[i]);
    }

    return 0;
}
