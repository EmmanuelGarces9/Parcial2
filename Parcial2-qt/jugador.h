#ifndef JUGADOR_H
#define JUGADOR_H

#include "tablero.h"

class jugador
{
private:
    char color;
public:
    jugador(char color);

    bool vrf_mov_disp(tablero* tablero);

    char getColor() const;
};

#endif // JUGADOR_H
