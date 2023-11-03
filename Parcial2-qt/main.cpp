#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "jugador.h"
#include "archivos.h"

using namespace std;

int main()
{
    tablero tablero(8);
    tablero.mostrar();
    jugador jugador1('B');
    jugador jugador2('N');
    juego juego(8,'B','N');
    archivos archivo;
    char opcion, opcion1;
    bool jugando=false;
    while (!jugando) {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Jugar una partida" << endl;
        cout << "2. Ver el historial de partidas" << endl;
        cout << "Ingrese su elección (1 o 2): ";
        cin >> opcion1;
        if (opcion == '1') {
            jugando = true;
        } else if (opcion == '2') {
            archivo.mostrar_historial();
        } else {
            cout << "Opción no válida. Por favor, ingrese 1 o 2." << endl;
        }
    }

    while(jugando){
        if(juego.vrf_fin_juego()==false){
            int fila, columna, opcion;
            cout<<"Es el turno de las fichas: "<<juego.getJugadorActual()<<endl;
            cout<<"Ingrese 1 para realizar su movimiento o 2 para pasar de turno: "<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:{
                    cout<<"Ingrese la fila: "<<endl;
                    cin>>fila;
                    cout<<"Ingrese la columna"<<endl;
                    cin>>columna;
                    bool mov_valido=juego.realizar_movimiento(fila, columna);
                    while(mov_valido==false){
                        cout<<"movimiento no válido"<<endl;
                        cout<<"Ingrese la fila: "<<endl;
                        cin>>fila;
                        cout<<"Ingrese la columna"<<endl;
                        cin>>columna;
                        mov_valido=juego.realizar_movimiento(fila, columna);
                    }
                    if(mov_valido){
                        tablero.mostrar();
                        juego.cambiar_turno();
                    }
                    break;
                }
                case 2:{
                    if(juego.pre_cambiar_turno()) juego.cambiar_turno();
                    else cout<<"aun tiene movimientos disponibles, no puede cambiar de turno"<<endl;
                    break;
                }
            }
        }
        else{
            int fichas_Ganador=0;
            char ganador=juego.vrf_ganador(fichas_Ganador);
            char elganador[250];
            char elperdedor[250];
            if(ganador!='e'){
                cout << "El ganador es el Jugador " << ganador << " con " << fichasGanador << " fichas." << endl;
                cout<<"Escriba el nombre del jugador que gano: ";
                cin>>elganador;
                cout<<"Escriba el nombre del jugador que perdio ";
                cin>>elperdedor;
                archivo.escribir_archivo(elganador, elperdedor, ganador,fichas_Ganador, 1);
                jugando=false;
            }
            else{
                cout << "El juego quedó empatado con " << fichasGanador << " fichas." << endl;
                cout<<"Escriba el nombre de cada jugador uno por uno por favor: ";
                cin>>elganador;
                cout<<"Escriba el nombre del otro jugador: ";
                cin>>elperdedor;
                archivo.escribir_archivo(elganador, elperdedor, ganador,fichas_Ganador, 0);
                jugando=false;
            }

        }
    }
return 0;
}
