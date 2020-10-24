#ifndef DISTANCIAESTADIOS_H
#define DISTANCIAESTADIOS_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Estructura que almacena la informacion del csv
 */
struct csv_info{
    std::string equipo;
    std::string comuna;
    std::string estadio;
    double latitud;
    double longitud;
};

struct partido{
    int local;
    int visita;
    std::string estadio;
};

struct Estadio{
    std::string nombre;
    bool estado;
    std::vector<partido> partidos_jugados;
    double latitud;
    double longitud;
};


/**
 * Clase de Distancias entre varios equipos.
 */
class DistanciaEstadios{
    private:
    public:
        int Estadio1;
        int Estadio2;
        double Distancia;
        DistanciaEstadios(int, int, double);
        void MostrarDistancia(std::vector<csv_info>);
};






#endif // DISTANCIAESTADIOS_H