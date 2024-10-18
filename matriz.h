#ifndef MATRIZ_H
#define MATRIZ_H

#define N 6 // Tamaño de la matriz (número de elementos del álgebra)

#include <stdbool.h> // Para utilizar el tipo bool en las funciones

// Declaración de las funciones relacionadas con la matriz

// Inicializa la matriz con valores -1 (indicando posiciones indefinidas)
void inicializarMatriz(int matriz[N][N]);

// Llena la matriz para la operación '+', aplicando las propiedades conocidas
void llenarMatrizCruz(int matriz[N][N], int array[N], int arrayComplemento[N]);

// Llena la matriz para la operación '*', aplicando las propiedades conocidas
void llenarMatrizEstrella(int matriz[N][N], int array[N], int arrayComplemento[N]);

// Imprime la matriz en pantalla
void imprimirMatriz(const int matriz[N][N]);

// Funciones para verificar propiedades y buscar soluciones

// Verifica la propiedad de cierre (closure)
bool verificarCierre(int matriz[N][N]);

// Verifica la propiedad de conmutatividad (commutativity)
bool verificarConmutatividad(int matriz[N][N]);

// Verifica la propiedad de asociatividad (associativity)
bool verificarAsociatividad(int matriz[N][N]);

// Verifica la existencia del elemento neutro (identity element)
bool verificarElementoNeutro(int matriz[N][N], int neutro);

// Verifica la propiedad de idempotencia (idempotence)
bool verificarIdempotencia(int matriz[N][N]);

// Verifica la existencia de complementos (complements)
bool verificarExistenciaComplementos(int matriz[N][N], int neutro);

// Verifica la propiedad de distributividad: a + (b * c) = (a + b) * (a + c)
bool verificarDistributividadCruz(int matrizCruz[N][N], int matrizEstrella[N][N]);

// Verifica la propiedad de distributividad: a * (b + c) = (a * b) + (a * c)
bool verificarDistributividadEstrella(int matrizCruz[N][N], int matrizEstrella[N][N]);

// Verifica todas las propiedades requeridas de un álgebra de Boole
bool verificarPropiedades(int matrizCruz[N][N], int matrizEstrella[N][N], int neutroSuma, int neutroProducto);

// Realiza la búsqueda exhaustiva para encontrar una solución que satisfaga todas las propiedades
bool buscarSolucion(int matrizCruz[N][N], int matrizEstrella[N][N], int neutroSuma, int neutroProducto);

#endif
