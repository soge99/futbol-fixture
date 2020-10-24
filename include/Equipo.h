#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
#include <vector>
#include "DistanciaEstadios.h"


/**
 * Estructura que almacena la informacion del csv
 */


class Equipo{
    private:
    public:
        std::string nombre;
        std::string estadio;
        std::vector<partido> partidos_jugados;
        std::string posicion;
        bool local;
        Equipo(std::string, std::string);
        bool revisarPartido(int);
        void guardarPartido(partido);
};






#endif // EQUIPO_H