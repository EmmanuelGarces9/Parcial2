#ifndef TABLERO_H
#define TABLERO_H


#include "jugador.h"
#include "archivos.h"
#include "juego.h"


class tablero
{
private:
    int tamano;
    char** estado;
public:
    tablero(int tamano);
    ~tablero();
    void mostrar();
    bool validar_movimiento(int fila, int columna, int color);
    void mover(int fila, int columna, int color);
};

#endif // TABLERO_H
