#include "tablero.h"

tablero::tablero(int tamaño)
{
    tamaño = tamaño;

    estado = new char*[tamaño]; // Inicializa la matriz del tablero
    for (int i = 0; i < tamaño; ++i) {
        estado[i] = new char[tamaño];
        for (int j = 0; j < tamaño; ++j) {
            estado[i][j] = '-';  // Inicializar todas las celdas vacias
        }
    }

    // Coloca las 4 fichas iniciales del tablero
    int centro = tamaño / 2;
    estado[centro - 1][centro - 1] = 'B';  // Ficha blanca
    estado[centro - 1][centro] = 'N';      // Ficha negra
    estado[centro][centro - 1] = 'N';      // Ficha negra
    estado[centro][centro] = 'B';          // Ficha blanca
}

tablero::~tablero()
{
    for (int i = 0; i < tamaño; ++i) {
        delete[] estado[i];
    }
    delete[] estado;
}

void tablero::mostrar()
{
    // Mostrar las letras de las columnas
    cout << "   ";
    for (char columna = 'A'; columna < 'A' + tamaño; ++columna) {
        cout << columna << " ";
}
    cout << endl;

    for (int i = 0; i < tamaño; ++i) {
        cout << i << "  "; // mostrar numero de fila
        for (int j = 0; j < tamaño; ++j) {
            cout << estado[i][j] << " "; //mostrar ficha en casilla
        }
        cout << endl;
    }
}

bool tablero::validar_movimiento(int fila, int columna, int color)
{

}

void tablero::mover(int fila, int columna, int color)
{

}
