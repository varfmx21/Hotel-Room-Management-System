#include "HabitacionJunior.h"

HabitacionJunior::HabitacionJunior() : Habitacion() {}

HabitacionJunior::HabitacionJunior(int numero) : Habitacion(numero) {}

bool HabitacionJunior::checkin(string nombre, int adultos, int infantes, double credito) {
    // Si la habitación está disponible y la cantidad de adultos e infantes no supere 4 personas
    if (disponible == true && adultos + infantes <= 4) {
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }
    return false;
}

double HabitacionJunior::getTarifaBase() {
    // 20% de incremento
    return Habitacion::getTarifaBase() * 1.20; 
}

string HabitacionJunior::toString() {
    // Tipo de Habitación
    return Habitacion::toString() + ",Habitacion Junior";
}