#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
#include <vector>
#include <stdio.h>

#include "include/Funciones.h"
#include "include/DistanciaEstadios.h"
#include "include/Equipo.h"


using namespace std;

int main(int argv, char** argc){
    std::vector<csv_info> info;
    get_csv(info);
    vector<DistanciaEstadios> distanciaEstadios = generarDistanciasEstadios(info);
    for(unsigned int i = 0; i < distanciaEstadios.size(); i++){
        std::cout << i << " " << std::endl;
        distanciaEstadios.at(i).MostrarDistancia(info);
        // ES necesario volcar la información de distanciaEstadios en algo utilizable para el programa.
    }
   
    // Llenar vector de equipos y estadios.
    std::vector<Equipo> equipos;
    std::vector <Estadio> estadios;
    for(int i = 1; i<19; i++){
        std::string _equipo = info[i].equipo;
        std::string _estadio = info[i].estadio;
        double latitud = info[i].latitud;
        double longitud = info[i].longitud;
        Equipo equipo(_equipo, _estadio);
        equipos.push_back(equipo);
        Estadio estadio = {};
        estadio.nombre = _estadio;
        estadio.estado = false;
        estadio.latitud = latitud;
        estadio.longitud = longitud;
        estadios.push_back(estadio);
    }
    // // Debugging cambios
    //std::cout << "TRYING" << std::endl;
    //std::vector<Equipo> pruebas;
    //partido test = {};
    //test.estadio = estadios.at(0).nombre;
    //test.local = 1;
    //test.visita = 2;
    //Equipo test_equipo(equipos.at(0).nombre, test.estadio);
    //test_equipo.guardarPartido(test, 0);
    //pruebas.push_back(test_equipo);
    //pruebas.push_back(test_equipo);
    //for(unsigned int i = 0; i<pruebas.size(); i++){
    //    std::cout << "Equipo: " << pruebas.at(i).nombre << std::endl;
    //}
    //if(partidosCompletados(pruebas, 0)){
    //    std::cout << "Partidos completados" << std::endl;
    //}
////
    
    //Para comprobar el struct tenga todos los datos nomas, la fila 0 son los encabezados, no se como sacarlos
    //std::cout << " ======= DEBUG =======" << std::endl;
    //for(int i = 1; i<19;i++){
    //    cout<<i;
    //    cout<<"- equipo: "<<info[i].equipo;
    //    cout<<" - comuna: "<<info[i].comuna;
    //    cout<<" - estadio: "<<info[i].estadio;
    //    cout<<" - latitud: "<<info[i].latitud;
    //    cout<<" - longitud: "<<info[i].longitud;
    //    cout<<endl;
    //}  

    return 0;
}