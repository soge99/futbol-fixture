#include "../include/DistanciaEstadios.h"


/**
 * Constructor
 */
DistanciaEstadios::DistanciaEstadios(int _Estadio1, int _Estadio2, double _Distancia){
    Estadio1 = _Estadio1;
    Estadio2 = _Estadio2;
    Distancia = _Distancia;
}


/**
 * Imprime la distancia entre dos equipos
 */
void DistanciaEstadios::MostrarDistancia(std::vector<csv_info> csv){
        std::cout  << csv[this->Estadio1].estadio;
        std::cout << " v/s " << csv[this->Estadio2].estadio; 
        std::cout << ", Distancia: " << this->Distancia << std::endl;
}

