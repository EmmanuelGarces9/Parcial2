#include <iostream>
#include "tablero.h"
#include "jugador.h"


using namespace std;


char tablero::obtenerValor(int fila, int columna)
{
    return estado[fila][columna];
}

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
    fila=fila-1; columna=columna-1;
    // Verifica si el movimiento esta dentro de los limites del tablero y si la celda esta vacia
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
            bool captura = false;

            // Verifica si hay fichas capturables en esta direccion
            while (f >= 0 && f < tam && c >= 0 && c < tam) {
                if (estado[f][c] == oponente) {
                    captura = true; // El movimiento es valido
                }else if (estado[f][c] == color) {
                    if (captura) { //Solo es valido si tha capturado alguna ficha del oponente
                        return true; // El movimiento es valido
                    }else{
                        break; // No hay fichas capturables en esta direccion
                    }
                } else if (estado[f][c] == '-') {
                    break; // No hay fichas capturables en esta direccion
                }

                // Mueve en la misma dirección
                f += direcciones[i][0];
                c += direcciones[i][1];
            }
        }
    }

    return false; // El movimiento no es valido
}

void tablero::mover(int fila, int columna, char color)
{
    int direcciones[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    estado[fila-1][columna-1] = color;
    for (int i = 0; i < 8; ++i) {
        CambiarColorDeFichas(fila, columna, direcciones[i][0], direcciones[i][1], color);
    }
}

void tablero::CambiarColorDeFichas(int fila, int columna, int deltaFila, int deltaColumna, char color)
{
    fila=fila-1; columna=columna-1;
    int f = fila + deltaFila;
    int c = columna + deltaColumna;
    bool captura = false;

    while (f >= 0 && f < tam && c >= 0 && c < tam) {
        if (estado[f][c] == '-') {
            // Si encontramos una casilla vacia, no hay fichas capturadas en esta direccion
            break;
        }
        if (estado[f][c] == color) {
            // Si encontramos una ficha del mismo color se debe capturar las intermedias
            captura = true;
            break;
        }
        // Continuar en la misma dirección
        f += deltaFila;
        c += deltaColumna;
    }

    // Cambiar el color de las fichas capturadas
    if (captura) {
        f = fila + deltaFila;
        c = columna + deltaColumna;
        while (estado[f][c] != color) {
            estado[f][c] = color;
            f += deltaFila;
            c += deltaColumna;
        }
    }
}

bool tablero::tablero_lleno()
{
    for (int fila = 0; fila < tam; fila++) {
           for (int columna = 0; columna < tam; columna++) {
               if (estado[fila][columna] == '-') {
                    return false;
               }
           }
       }
    return true;
}

int tablero::contar_fichas(char color)
{
    int fichas=0;
    for (int fila = 0; fila < tam; fila++) {
        for (int columna = 0; columna < tam; columna++) {
            if (estado[fila][columna]==color){
                fichas++;
            }
        }
    }
    return fichas;
}

bool tablero::vrf_mov_disp(char color)
{

    for (int fila = 0; fila < tam; ++fila) {
        for (int columna = 0; columna < tam; ++columna) {
            if (obtenerValor(fila,columna) == '-') {
                // Si la celda esta vacia, verificar si es un movimiento valido para el jugador actual
                if (validar_movimiento(fila+1, columna+1, color)) {
                    return true; //El jugador si tiene movimientos disponibles
                }
            }
        }
    }
    return false;
}










