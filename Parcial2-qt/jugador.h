#ifndef JUGADOR_H
#define JUGADOR_H


class jugador
{
private:
    int color;
public:
    jugador(char color);
    bool vrf_mov_disp();
    int getColor() const;
};

#endif // JUGADOR_H
