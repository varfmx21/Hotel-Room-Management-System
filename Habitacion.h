// Luis Fernando Valderrábano García, A01644530, TC1030.315

#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
using namespace std;

class Habitacion {
    protected:
        // Atributos
        string nombre;
        int numero,
            adultos,
            infantes;
        double credito,
               cargo;
        bool disponible;

       
    public:
        // Constructores
        Habitacion();
        Habitacion(int numero);

        // Métodos
        int getNumero();
        bool getDisponible();
        void setNumero(int numero);
        bool checkout();
        bool realizarCargo(double cantidad);
        // Métodos abstractos
        virtual bool checkin(string nombre, int adultos, int infantes, double credito);
        virtual double getTarifaBase();
        virtual string toString();
        // Sobrecargas
        friend double operator+(double tarifa, Habitacion& h1);
};

#endif // HABITACION_H