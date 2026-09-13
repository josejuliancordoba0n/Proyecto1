//
// Persona 3 - Gestion de Reservas-Yani
//

#ifndef PROYECTO1_RESERVA_H
#define PROYECTO1_RESERVA_H
#include <string>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

class Reserva {
    private:
    int numeroReserva;
    Cliente* cliente;
    Cancha* cancha;
    int franjaInicial;
    int cantidadFranjas;
    float monto;
    char estado; 

    public:
    
    Reserva();
    Reserva(int numeroReserva, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas, float monto);

   
    string toStringReserva();

   
    int getNumeroReserva();
    Cliente* getCliente();
    Cancha* getCancha();
    int getFranjaInicial();
    int getCantidadFranjas();
    float getMonto();
    char getEstado();

    
    void setEstado(char nuevoEstado);

    
    ~Reserva();
};

#endif 
