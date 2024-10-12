#include <stdio.h>
#include "matriz.h"

int main() {
    int array[] = {0, 1, 2, 3, 4, 5};
    int arrayComplemento[]= {1, 0, 3, 2, 5, 4};
    int matrizCruz[6][6];
    int matrizEstrella[6][6];

    inicializarMatriz(matrizCruz);  // Inicializa la matriz con -1
    inicializarMatriz(matrizEstrella);  // Inicializa la matriz con -1

    llenarMatrizCruz(matrizCruz, array, arrayComplemento); // Llenar matriz con propiedades 1, 3 y 4
    printf("Matriz cruz resultante:\n");
    imprimirMatriz(matrizCruz);      // Imprimir la matriz generada
    llenarMatrizEstrella(matrizEstrella, array, arrayComplemento); // Llenar matriz con propiedades 1, 3 y 4
    printf("Matriz estrella resultante:\n");
    imprimirMatriz(matrizEstrella);

    // llenarPropiedad2(matrizCruz);    // Llenar con propiedad 2 y simetría
    // llenarPropiedad2(matrizEstrella);    // Llenar con propiedad 2 y simetría

    // printf("Matriz resultante:\n");
    // imprimirMatriz(matrizCruz);      // Imprimir la matriz generada
    // imprimirMatriz(matrizEstrella);      // Imprimir la matriz generada

    return 0;
}