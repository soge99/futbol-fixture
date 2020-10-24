#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath> 
#include <cstdlib>

#include "DistanciaEstadios.h"


/**
 * Función que muestra los participantes del grupo
 */
void participantes();

/**
 * Función que calcula las distancias entre dos puntos en base a latitud y longitud.
 */
double haversine(double , double , double , double ); 

/**
 * Función que recupera los datos del csv y los inserta dentro de la estructura.
 */
void get_csv(std::vector<csv_info> &);


/**
 * Retorna un vector de Distancias entre cada uno de los estadios a modo de matriz.
 */
std::vector<DistanciaEstadios> generarDistanciasEstadios(std::vector<csv_info> &);


#endif /* FUNCIONES_H */