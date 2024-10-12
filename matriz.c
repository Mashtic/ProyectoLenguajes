#include <stdio.h>
#include "matriz.h"

// Inicializa la matriz con valores -1
void inicializarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = -1; // Valor no definido
        }
    }
}
void llenarPropiedades1(int matriz[N][N], int array[N]) {
    //Rellena con la propiedad 1, es decir a + a = a | a * a = a
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i==j){
                matriz[i][j] = array[i]; // Valor no definido
            }
        }
    }
}

// Llenar matriz con las propiedades 1, 3, 4
void llenarPropiedadesCruz(int matriz[N][N], int array[N], int arrayComplemento[N]) {
    llenarPropiedades1(matriz, array);

}

// Llenar matriz según la propiedad 2 y la simetría
void llenarPropiedad2(int matriz[N][N]) {
    matriz[4][4] = 0;
    matriz[4][5] = 1;
    matriz[5][4] = 1;
    matriz[5][5] = 0;

    for (int i = 4; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            matriz[j][i] = matriz[i][j]; // Simetría
        }
    }
}

// Imprimir la matriz
void imprimirMatriz(const int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
