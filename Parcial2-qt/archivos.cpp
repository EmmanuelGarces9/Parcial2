#include "archivos.h"

archivos::archivos()
{

}

void archivos::escribir_archivo(char *nombre_ganador, char *nombre_perdedor, int ganador, int fichas)
{
    fstream archivo;
    archivo.open(nombre_archivo, ios::app);
    if(archivo.is_open()){
        auto now = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(now);
             archivo<<"\nJugaron: "<<nombre_ganador<<" y "<<nombre_perdedor<< " en la fecha:"<<ctime(&end_time)<<'\n';
             archivo<<"Ganador: "<<nombre_ganador<<" con fichas: "<<fichas<<'\n';

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
        std::cout << "Error al abrir el archivo " << nombre_archivo <<endl;
    }

    archivo.close();
}
