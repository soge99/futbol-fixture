CXX = g++
CXXFLAGS = -g3 -Wall -fopenmp
MKDIR = mkdir -p

LIBS = -lm

clean:
	rm -fr *.o a.out core programa dist build
 
directorios:
	$(MKDIR) build dist

DistanciaEstadios.o: directorios src/DistanciaEstadios.cpp include/DistanciaEstadios.h
	$(CXX) $(CXXFLAGS) -c src/DistanciaEstadios.cpp -o build/DistanciaEstadios.o

Funciones.o: directorios src/Funciones.cpp include/Funciones.h
	$(CXX) $(CXXFLAGS) -c src/Funciones.cpp -o build/Funciones.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o DistanciaEstadios.o Funciones.o 
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/DistanciaEstadios.o build/Funciones.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all