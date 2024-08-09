#ifndef HabitacionDeluxe_H
#define HabitacionDeluxe_H

#include "Habitacion.h"

class HabitacionDeluxe : public Habitacion {
    private:
        // Atributos
    
    public:
        // Métodos
        HabitacionDeluxe();
        HabitacionDeluxe(int numero);
        bool checkin(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif // HabitacionDeluxe_H