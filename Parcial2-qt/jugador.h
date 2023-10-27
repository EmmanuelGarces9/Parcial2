#ifndef JUGADOR_H
#define JUGADOR_H

#include "tablero.h"
#include "archivos.h"
#include "juego.h"



class jugador
{
private:
    int color;
public:
    jugador(int color);
    int getColor() const;
    bool vrf_mov_disp(tablero* tablero);

};

#endif // JUGADOR_H
