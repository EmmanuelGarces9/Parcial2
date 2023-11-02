#ifndef TABLERO_H
#define TABLERO_H

#include "jugador.h"

class tablero
{
private:
    int tam;
    char** estado;
public:
    tablero(int tam);
    ~tablero();
    void mostrar();
    bool validar_movimiento(int fila, int columna, char color);
    void mover(int fila, int columna, char color);
    void CambiarColorDeFichas(int fila, int columna, int deltaFila, int deltaColumna, char color);
};

#endif // TABLERO_H5
