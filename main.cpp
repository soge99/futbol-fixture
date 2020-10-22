#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct csv_info{
    string equipo;
    string comuna;
    string estadio;
    string latitud;
    string longitud;
}info[18];

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
        info[cont].latitud = latitud;
        info[cont].longitud = longitud;
        
        cont++;   
    }   
}


int main(int argv, char** argc){

    get_csv();
    /*Para comprobar el struct tenga todos los datos nomas, la fila 0 son los encabezados, no se como sacarlos
    for(int i = 1; i<19;i++){
        cout<<i;
        cout<<"- equipo: "<<info[i].equipo;
        cout<<" - comuna: "<<info[i].comuna;
        cout<<" - estadio: "<<info[i].estadio;
        cout<<" - latitud: "<<info[i].latitud;
        cout<<" - longitud: "<<info[i].longitud;
        cout<<endl;
    }
    */

    return 0;
}