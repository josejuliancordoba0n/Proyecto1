//
// Persona 3 - Gestion de Reservas-Yani
//

#ifndef PROYECTO1_LISTARESERVAS_H
#define PROYECTO1_LISTARESERVAS_H
#include "Reserva.h"
#include <string>
using namespace std;

class ListaReservas {
    private:
    int cant;
    int tam;
    Reserva** arrayReserva; 
    int siguienteNumero;

    public:
   
    //Constructor
    ListaReservas();
    
    //Metodos Propios
    bool registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas);
    Reserva* buscarReserva(int numeroReserva);
    bool cancelarReserva(int numeroReserva);
    Reserva* getReserva(int posicion);
    int getCantidad();
    int contarReservasActivasPorCancha(int idCancha);
    int contarReservasActivasPorCliente(int idCliente);
    string mostrarReservasPorCliente(int idCliente);
    string mostrarReservasPorCancha(int idCancha);

    //To String   
    string toStringListaReservas();

   
    ~ListaReservas();
};

#endif 
