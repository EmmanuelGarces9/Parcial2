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
    int direcciones[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    // Verifica si el movimiento está dentro de los límites del tablero y si la celda está vacía
    if (fila >= 0 && fila < tam && columna >= 0 && columna < tam && estado[fila][columna] == '-') {
        // Determina el color del oponente
        char oponente;
        if (color == 'N') {
            oponente='B'; // Si el color es 'X', el oponente es 'O'
        }else{
            oponente='N';
        }

        // Verifica las direcciones para fichas capturables
        for (int i = 0; i < 8; ++i) {
            int f = fila + direcciones[i][0];
            int c = columna + direcciones[i][1];
            bool atrapa = false;

            // Verifica si hay fichas capturables en esta dirección
            while (f >= 0 && f < tam && c >= 0 && c < tam) {
                if (estado[f][c] == oponente) {
                    atrapa = true; // El movimiento es válido
                }else if (estado[f][c] == color) {
                    if (atrapa) {
                        return true; // El movimiento es válido
                    }else {
                        break; // No hay fichas capturables en esta dirección
                    }
                } else if (estado[f][c] == '-') {
                    break; // No hay fichas capturables en esta dirección
                }

                // Mueve en la misma dirección
                f += direcciones[i][0];
                c += direcciones[i][1];
            }
        }
    }

    return false; // El movimiento no es válido
}

void tablero::mover(int fila, int columna, char color)
{
    estado[fila-1][columna-1]=color;
}
