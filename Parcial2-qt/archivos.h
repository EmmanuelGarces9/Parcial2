#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "jugador.h"
#include "tablero.h"
#include "juego.h"
#include <fstream>
#include <ctime>
#include <chrono>


class archivos
{
private:
    char* nombre_archivo;
public:
    archivos();
    void escribir_archivo(char* nombre_ganador, char* nombre_perdedor, int ganador, int fichas);
    void mostrar_historial();
};

#endif // ARCHIVOS_H
