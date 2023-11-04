#ifndef JUGADOR_H
#define JUGADOR_H

#include "tablero.h"

class jugador
{
private:
    char color;
public:
    jugador(char color);

    char getColor() const;



};

#endif // JUGADOR_H
