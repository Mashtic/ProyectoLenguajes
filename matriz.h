#ifndef MATRIZ_H
#define MATRIZ_H

#define N 6 // Tamaño de la matriz

// Declaración de las funciones relacionadas con la matriz
void inicializarMatriz(int matriz[N][N]);
void llenarPropiedadesCruz(int matriz[N][N], int array[N], int arrayComplemento[N]);
void llenarPropiedadesEstrella(int matriz[N][N], int array[N], int arrayComplemento[N]);
void llenarPropiedad2(int matriz[N][N]);
void imprimirMatriz(const int matriz[N][N]);

#endif
