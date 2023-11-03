#include "tablero.h"
#include "jugador.h"
#include "juego.h"

char jugador::getColor() const
{
    return color;
}

jugador::jugador(char color)
{
    this->color=color;
}
