# include "HabitacionSuite.h"

HabitacionSuite::HabitacionSuite() : Habitacion() {}

HabitacionSuite::HabitacionSuite(int numero) : Habitacion(numero) {}

bool HabitacionSuite::checkin(string nombre, int adultos, int infantes, double credito) {
    // Si la habitación está disponible y la cantidad de adultos e infantes no supere 6 personas
    if (disponible == true && adultos + infantes <= 6) {
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }
    return false;
}

double HabitacionSuite::getTarifaBase() {
    // 30% de incremento
    return Habitacion::getTarifaBase() * 1.30;
}

string HabitacionSuite::toString() {
    // Tipo de Habitación
    return Habitacion::toString() + ",Habitacion Suite";
}