#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
using namespace std;

struct csv_info{
    string equipo;
    string comuna;
    string estadio;
    double latitud;
    double longitud;
}info[18];

// Haversine function
double haversine(double lat1, double lon1, 
                        double lat2, double lon2) 
    { 
        // distance between latitudes 
        // and longitudes 
        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  
        // convert to radians 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        // apply formulae 
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



int main(int argv, char** argc){

    get_csv();

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

    int k = 1;
    for (int i = 1; i < 18 ; i++){
        for(int j = i+1; j< 19; j++){
            double Lat1, Lat2, Lon1, Lon2;
            Lat1 = info[i].latitud;
            Lon1 = info[i].longitud;
            Lat2 = info[j].latitud;
            Lon2 = info[j].longitud;
            double Distancia =  haversine(Lat1, Lon1, Lat2, Lon2);
            cout << k << " La distancia entre " << info[i].estadio << " y " << info[j].estadio << " es: " << Distancia << " KM" << endl;
            k++;
        }
    }
    
   

    return 0;
}