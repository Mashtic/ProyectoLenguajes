#include <stdio.h>
#include "matriz.h"

int main() {
    int array[] = {0, 1, 2, 3, 4, 5};                 // Elementos del conjunto
    int arrayComplemento[] = {1, 0, 3, 2, 5, 4};      // Complementos de cada elemento

    int matrizCruz[N][N];     // Matriz para la operación '+'
    int matrizEstrella[N][N]; // Matriz para la operación '*'

    // Inicializar y llenar las matrices con las propiedades conocidas
    inicializarMatriz(matrizCruz);
    inicializarMatriz(matrizEstrella);
    llenarMatrizCruz(matrizCruz, array, arrayComplemento);
    llenarMatrizEstrella(matrizEstrella, array, arrayComplemento);

    // Mostrar las matrices iniciales
    printf("Matriz inicial para la operación '+' (suma):\n");
    imprimirMatriz(matrizCruz);

    printf("Matriz inicial para la operación '*' (producto):\n");
    imprimirMatriz(matrizEstrella);

    // Pausa antes de continuar
    printf("Presione Enter para continuar con la búsqueda...\n");
    getchar();

    // Iniciar búsqueda de solución
    printf("Buscando solución que satisfaga todas las propiedades...\n");
    if (buscarSolucion(matrizCruz, matrizEstrella, 1, 0)) {
        printf("Se encontró una álgebra de Boole válida:\n");
        printf("Matriz cruz:\n");
        imprimirMatriz(matrizCruz);
        printf("Matriz estrella:\n");
        imprimirMatriz(matrizEstrella);
    } else {
        printf("No es posible construir un álgebra de Boole con 6 elementos.\n");
    }

    return 0; // Finaliza el programa
}

