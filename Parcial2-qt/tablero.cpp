#include <iostream>
#include "tablero.h"
#include "jugador.h"

using namespace std;

tablero::tablero(int tam)
{
    this->tam = tam;

    estado = new char*[tam]; // Inicializa la matriz del tablero
    for (int i = 0; i < tam; ++i) {
        estado[i] = new char[tam];
    }
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            estado[i][j] = '-';  // Inicializar todas las celdas vacias
        }
    }
    // Coloca las 4 fichas iniciales del tablero
    int centro = tam / 2;
    estado[centro - 1][centro - 1] = 'B';  // Ficha blanca
    estado[centro - 1][centro] = 'N';      // Ficha negra
    estado[centro][centro - 1] = 'N';      // Ficha negra
    estado[centro][centro] = 'B';          // Ficha blanca
}

tablero::~tablero()
{
    for (int i = 0; i < tam; ++i) {
        delete[] estado[i];
    }
    delete[] estado;
}

void tablero::mostrar()
{
    // Mostrar las letras de las columnas
    cout << "   ";
    for (char columna = 'A'; columna < 'A' + tam; ++columna) {
        cout << columna << " ";
}
    cout << endl;

    for (int i = 0; i < tam; ++i) {
        cout << i+1 << "  "; // mostrar numero de fila
        for (int j = 0; j < tam; ++j) {
            cout << estado[i][j] << " "; //mostrar ficha en casilla
        }
        cout << endl;
    }
}

bool tablero::validar_movimiento(int fila, int columna, char color)
{

}

void tablero::mover(int fila, int columna, char color)
{

}
