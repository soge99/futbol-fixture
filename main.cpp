#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
#include <vector>
#include <stdio.h>

using namespace std;

struct csv_info{
    string equipo;
    string comuna;
    string estadio;
    double latitud;
    double longitud;
}info[18];

class DistanciaEstadios{
    private:
    public:
        int Estadio1;
        int Estadio2;
        double Distancia;
        DistanciaEstadios(int, int, double);
        void MostrarDistancia(csv_info*);
};
DistanciaEstadios::DistanciaEstadios(int _Estadio1, int _Estadio2, double _Distancia){
    Estadio1 = _Estadio1;
    Estadio2 = _Estadio2;
    Distancia = _Distancia;
}

void DistanciaEstadios::MostrarDistancia(csv_info csv[]){
        cout  << csv[this->Estadio1].equipo;
        cout << " v/s " << csv[this->Estadio2].equipo; 
        cout << ", Distancia: " << this->Distancia << endl;
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

void get_csv(){
    int cont = 0;
    ifstream file;
    string equipo,comuna, estadio,latitud,longitud;
    file.open("./data/equipos.csv");
    while(file.good()){
        getline(file,equipo,';');
        getline(file,comuna,';');
        getline(file,estadio,';');
        getline(file,latitud,';');
        getline(file,longitud,'\n');
        info[cont].equipo = equipo;
        info[cont].comuna = comuna;
        info[cont].estadio = estadio;
        string _latitud =   latitud.erase(latitud.length()-1,1).erase(0,1);
        string _longitud = longitud.erase(longitud.length()-1,1).erase(0,1);
        info[cont].latitud = atof(_latitud.c_str());
        info[cont].longitud = atof(_longitud.c_str());
        cont++;   
    }   
}

vector<DistanciaEstadios> generarDistanciasEstadios(csv_info csv[]){
    vector<DistanciaEstadios> DistanciasEst;
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

int main(int argv, char** argc){

    get_csv();
    vector<DistanciaEstadios> distanciaEstadios = generarDistanciasEstadios(info);
    for(unsigned int i = 0; i < distanciaEstadios.size(); i++){
        distanciaEstadios.at(i).MostrarDistancia(info);
    }
    //Para comprobar el struct tenga todos los datos nomas, la fila 0 son los encabezados, no se como sacarlos
    /*for(int i = 1; i<19;i++){
        cout<<i;
        cout<<"- equipo: "<<info[i].equipo;
        cout<<" - comuna: "<<info[i].comuna;
        cout<<" - estadio: "<<info[i].estadio;
        cout<<" - latitud: "<<info[i].latitud;
        cout<<" - longitud: "<<info[i].longitud;
        cout<<endl;
    }*/  

    return 0;
}