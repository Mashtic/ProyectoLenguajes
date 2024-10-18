#include <stdio.h>
#include "matriz.h"

// Inicializa la matriz con valores -1 (posiciones indefinidas)
void inicializarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {         // Recorre filas
        for (int j = 0; j < N; j++) {     // Recorre columnas
            matriz[i][j] = -1;            // Asigna -1 a cada posición
        }
    }
}

// Aplica la propiedad idempotente: a op a = a
void aplicarTeorema1(int matriz[N][N], int array[N]) {
    for (int i = 0; i < N; i++) {
        matriz[i][i] = array[i];          // matriz[i][i] = i
    }
}

// Aplica la existencia del elemento neutro
void aplicarTeorema2(int matriz[N][N], int neutro) {
    for (int i = 0; i < N; i++) {
        matriz[i][neutro] = neutro;       // a op neutro = neutro (para '+') o a op neutro = a (para '*')
        matriz[neutro][i] = neutro;
    }
}

// Aplica la existencia del elemento absorbente (propiedad 3)
void aplicarPropiedad3(int matriz[N][N], int neutro) {
    for (int i = 0; i < N; i++) {
        matriz[i][neutro] = i;            // a op neutro = a (para '+') o a op neutro = neutro (para '*')
        matriz[neutro][i] = i;
    }
}

// Aplica la existencia de complementos: a op complemento(a) = neutro
void llenarPropiedades4(int matriz[N][N], int arrayComplemento[N], int neutro) {
    for (int i = 0; i < N; i++) {
        int complemento = arrayComplemento[i];   // Obtenemos el complemento de i
        matriz[i][complemento] = neutro;         // a op complemento(a) = neutro
        matriz[complemento][i] = neutro;         // Aseguramos la simetría
    }
}

// Llena la matriz para la operación '+', aplicando propiedades conocidas
void llenarMatrizCruz(int matriz[N][N], int array[N], int arrayComplemento[N]) {
    aplicarTeorema1(matriz, array);              // a + a = a
    aplicarTeorema2(matriz, 1);                  // a + 1 = 1
    aplicarPropiedad3(matriz, 0);                // a + 0 = a
    llenarPropiedades4(matriz, arrayComplemento, 1); // a + complemento(a) = 1
}

// Llena la matriz para la operación '*', aplicando propiedades conocidas
void llenarMatrizEstrella(int matriz[N][N], int array[N], int arrayComplemento[N]) {
    aplicarTeorema1(matriz, array);              // a * a = a
    aplicarTeorema2(matriz, 0);                  // a * 0 = 0
    aplicarPropiedad3(matriz, 1);                // a * 1 = a
    llenarPropiedades4(matriz, arrayComplemento, 0); // a * complemento(a) = 0
}

// Imprime la matriz en pantalla
void imprimirMatriz(const int matriz[N][N]) {
    for (int i = 0; i < N; i++) {                // Recorre filas
        for (int j = 0; j < N; j++) {            // Recorre columnas
            printf("%d ", matriz[i][j]);         // Imprime el valor en la posición [i][j]
        }
        printf("\n");                            // Nueva línea al final de cada fila
    }
}

// Función para verificar la propiedad de cierre
bool verificarCierre(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {                // Recorre filas
        for (int j = 0; j < N; j++) {            // Recorre columnas
            int resultado = matriz[i][j];
            if (resultado < 0 || resultado >= N) {   // Verifica si el resultado está fuera del rango
                printf("No cumple con la propiedad de cierre: matriz[%d][%d] = %d no está en el rango [0, %d]\n", i, j, resultado, N - 1);
                return false;                   // Retorna false si hay violación
            }
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar la propiedad de conmutatividad
bool verificarConmutatividad(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {                // Recorre filas
        for (int j = 0; j < N; j++) {            // Recorre columnas
            if (matriz[i][j] != matriz[j][i]) {  // Verifica simetría
                printf("No cumple con la propiedad de conmutatividad: matriz[%d][%d] = %d, matriz[%d][%d] = %d\n",
                       i, j, matriz[i][j], j, i, matriz[j][i]);
                return false;                   // Retorna false si hay violación
            }
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar la propiedad de asociatividad
bool verificarAsociatividad(int matriz[N][N]) {
    for (int a = 0; a < N; a++) {                // Recorre primer elemento
        for (int b = 0; b < N; b++) {            // Recorre segundo elemento
            for (int c = 0; c < N; c++) {        // Recorre tercer elemento
                int izquierda = matriz[matriz[a][b]][c]; // (a op b) op c
                int derecha = matriz[a][matriz[b][c]];   // a op (b op c)
                if (izquierda != derecha) {      // Compara resultados
                    printf("No cumple con la propiedad de asociatividad en a=%d, b=%d, c=%d: "
                           "(%d op %d) op %d = %d, %d op (%d op %d) = %d\n",
                           a, b, c, a, b, c, izquierda, a, b, c, derecha);
                    return false;               // Retorna false si hay violación
                }
            }
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar la existencia del elemento neutro
bool verificarElementoNeutro(int matriz[N][N], int neutro) {
    for (int a = 0; a < N; a++) {                // Recorre todos los elementos
        if (matriz[a][neutro] != a) {            // Verifica a op neutro = a
            printf("No cumple con la propiedad de elemento neutro a la derecha: matriz[%d][%d] = %d, se esperaba %d\n",
                   a, neutro, matriz[a][neutro], a);
            return false;                       // Retorna false si hay violación
        }
        if (matriz[neutro][a] != a) {            // Verifica neutro op a = a
            printf("No cumple con la propiedad de elemento neutro a la izquierda: matriz[%d][%d] = %d, se esperaba %d\n",
                   neutro, a, matriz[neutro][a], a);
            return false;                       // Retorna false si hay violación
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar la propiedad de idempotencia
bool verificarIdempotencia(int matriz[N][N]) {
    for (int a = 0; a < N; a++) {                // Recorre todos los elementos
        if (matriz[a][a] != a) {                 // Verifica a op a = a
            printf("No cumple con la propiedad de idempotencia: matriz[%d][%d] = %d, se esperaba %d\n",
                   a, a, matriz[a][a], a);
            return false;                       // Retorna false si hay violación
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar la existencia de complementos
bool verificarExistenciaComplementos(int matriz[N][N], int neutro) {
    for (int a = 0; a < N; a++) {                // Recorre todos los elementos
        bool complementoEncontrado = false;
        for (int b = 0; b < N; b++) {            // Busca un complemento para 'a'
            if (matriz[a][b] == neutro) {        // Si a op b = neutro
                complementoEncontrado = true;    // Complemento encontrado
                break;
            }
        }
        if (!complementoEncontrado) {            // Si no se encontró complemento
            printf("No se encontró complemento para el elemento %d\n", a);
            return false;// Retorna false
        }
    }
    return true;                                 // Retorna true si todos tienen complemento
}



// Función para verificar a + (b * c) = (a + b) * (a + c)
bool verificarDistributividadCruz(int matrizCruz[N][N], int matrizEstrella[N][N]) {
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                int izquierda = matrizCruz[a][matrizEstrella[b][c]]; // a + (b * c)
                int derecha = matrizEstrella[matrizCruz[a][b]][matrizCruz[a][c]]; // (a + b) * (a + c)
                if (izquierda != derecha) {
                    printf("Violación de distributividad a + (b * c) en a=%d, b=%d, c=%d: "
                           "a + (b * c) = %d, (a + b) * (a + c) = %d\n",
                           a, b, c, izquierda, derecha);
                    return false;               // Retorna false si hay violación
                }
            }
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Función para verificar a * (b + c) = (a * b) + (a * c)
bool verificarDistributividadEstrella(int matrizCruz[N][N], int matrizEstrella[N][N]) {
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                int izquierda = matrizEstrella[a][matrizCruz[b][c]]; // a * (b + c)
                int derecha = matrizCruz[matrizEstrella[a][b]][matrizEstrella[a][c]]; // (a * b) + (a * c)
                if (izquierda != derecha) {
                    printf("Violación de distributividad a * (b + c) en a=%d, b=%d, c=%d: "
                           "a * (b + c) = %d, (a * b) + (a * c) = %d\n",
                           a, b, c, izquierda, derecha);
                    return false;               // Retorna false si hay violación
                }
            }
        }
    }
    return true;                                 // Retorna true si se cumple la propiedad
}

// Verifica todas las propiedades requeridas de un álgebra de Boole
bool verificarPropiedades(int matrizCruz[N][N], int matrizEstrella[N][N], int neutroCruz, int neutroEstrella) {
    // Verificar propiedades para la operación '+'
    if (!verificarCierre(matrizCruz)) {
        return false;
    }
    if (!verificarConmutatividad(matrizCruz)) {
        return false;
    }
    if (!verificarAsociatividad(matrizCruz)) {
        return false;
    }
    if (!verificarElementoNeutro(matrizCruz, neutroCruz)) {
        return false;
    }
    if (!verificarIdempotencia(matrizCruz)) {
        return false;
    }
    if (!verificarExistenciaComplementos(matrizCruz, neutroCruz)) {
        return false;
    }

    // Verificar propiedades para la operación '*'
    if (!verificarCierre(matrizEstrella)) {
        return false;
    }
    if (!verificarConmutatividad(matrizEstrella)) {
        return false;
    }
    if (!verificarAsociatividad(matrizEstrella)) {
        return false;
    }
    if (!verificarElementoNeutro(matrizEstrella, neutroEstrella)) {
        return false;
    }
    if (!verificarIdempotencia(matrizEstrella)) {
        return false;
    }

    // Verificar distributividad mutua
    if (!verificarDistributividadCruz(matrizCruz, matrizEstrella)) {
        return false;
    }
    if (!verificarDistributividadEstrella(matrizCruz, matrizEstrella)) {
        return false;
    }

    return true; // Si todas las propiedades se cumplen, retorna true
}


// Función recursiva para realizar la búsqueda exhaustiva considerando ambas matrices
bool buscarSolucionRecursiva(int matrizCruz[N][N], int matrizEstrella[N][N],
                             int posicionesIndefCruz[][2], int totalIndefCruz, int indexCruz,
                             int posicionesIndefProd[][2], int totalIndefProd, int indexProd,
                             int neutroCruz, int neutroEstrella) {
    // Caso base: todas las posiciones indefinidas han sido asignadas
    if (indexCruz == totalIndefCruz && indexProd == totalIndefProd) {
        // Verificar todas las propiedades
        if (verificarPropiedades(matrizCruz, matrizEstrella, neutroCruz, neutroEstrella)) {
            return true; // Solución encontrada
        } else {
            return false; // No es válida
        }
    }

    // Si aún hay posiciones indefinidas en matrizCruz
    if (indexCruz < totalIndefCruz) {
        int i = posicionesIndefCruz[indexCruz][0];
        int j = posicionesIndefCruz[indexCruz][1];

        for (int valor = 0; valor < N; valor++) {
            matrizCruz[i][j] = valor;
            matrizCruz[j][i] = valor; // Asegurar simetría
            if (buscarSolucionRecursiva(matrizCruz, matrizEstrella, posicionesIndefCruz, totalIndefCruz, indexCruz + 1,
                                        posicionesIndefProd, totalIndefProd, indexProd,
                                        neutroCruz, neutroEstrella)) {
                return true;
            }
        }
        matrizCruz[i][j] = -1; // Restablecer la posición
        matrizCruz[j][i] = -1;
    }
    // Si no hay más posiciones en matrizCruz, procedemos con matrizEstrella
    else if (indexProd < totalIndefProd) {
        int i = posicionesIndefProd[indexProd][0];
        int j = posicionesIndefProd[indexProd][1];

        for (int valor = 0; valor < N; valor++) {
            matrizEstrella[i][j] = valor;
            matrizEstrella[j][i] = valor; // Asegurar simetría
            if (buscarSolucionRecursiva(matrizCruz, matrizEstrella, posicionesIndefCruz, totalIndefCruz, indexCruz,
                                        posicionesIndefProd, totalIndefProd, indexProd + 1,
                                        neutroCruz, neutroEstrella)) {
                return true;
            }
        }
        matrizEstrella[i][j] = -1; // Restablecer la posición
        matrizEstrella[j][i] = -1;
    }

    return false; // No se encontró solución en esta rama
}

// Función principal para buscar la solución
bool buscarSolucion(int matrizCruz[N][N], int matrizEstrella[N][N], int neutroCruz, int neutroEstrella) {
    int posicionesIndefCruz[N * N][2];
    int totalIndefCruz = 0;

    int posicionesIndefProd[N * N][2];
    int totalIndefProd = 0;

    // Identificar posiciones indefinidas en matrizCruz
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {            // Solo mitad superior
            if (matrizCruz[i][j] == -1) {
                posicionesIndefCruz[totalIndefCruz][0] = i;
                posicionesIndefCruz[totalIndefCruz][1] = j;
                totalIndefCruz++;
            }
        }
    }

    // Identificar posiciones indefinidas en matrizEstrella
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {            // Solo mitad superior
            if (matrizEstrella[i][j] == -1) {
                posicionesIndefProd[totalIndefProd][0] = i;
                posicionesIndefProd[totalIndefProd][1] = j;
                totalIndefProd++;
            }
        }
    }

    // Iniciar búsqueda recursiva
    return buscarSolucionRecursiva(matrizCruz, matrizEstrella,
                                   posicionesIndefCruz, totalIndefCruz, 0,
                                   posicionesIndefProd, totalIndefProd, 0,
                                   neutroCruz, neutroEstrella);
}
