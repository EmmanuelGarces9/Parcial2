#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;

jugador *juego::getJugadorActual() const
{
    return jugadorActual;
}

juego::juego(int tam_tablero, char colorJugador1, char colorJugador2)
{
    jugador1 = new jugador(colorJugador1);
    jugador2 = new jugador(colorJugador2);
    jugadorActual = jugador1;

    tableroDeJuego = new tablero(tam_tablero);
}

juego::~juego()
{
    delete jugador1;
    delete jugador2;
    delete tableroDeJuego;
}

void juego::realizar_movimiento(int fila, int columna)
{
    if(tableroDeJuego->validar_movimiento(fila,columna,jugadorActual->getColor())){
        tableroDeJuego->mover(fila,columna,jugadorActual->getColor());
    }else{
        cout<<"El movimiento no está permitido"<<endl;
    }
}

void juego::cambiar_turno()
{
    jugador* temp = jugador1;
    jugador1 = jugador2;
    jugador2 = temp;
}
