#include "../include/Funciones.h"

void participantes() {
    std::cout << std::endl << "=== Taller 2 ===" << std::endl;
    std::cout << std::endl << "Kevin Peralta"; 
    std::cout << std::endl << "Roberto Albornoz"; 
    std::cout << std::endl << "Sebastian Santelices" << std::endl; 
}

double haversine(double lat1, double lon1, 
                        double lat2, double lon2) 
    { 
        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        double a = pow(sin(dLat / 2), 2) +  
                   pow(sin(dLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double rad = 6371; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    }

void get_csv(std::vector<csv_info> &info){
    int cont = 0;
    std::ifstream file;
    std::string equipo,comuna, estadio,latitud,longitud;
    file.open("data/equipos.csv");
    while(file.good()){
        getline(file,equipo,';');
        getline(file,comuna,';');
        getline(file,estadio,';');
        getline(file,latitud,';');
        getline(file,longitud,'\n');
        info.push_back(csv_info());
        info[cont].equipo = equipo;
        info[cont].comuna = comuna;
        info[cont].estadio = estadio;
        std::string _latitud =   latitud.erase(latitud.length()-1,1).erase(0,1);
        std::string _longitud = longitud.erase(longitud.length()-1,1).erase(0,1);
        info[cont].latitud = atof(_latitud.c_str());
        info[cont].longitud = atof(_longitud.c_str());
        cont++;   
    }   
}

std::vector<DistanciaEstadios> generarDistanciasEstadios(std::vector<csv_info> &info){
    std::vector<DistanciaEstadios> DistanciasEst;
    for (int i = 1; i < 18 ; i++){
        for(int j = i+1; j< 19; j++){
            double Lat1, Lat2, Lon1, Lon2;
            Lat1 = info[i].latitud;
            Lon1 = info[i].longitud;
            Lat2 = info[j].latitud;
            Lon2 = info[j].longitud;
            double Distancia =  haversine(Lat1, Lon1, Lat2, Lon2);
            DistanciaEstadios Dist(i, j, Distancia);
            DistanciasEst.push_back(Dist);
        }
    }
    return DistanciasEst;
}
 

 void imprimirPartido(partido _partido, std::vector<Equipo> _equipos){
    std::cout << "Local: " << _equipos.at(_partido.local).nombre;
    std::cout << " - Visita: " << _equipos.at(_partido.visita).nombre;
    std::cout << " | Estadio  " << _partido.estadio << std::endl;
 }

 double calcularDistancia(Estadio _est1, Estadio _est2){
     double distancia, Lat1, Lat2, Lon1, Lon2;
     Lat1 = _est1.latitud;
     Lon1 = _est1.longitud;
     Lat2 = _est2.latitud;
     Lon2 = _est2.latitud;
     distancia = haversine(Lat1, Lon1, Lat2, Lon2);
     return distancia;
 }

 int menorDistancia(std::vector<Estadio> estadios_disponibles, int index){
     unsigned int indice_estadio = (unsigned int)index;
     unsigned int indice_menor;
     double menor_distancia = 999999;
     for(unsigned int i = 0; i < estadios_disponibles.size() ; i++){
         if(i == indice_estadio){
             continue;
         }else{
            double tmp_distancia = calcularDistancia(estadios_disponibles.at(index), estadios_disponibles.at(i));
            if(tmp_distancia < menor_distancia){
                indice_menor = i;
            }
         }
     }
     return indice_menor;
 }