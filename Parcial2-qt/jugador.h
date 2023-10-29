#ifndef JUGADOR_H
#define JUGADOR_H

class jugador
{
private:
    int color;
public:
    jugador(char color);
    char getColor() const;
    //bool vrf_mov_disp(tablero* tablero);

};

#endif // JUGADOR_H
