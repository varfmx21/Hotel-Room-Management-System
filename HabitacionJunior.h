#ifndef HABITAIONJUNIOR_H
#define HABITAIONJUNIOR_H

#include "Habitacion.h"

class HabitacionJunior : public Habitacion {
    private: 
        // Atributos

    public:
        // Métodos
        HabitacionJunior();
        HabitacionJunior(int numero);
        bool checkin(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif // HABITAIONJUNIOR_H