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

void aplicarTeorema1(int matriz[N][N], int array[N]) {
    //Rellena a partir del teorema 1, es decir a + a = a | a * a = a
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i==j){
                matriz[i][j] = array[i]; 
            }
        }
    }
}

void aplicarTeorema2(int matriz[N][N], int neutro) {
    //Rellena a partir del teorema 2, es decir ∀a ∈ B, a + U = U y también a ∗ Z = Z
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i==neutro || j==neutro){
                matriz[i][j] = neutro; // neutro es 1 si es operación cruz y 0 si es operación *
            }
        }
    }
}
void aplicarPropiedad3(int matriz[N][N], int neutro) {
    //Rellena a partir de la priopiedad 3, es decir Z tal que a + Z = Z + a = a, ∀a ∈ B y Existe también en B un elemento U tal que a∗U = U ∗a = a, ∀a ∈ B.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i==neutro){
                matriz[i][j] = j;
            }
            else if(j==neutro){
                matriz[i][j] = i;
            }
        }
    }
}

void llenarPropiedades4(int matriz[N][N], int arrayComplemento[N], int neutro) {
    //Aplicar propiedad 4 que a + `a =1 |a * `a =1

    for (int i=0; i < N; i++   ) {
        for (int j=0; j < N; j++) {
            if(j == arrayComplemento[i]) {
                // matriz [0][1]=1
                matriz[i][j]=neutro;
            }
        }
    }
}

// Llenar matriz con las propiedades y teoremas 1, 3, 4 IMPORTANTE RECORDAR: Z=0, U=1
void llenarMatrizCruz(int matriz[N][N], int array[N], int arrayComplemento[N]) {
    aplicarTeorema1(matriz, array);
    aplicarTeorema2(matriz, 1);
    aplicarPropiedad3(matriz, 0);
    llenarPropiedades4(matriz, arrayComplemento, 1);
}

void llenarMatrizEstrella(int matriz[N][N], int array[N], int arrayComplemento[N]) {
    aplicarTeorema1(matriz, array);
    aplicarTeorema2(matriz, 0);
    aplicarPropiedad3(matriz, 1);
    llenarPropiedades4(matriz, arrayComplemento, 0);
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
