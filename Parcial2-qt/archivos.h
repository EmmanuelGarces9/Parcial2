#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "jugador.h"
#include "tablero.h"
#include "juego.h"


class archivos
{
private:
    char* nombrearchivo;
public:
    archivos();
    void escribir_archivo(char* nombre_ganador, char* nombre_perdedor, int ganador, int fichas);
    void mostrar_historial();
};

#endif // ARCHIVOS_H