// Luis Fernando Valderrábano García, A01644530, TC1030.315

#include "Hotel.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include <iostream>

Hotel::Hotel(string nombre,int hJ,int hS,int hD) {
    this->nombre = nombre;
    int c = 0;
    for(int i = 0; i < hJ; i++){
        habitaciones.push_back(new HabitacionJunior(100 + c++));
    }
    for(int i = 0; i < hS; i++){
        habitaciones.push_back(new HabitacionSuite(100 + c++));
    }
    for(int i = 0; i < hD; i++){
        habitaciones.push_back(new HabitacionDeluxe(100 + c++));
    }
    numHabitaciones = habitaciones.size();
}

int Hotel::checkin(string nombre, int adultos, int infantes, double credito, int tipoHabitacion) {
    for (int i = 0; i < habitaciones.size(); i++) {
        if(habitaciones[i]->getDisponible()){
            if ((tipoHabitacion == 1 && dynamic_cast<HabitacionJunior*>(habitaciones[i])) || 
                (tipoHabitacion == 2 && dynamic_cast<HabitacionSuite*>(habitaciones[i])) || 
                (tipoHabitacion == 3 && dynamic_cast<HabitacionDeluxe*>(habitaciones[i]))){
                if (habitaciones[i]->checkin(nombre, adultos, infantes, credito)) {
                    return habitaciones[i]->getNumero();
                }   
            }
        }
    }
    return -1;
}

bool Hotel::checkout(int numHabitaciones) {
    for (int i = 0; i < habitaciones.size(); i++) {
        if (habitaciones[i]->getNumero() == numHabitaciones) {
            return habitaciones[i]->checkout();
        }
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int numHabitaciones, double cargo) {
    for (int i = 0; i < habitaciones.size(); i++) {
        if (habitaciones[i]->getNumero() == numHabitaciones) {
            return habitaciones[i]->realizarCargo(cargo);
        }
    }
    return false;
}

double Hotel::getTotalXTarifaBase() {
    double total = 0.0;
    for (int i = 0; i < habitaciones.size(); i++) {
        if(!habitaciones[i]->getDisponible()) {
            total += habitaciones[i]->getTarifaBase();
        }
    }
    return total;
}

void Hotel::imprimeOcupacion() {
    cout<<"\nOcupacion en "<<nombre<<'\n';
    for(int i = 0; i < habitaciones.size(); i++) {
        if (habitaciones[i]->getDisponible() == true) {
            continue;
        }
        cout<<habitaciones[i]->toString()<<'\n';
    }
}

Habitacion* Hotel::operator[](int numHabitacion) {
    for (Habitacion* habitacion : habitaciones) {
        if (habitacion->getNumero() == numHabitacion) {
            return const_cast<Habitacion*>(habitacion);
        }
    }
    return nullptr;
}