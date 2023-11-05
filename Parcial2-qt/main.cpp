#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "jugador.h"
#include "archivos.h"

using namespace std;

int main()
{
    int tam=8;
    jugador jugador1('B');
    jugador jugador2('N');
    juego juego(tam,'B','N');
    archivos archivo;
    juego.getTableroDeJuego()->mostrar();
    char opcion, opcion1;
    bool jugando=false;
    while (!jugando) {
        cout << "Que desea hacer?" << endl;
        cout << "1. Jugar una partida" << endl;
        cout << "2. Ver el historial de partidas" << endl;
        cout << "Ingrese su eleccion (1 o 2): ";
        cin >> opcion1;
        if (opcion1 == '1') {
            jugando = true;
        } else if (opcion1 == '2') {
            archivo.mostrar_historial();
        } else {
            cout << "Opcion no valida. Por favor, ingrese 1 o 2." << endl;
        }
    }

    while(jugando){
        if(juego.vrf_fin_juego()==false){
            char fila,columna,opcion;
            cout<<"Es el turno de las fichas: "<<juego.getJugadorActual()->getColor()<<endl;
            cout<<"Ingrese 1 para realizar su movimiento o 2 para pasar de turno: "<<endl;
            cin>>opcion;
            switch(opcion){
                case '1':{
                    bool cambiar=true;
                    bool n=false;
                    cout<<"Ingrese la fila: "<<endl;
                    cin>>fila;
                    cout<<"Ingrese la columna"<<endl;
                    cin>>columna;
                    int fila_int=(int)(fila-'0');
                    int col=columna-'A'+1;
                    bool mov_valido=juego.realizar_movimiento(fila_int, col);
                    while(mov_valido==false){
                        char opcion2;
                        cout<<"Desea pasar el turno? Ingrese 1 si desea pasar el turno o 2 si desea intentar mover de nuevo"<<endl;
                        cin>>opcion2;
                        if(opcion2=='1'){
                            if(juego.pre_cambiar_turno()){
                                juego.cambiar_turno();
                                mov_valido=true;
                                cambiar=false;
                            }
                            else{
                                cout<<"Aun tiene movimientos disponibles, no puede cambiar de turno"<<endl;
                                n=true;
                            }
                        }
                        else if(opcion2=='2' or n==true){
                            cout<<"Ingrese la fila: "<<endl;
                            cin>>fila;
                            cout<<"Ingrese la columna"<<endl;
                            cin>>columna;
                            fila_int=(int)(fila-'0');
                            col=columna-'A'+1;
                            mov_valido=juego.realizar_movimiento(fila_int, col);
                        }
                        else{
                            cout<<"Opcion no valida. Ingrese una opcion valida"<<endl;
                        }
                    }
                    if(mov_valido and cambiar){
                        juego.getTableroDeJuego()->mostrar();
                        juego.cambiar_turno();
                    }
                    break;
                }
                case '2':{
                    if(juego.pre_cambiar_turno()) juego.cambiar_turno();
                    else cout<<"aun tiene movimientos disponibles, no puede cambiar de turno"<<endl;
                    break;
                }
                default:{
                    cout<<"no es una opcion valida, ingrese 1 o 2"<<endl;
                }


            }
        }
        else{
            int fichas_Ganador=0;
            char ganador=juego.vrf_ganador(fichas_Ganador);
            char elganador[250];
            char elperdedor[250];
            if(ganador!='e'){
                cout << "El ganador es el Jugador " << ganador << " con " << fichas_Ganador << " fichas." << endl;
                cout<<"Escriba el nombre del jugador que gano: ";
                cin>>elganador;
                cout<<"Escriba el nombre del jugador que perdio ";
                cin>>elperdedor;
                archivo.escribir_archivo(elganador, elperdedor, fichas_Ganador, 1);
                jugando=false;
            }
            else{
                cout << "El juego quedó empatado con " << fichas_Ganador << " fichas." << endl;
                cout<<"Escriba el nombre de cada jugador uno por uno por favor: ";
                cin>>elganador;
                cout<<"Escriba el nombre del otro jugador: ";
                cin>>elperdedor;
                archivo.escribir_archivo(elganador, elperdedor, fichas_Ganador, 0);
                jugando=false;
            }

        }
    }
return 0;
}
