#include "jugador.h"
#include "juego.h"
#include "tablero.h"

char jugador::getColor() const
{
    return color;
}


jugador::jugador(char color)
{
    this->color=color;
}
