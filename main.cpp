#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
#include <vector>
#include <stdio.h>
#define MAX 99999999;

using namespace std;

struct csv_info{
    string equipo;
    string comuna;
    string estadio;
    double latitud;
    double longitud;
}info[18];

struct Enfrentamientos{
    int Local;
    int Visita;
};
struct Equipo{
    int id;
    int EstadioActual;
};


void imprimirEnfrentamientos(int A[17][18]){ // se borra
    for(int i = 0; i < 17 ; i++){
        for (int j=0; j<9 ; j++){
            cout << A[i][2*j] << "-" << A[i][2*j+1] << " ";
        }
        cout << endl;
    }
}

void GenerarEnfrentamientos(int enfrentamientos[17][18]){
    int equipo1=1;
    for (int i = 0; i < 17 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(equipo1 == 18) equipo1 = 1;
            if(j==0 && i%2!=0){
                enfrentamientos[i][1] = equipo1;
            }else{
                enfrentamientos[i][2*j] = equipo1;
            }
            equipo1++; 
        }
    }
    for(int i = 0; i<17 ; i++){
        if(i%2 == 0){
            enfrentamientos[i][1] = 18;
        }else{
            enfrentamientos[i][0] = 18;
        }
    }
    int equipo2 = 17;
    for (int i = 0; i < 17 ; i++){
        for(int j = 1 ; j < 9 ; j++){
            if(equipo2 == 0) equipo2 = 17;
            enfrentamientos[i][2*j+1] = equipo2;
            equipo2--;
        }
    }
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

double calcularDistanciaEstadios(int E1, int E2, csv_info csv[]){
                double Lat1 = info[E1].latitud;
                double Lon1 = info[E1].longitud;
                double Lat2 = info[E2].latitud;
                double Lon2 = info[E2].longitud; 
                return haversine(Lat1, Lon1, Lat2, Lon2);
}

int distanciaMinima(int enfrentamientos[17][18], int EstadiosActuales[18], int FechaElegida[17]){
    double Menor = MAX;
    int PosMenor = 0;
    for (int i = 0; i< 17 ; i++){
        if(FechaElegida[i]!= 1){
            double Suma = 0;
            for (int j=0; j<9; j++){
                Suma +=  calcularDistanciaEstadios(EstadiosActuales[enfrentamientos[i][2*j]-1] , EstadiosActuales[enfrentamientos[i][2*j+1] - 1], info);
            }
                if (Suma < Menor){
                    Menor = Suma;
                    PosMenor=i;
                
            }
        }
    }
    return PosMenor;
}

void imprimirOrdenFechas(int ordenEnfrentamientos[17], int Enfrentamientos[17][18]){
    for (int i = 0; i <17 ; i++){
        
        for (int j=0 ; j < 9 ; j++){
            cout<< Enfrentamientos[ordenEnfrentamientos[i]][2*j] << "-" << Enfrentamientos[ordenEnfrentamientos[i]][2*j+1] << " ";
        }
        cout << "Fecha " << i+1 ;
        cout << endl;
    }
}

int main(int argv, char** argc){
    int Enfrentamientos[17][18];
    int ordenEnfrentamientos[17];
    int FechaElegida[17];
    int EstadioActual[18];
    int posMenor;
    for(int i = 0 ; i < 18 ; i++){
        EstadioActual[i] = i+1;
    }
    GenerarEnfrentamientos(Enfrentamientos);
    imprimirEnfrentamientos(Enfrentamientos);
    cout << "------------------\n"; 
    get_csv();

    cout<< "estadio actual: ";
        for (int j = 0; j < 18 ; j ++){
                cout << EstadioActual[j] << " ";
        }cout << endl;
    for(int i = 0; i<17 ; i ++){
            posMenor = distanciaMinima(Enfrentamientos, EstadioActual, FechaElegida);
            FechaElegida[posMenor] = 1;
            ordenEnfrentamientos[i] = posMenor;
            for(int j = 0 ; j < 9 ; j ++){
                EstadioActual [Enfrentamientos[posMenor][2*j+1] -1 ] = EstadioActual [Enfrentamientos[posMenor][2*j] -1 ];
            }
        
        cout<< "estadio actual: ";
        for (int j = 0; j < 18 ; j ++){
                cout << EstadioActual[j] << " ";
        }cout << endl;
    }
    imprimirOrdenFechas( ordenEnfrentamientos, Enfrentamientos );
    return 0;
}