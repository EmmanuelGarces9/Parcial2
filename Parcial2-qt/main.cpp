#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "jugador.h"
#include "archivos.h"

using namespace std;

int main()
{

    int i=0;

    tablero tablero(8);
    tablero.mostrar();
    jugador jugador1('B');
    jugador jugador2('N');
    juego juego(8,'B','N');
    archivos archivo;

    while(true){
        if(juego.vrf_fin_juego()==false){
            int fila, columna, opcion;
            cout<<"Es el turno de las fichas: "<<juego.getJugadorActual();<<endl;
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
                }
                case 2:{
                    if(juego.pre_cambiar_turno()) juego.cambiar_turno();
                    else cout<<"aun tiene movimientos disponibles, no puede cambiar de turno"<<endl;
                }
            }
        }
        else{
            int fichas_Ganador;
            char ganador=juego.vrf_ganador(fichas_Ganador);
            if(ganador!='e'){
                cout << "El ganador es el Jugador " << ganador << " con " << fichasGanador << " fichas." << endl;
                char elganador[250];
                char elperdedor[250];
                cout<<"Escriba el nombre del jugador que gano: ";
                cin>>elganador;
                cout<<"Escriba el nombre del jugador que perdio ";
                cin>>elperdedor;
                archivo.escribir_archivo(elganador, elperdedor, ganador,fichas_Ganador);
            }


        }
    }

}
