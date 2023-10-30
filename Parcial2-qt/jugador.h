#ifndef JUGADOR_H
#define JUGADOR_H

#include "tablero.h"

class jugador
{
private:
    int color;
public:
    jugador(char color);

//    bool vrf_mov_disp(tablero* tablero);

    int getColor() const;
};

#endif // JUGADOR_H
