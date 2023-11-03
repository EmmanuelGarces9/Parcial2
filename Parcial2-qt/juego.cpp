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

bool juego::realizar_movimiento(int fila, int columna)
{
    if(tableroDeJuego->validar_movimiento(fila,columna,jugadorActual->getColor())){
        tableroDeJuego->mover(fila,columna,jugadorActual->getColor());
        return true;
    }else{
        cout<<"El movimiento no está permitido"<<endl;
        return false;
    }
}

void juego::cambiar_turno()
{
    jugador* temp = jugador1;
    jugador1 = jugador2;
    jugador2 = temp;
}

bool juego::vrf_fin_juego()
{
    if (tableroDeJuego->tablero_lleno()){
        return true;
    }

    bool no_mov_1 = !jugador1->vrf_mov_disp(tablero);
    bool no_mov_2 = !jugador2->vrf_mov_disp(tablero);

    if (no_mov_1 && no_mov_2) {
        return true;
    }
    return false;
}

char juego::vrf_ganador(int &fichas_ganador)
{
    int fichas_1=tableroDeJuego->contar_fichas(jugador1->getColor());
    int fichas_2=tableroDeJuego->contar_fichas(jugador2->getColor());

    if (fichas_1 > fichas_2) {
        fichas_ganador=fichas_1;
        return jugador1->getColor();
    }
    else if (fichas_2 > fichas_1) {
        fichas_ganador=fichas_2;
        return jugador2->getColor();
    }
    else {
        fichas_ganador=fichas_1;
        return 'e'; // Empate
    }

}

bool juego::pre_cambiar_turno()
{
    if(getJugadorActual()->vrf_mov_disp(tableroDeJuego)){
        return false;
    }
    return true;
}
