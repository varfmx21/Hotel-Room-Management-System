// Luis Fernando Valderrábano García, A01644530, TC1030.315

#ifndef HOTEL_H
#define HOTEL_H

#include "Habitacion.h"
#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

class Hotel {
    private:
        // Atributos    
        string nombre;
        vector<Habitacion*> habitaciones;
        int numHabitaciones;
    
    public:
        // Constructor
        Hotel(string nombre,int hJ,int hS,int hD);

        // Métodos
        int checkin(string nombre, int adultos, int infantes, double credito, int tipoHabitacion);
        bool checkout(int numHabitaciones);
        bool realizarCargosHabitacion(int numHabitaciones, double cargo);
        double getTotalXTarifaBase();
        void imprimeOcupacion();

        // Sobrecargas
        Habitacion* operator[](int numHabitacion);
        friend ostream& operator<<(ostream& os, Hotel& h1) {
            os<<"Hotel: "<<h1.nombre<<'\n';
            for (Habitacion* habitacion : h1.habitaciones) {
                if (habitacion->getDisponible() == true)
                    continue;
                os<<habitacion->toString()<<'\n';
            }
            os<<"Total acumulado por tarifa base: $"<<h1.getTotalXTarifaBase()<<'\n';
            return os;
        }
};

#endif // HOTEL_H