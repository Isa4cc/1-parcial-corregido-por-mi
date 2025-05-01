# 1-parcial-corregido-por-mi

## Ejercicio 2 Programa que evalúa un torneo de 6 jugadores de videojuegos👍
Cada jugador recibe puntos según:
1. Victorias directas (3 puntos).
2. Empates (1 punto).
3. Si hay empate en puntos:
     - desempate por cant de partidas
     - desempate por cant de armas obtenidas
  
Primero verifica los puntajes con bubble sort para ver si son diferentes y ordenarlos o sino, ir por la cant de armas de j y j+1, que es el siguiente player:

- Correcto. El código primero verifica si los puntajes de los jugadores son diferentes. Si no lo son, compara las cantidades de armas entre j y j+1 para decidir la prioridad en el orden.

"Si alguno de los condicionales del if es verdad, intercambia las posiciones de las armas al ritmo de for anidado":

- Perfecto. Si se cumple la condición de que un jugador debe ir antes que el otro (por puntaje o cantidad de armas), se intercambian las posiciones dentro del arreglo cant_armas utilizando el bucle anidado.

"Cambia nombres al ritmo del for anidado":

- Absolutamente. Para mantener la consistencia en la tabla final, los nombres de los jugadores en el arreglo players también se intercambian según el mismo orden.
