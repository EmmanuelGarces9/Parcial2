#ifndef JUGADOR_H
#define JUGADOR_H


class jugador
{
private:
    char color;
public:
    jugador(char color);


    bool vrf_mov_disp(tablero* tablero);

    char getColor() const;

    bool vrf_mov_disp();

};

#endif // JUGADOR_H
