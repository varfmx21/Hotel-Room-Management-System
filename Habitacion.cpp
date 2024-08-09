// Luis Fernando Valderrábano García, A01644530, TC1030.315

#include "Habitacion.h"

#include <iostream>
using namespace std;

Habitacion::Habitacion() {
    this->nombre = "";
    this->numero = 0;
    this->adultos = 0;
    this->infantes = 0;
    this->credito = 0;
    this->cargo = 0;
    this->disponible = true;
}

Habitacion::Habitacion(int numero) {
    this->numero = numero;
    this->disponible = true;
}

int Habitacion::getNumero() {
    return this->numero;
}

bool Habitacion::getDisponible() {
    return this->disponible;
}

void Habitacion::setNumero(int numero) {
    this->numero = numero;
}

bool Habitacion::checkin(string nombre, int adultos, int infantes, double credito) {
    if (disponible == true) {
        this->nombre = nombre;
        this->adultos = adultos;
        this->infantes = infantes;
        this->credito = credito;
        this->cargo = 0.0;
        this->disponible = false;
        return true;
    }
    return false;
}

bool Habitacion::checkout() {
    if (disponible == false){
        this->nombre = "";
        this->adultos = 0;
        this->infantes = 0;
        this->credito = 0;
        this->cargo = 0;
        this->disponible = true;
        return true;
    }
    return false;
}

double Habitacion::getTarifaBase() {
    return this->adultos * 650 + this->infantes * 250;
}


bool Habitacion::realizarCargo(double cantidad) {
    if (cantidad > 0 && (cargo + cantidad) <= credito){ 
        cargo += cantidad;
        return true;
    }
    return false;
}

string Habitacion::toString() {
    return to_string(numero) + ",Huesped:" + this->nombre + ",Tarifa Base:" + to_string(getTarifaBase()) + ",Credito:" + to_string(credito) + ",Cargos:" + to_string(cargo);
}

double operator+(double tarifa, Habitacion& h1) {
    double resultado = tarifa + h1.getTarifaBase();
    return resultado;
}