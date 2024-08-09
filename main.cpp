
#include "Hotel.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"

#include <iostream>
using namespace std;

int main() {
    // Crear habitaciones Individuales
    HabitacionJunior hj(100);
    HabitacionSuite hs(101);
    HabitacionDeluxe hd(102);

    // Hacer check-in en las habitaciones individuales
    hj.checkin("Hugo", 2, 2, 100.0);
    hs.checkin("Paco", 4, 2, 200.0);
    hd.checkin("Luis", 4, 4, 300.0);


    // Probar la sobrecarga del operador +
    double tarifaBaseAcumulado = 0.0;
    double totalTarifaBase = tarifaBaseAcumulado + hj; // Deberia ser 
    std::cout << "Total Tarifa Base (solo hj): " << totalTarifaBase << std::endl; 

    tarifaBaseAcumulado = 0.0;
    totalTarifaBase = tarifaBaseAcumulado + hj + hs + hd; // Deberia ser 
    std::cout << "Total Tarifa Base (hj + hs + hd): " << totalTarifaBase << std::endl;

    // Crear Hotel RIU
    Hotel hotel("Hotel RIU",1, 1, 1);

    // Hacer Ckeck-in en las habitaciones del Hotel
    hotel[100]->checkin("Hugo", 2, 2, 100.0);
    hotel[101]->checkin("Paco", 4, 2, 200.0);
    hotel[102]->checkin("Luis", 4, 4, 300.0);
    
    // Probar la sobrecarga del operador []
    cout<<'\n';
    cout << hotel[100]->toString() << '\n';
    cout << hotel[101]->toString() << '\n';
    cout << hotel[102]->toString() << '\n';

    cout<<'\n';

    // Probar la sobrecarga del operador <<
    cout << hotel << endl;



    //----------------------------------------------------------//
    /* string nombreHotel;
    cout<<"Ingresa el nombre del hotel: ";
    getline(cin, nombreHotel);

    int numJunior, numSuite, numDeluxe;
    cout<<"Ingresa el numero de habitaciones Junior (max 4 Personas): ";
    cin>>numJunior;
    cout<<"Ingresa el numero de habitaciones Suite (max 6 Personas): ";
    cin>>numSuite;
    cout<<"Ingresa el numero de habitaciones Deluxe (max 8 Personas): ";
    cin>>numDeluxe;

    Hotel hotel(nombreHotel, numJunior, numSuite, numDeluxe);

    int opcion;
    do {
        cout<<'\n';
        cout<<"Ingresa el numero de la opcion deseada: "
            <<"\n1) Hacer check-in"
            <<"\n2) Hacer check-out"
            <<"\n3) Realizar cargos a habitacion"
            <<"\n4) Ingresos por tarifas"
            <<"\n5) Generar reporte de ocupacion"
            <<"\n6) Salir"
            <<"\nOpcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int adultos, infantes, tipoHabitacion;
                double credito;

                cout<<'\n';
                cout<<"Ingresa el nombre del huesped: ";
                cin>>nombre;
                cout<<"Ingresa el numero de adultos: ";
                cin>>adultos;
                cout<<"Ingresa el numero de infantes: ";
                cin>>infantes;
                cout<<"Ingresa el credito: ";
                cin>>credito;

                cout<<'\n';
                cout<<"Ingresa el tipo de habitacion: \n1) Junior\n2) Suite\n3) Deluxe\nOpcion: ";
                cin>>tipoHabitacion;

                int habitacionAsignada = hotel.checkin(nombre, adultos, infantes, credito, tipoHabitacion);
                if (habitacionAsignada != -1) {
                    cout<<"Check-in exitoso. Habitacion asignada: "<<habitacionAsignada<<'\n';
                } else {
                    cout<<"Check-in fallido. Supera el limite de personas, elija otra opcion.\n";
                }
                break;
            }
            case 2: {
                int numHabitacion;
                cout<<'\n';
                cout<<"Ingresa el numero de habitacion: ";
                cin>>numHabitacion;

                if (hotel.checkout(numHabitacion)) {
                    cout<<"Check-out exitoso.\n";
                } else {
                    cout<<"Check-out fallido. La habitacion no esta ocupada.\n";
                }
                break;
            }
            case 3: {
                int numHabitacion;
                double cargo;
                cout<<'\n';
                cout<<"Ingresa el numero de habitacion: ";
                cin>>numHabitacion;
                cout<<"Ingresa el cargo: ";
                cin>>cargo;

                if (hotel.realizarCargosHabitacion(numHabitacion, cargo)) {
                    cout<<"Cargo realizado exitosamente.\n";
                } else {
                    cout<<"Cargo fallido. La habitacion no esta ocupada.\n";
                }
                break;
            }
            case 4: {
                double Tarifa = hotel.getTotalXTarifaBase();
                cout<<"Ingresos totales por tarifas: $"<<Tarifa<<'\n';
                break;
            }
            case 5: {
                hotel.imprimeOcupacion();
                break;
            }
            case 6: {
                cout<<"Saliendo del programa...\n";
                break;
            }
            default: {
                cout<<"Opcion invalida. Intenta de nuevo. :)\n";
                break;
            }
        }
    } while (opcion != 6); */

    /* hotel.checkin("Diana", 3, 1, 6000.0, 1);
    hotel.checkin("Edward",2, 2, 3500.0, 2);
    hotel.checkin("Fiona", 1, 2, 4500.0, 3); */


    return 0;
}