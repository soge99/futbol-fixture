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
#include "Equipo.h"


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


/**
 * Imprime un partido con el nombre de los equipos y el estadio.
 */
void imprimirPartido(partido , std::vector<Equipo>);

/**
 * Retorna la distancia entre dos estadios.
 */
double calcularDistancia(Estadio , Estadio);

/**
 * Retorna el índice del estadio más cercano al estadio en el índice 
 * entregado como parámetro
 */
int menorDistancia(std::vector<Estadio> , int );

/**
 * Revisa si todos los equipos terminaron los partidos que
 * le corresponden para la fase ingresada.
 */
bool partidosCompletados(std::vector<Equipo> , int );


/**
 * Algoritmo de ordenamiento que crea el Fixture enfocándose en la distancia mínima
 */
void fixture(std::vector<Equipo>, std::vector <Estadio>);

#endif /* FUNCIONES_H */