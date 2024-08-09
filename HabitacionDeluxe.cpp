#include "HabitacionDeluxe.h"

HabitacionDeluxe::HabitacionDeluxe() : Habitacion() {}

HabitacionDeluxe::HabitacionDeluxe(int numero) : Habitacion(numero) {}

bool HabitacionDeluxe::checkin(string nombre, int adultos, int infantes, double credito) {
    // Si la habitación está disponible y la cantidad de adultos e infantes no supere 8 personas
    if (disponible == true && adultos + infantes <= 8) {
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }
    return false;
}

double HabitacionDeluxe::getTarifaBase() {
    // 50% de incremento
    return Habitacion::getTarifaBase() * 1.50; 
}

string HabitacionDeluxe::toString() {
    // Tipo de Habitación
    return Habitacion::toString() + ",Habitacion Deluxe";
}