#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
#include <vector>
#include <stdio.h>

#include "include/Funciones.h"
#include "include/DistanciaEstadios.h"


using namespace std;

int main(int argv, char** argc){
    std::vector<csv_info> info;
    get_csv(info);
    vector<DistanciaEstadios> distanciaEstadios = generarDistanciasEstadios(info);
    for(unsigned int i = 0; i < distanciaEstadios.size(); i++){
        distanciaEstadios.at(i).MostrarDistancia(info);
    }
    //Para comprobar el struct tenga todos los datos nomas, la fila 0 son los encabezados, no se como sacarlos
    std::cout << " ======= DEBUG =======" << std::endl;
    for(int i = 1; i<19;i++){
        cout<<i;
        cout<<"- equipo: "<<info[i].equipo;
        cout<<" - comuna: "<<info[i].comuna;
        cout<<" - estadio: "<<info[i].estadio;
        cout<<" - latitud: "<<info[i].latitud;
        cout<<" - longitud: "<<info[i].longitud;
        cout<<endl;
    }  

    return 0;
}