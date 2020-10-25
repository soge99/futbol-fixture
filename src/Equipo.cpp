#include "../include/Equipo.h"

/**
 * Constructor
 */
Equipo::Equipo(std::string _nombre, std::string _estadio){
    nombre = _nombre;
    estadio = _estadio;
    local = 1;
    posicion = _estadio;
}



/**
 * Retorna true o false dependiendo si el equipo ha jugado contra un equipo en particular.
 */
bool Equipo::revisarPartido(int equipo, int fase){
    if(fase==0){
        for(unsigned int i = 0; i < this->partidos_jugados_fase1.size(); i++){
            if(partidos_jugados_fase1.at(i).local == equipo || partidos_jugados_fase1.at(i).visita == equipo){
                return true;
            }
        }
        return false;
    }else{
        for(unsigned int i = 0; i < this->partidos_jugados_fase2.size(); i++){
            if(partidos_jugados_fase2.at(i).local == equipo || partidos_jugados_fase2.at(i).visita == equipo){
                return true;
            }
        }
        return false;
    }
}


/**
 * Agrega un partido (struct partido) a los partidos jugados del equipo.
 */
void Equipo::guardarPartido(partido _partido, int fase){
    if(fase == 0){
        this->partidos_jugados_fase1.push_back(_partido);
    }else{
        this->partidos_jugados_fase2.push_back(_partido);
    }
    
}
