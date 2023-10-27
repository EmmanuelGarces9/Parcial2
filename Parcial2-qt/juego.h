#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "tablero.h"
#include "archivos.h"


class juego
{
private:
    jugador* jugador1;
    jugador* jugador2;
    tablero* tablero;

public:
    juego(int tam_tablero, int color1, int color2);
    ~juego();
    void realizar_movimiento(int fila, int columna);
    void cambiar_turno();
    bool vrf_fin_juego();
    int vrf_ganador();


};

#endif // JUEGO_H
