#include "../include/Equipo.h"


Equipo::Equipo(std::string _nombre, std::string _estadio){
    nombre = _nombre;
    estadio = _estadio;
    local = 1;
    posicion = _estadio;
}

bool Equipo::revisarPartido(int equipo){
    for(unsigned int i = 0; i < this->partidos_jugados.size(); i++){
        if(partidos_jugados.at(i).local == equipo || partidos_jugados.at(i).visita == equipo){
            return true;
        }
    }
    return false;
}
void Equipo::guardarPartido(partido _partido){
    this->partidos_jugados.push_back(_partido);
}
