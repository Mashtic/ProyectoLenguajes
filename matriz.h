#ifndef MATRIZ_H
#define MATRIZ_H

#define N 6 // Tamaño de la matriz

// Declaración de las funciones relacionadas con la matriz
void inicializarMatriz(int matriz[N][N]);
void llenarMatrizCruz(int matriz[N][N], int array[N], int arrayComplemento[N]);
void llenarMatrizEstrella(int matriz[N][N], int array[N], int arrayComplemento[N]);
void llenarMatrizPropiedad2(int matriz[N][N]);
void imprimirMatriz(const int matriz[N][N]);

#endif
