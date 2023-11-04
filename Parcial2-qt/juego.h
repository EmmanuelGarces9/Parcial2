#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "tablero.h"

class juego
{
private:
    jugador* jugador1;
    jugador* jugador2;
    jugador* jugadorActual;
    tablero* tableroDeJuego;

public:
    juego(int tam_tablero, char colorJugador1, char colorJugador2);
    ~juego();
    bool realizar_movimiento(int fila, int columna);
    void cambiar_turno();
    bool vrf_fin_juego();
    char vrf_ganador(int &fichas_ganador);
    bool pre_cambiar_turno();
    jugador *getJugadorActual() const;
    tablero *getTableroDeJuego() const;
};

#endif // JUEGO_H
