#include "jugador.h"
#include "tablero.h"
#include "juego.h"

int jugador::getColor() const
{
    return color;
}

jugador::jugador(char color)
{
    this->color=color;
}
