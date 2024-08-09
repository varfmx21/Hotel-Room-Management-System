#ifndef HabitacionSuite_H
#define HabitacionSuite_H

#include "Habitacion.h"

class HabitacionSuite : public Habitacion {
    private:
        // Atributos
    
    public:
        // Métodos
        HabitacionSuite();
        HabitacionSuite(int numero);
        bool checkin(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif // HabitacionSuite_H