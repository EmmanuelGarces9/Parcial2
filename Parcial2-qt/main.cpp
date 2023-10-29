#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;

int main()
{
    tablero tablero(8);
    tablero.mostrar();
    jugador Jugador1('B');
    jugador Jugador2('N');
    juego Juego(8,'B','N');

    while(true){
        int fila,columna,opcion;
        cout<<"Jugador en turno: "<< Juego.getJugadorActual()<<endl;
        cout<<"Ingrese 1 para hacer movimiento"<<endl;
        cout<<"Ingrese 2 para pasar turno"<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:{
            cout<<"Ingrese su movimiento(fila y columna)";
            cin>>fila>>columna;
            Juego.realizar_movimiento(fila,columna);
            break;
        }
        case 2:{
            Juego.cambiar_turno();
            break;
        }
        }
    }
}
