#include "archivos.h"

#include <iostream>


using namespace std;

archivos::archivos()
{
    nombre_archivo="historial.txt";
}

void archivos::escribir_archivo(char *nombre_ganador, char *nombre_perdedor, int fichas, bool comprobar)
{
    fstream archivo;
    archivo.open(nombre_archivo, ios::app);
    if(archivo.is_open()){
        auto now = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(now);
        archivo<<"\nJugaron: "<<nombre_ganador<<" y "<<nombre_perdedor<< " en la fecha:"<<ctime(&end_time)<<'\n';
        if (comprobar){
            archivo<<"Ganador: "<<nombre_ganador<<" con fichas: "<<fichas<<'\n';
        }
        else{
            archivo<<"Hubo empate con fichas: "<<fichas<<'\n';
        }

    }
    else{
        cout<<"error con los archivos"<<endl;
    }
    archivo.close();
}

void archivos::mostrar_historial()
{
    fstream archivo;
    archivo.open(nombre_archivo, std::ios::in);

    if (archivo.is_open()) {
        char linea[256]; // Tamaño suficiente para almacenar una línea
        while (archivo.getline(linea, sizeof(linea))) {
            cout << linea << endl;
        }
    }
    else {
        cout << "Error al abrir el archivo " << "historial" <<endl;
    }

    archivo.close();
}
