

#ifndef PROYECTO1_REGISTROESPERA_H
#define PROYECTO1_REGISTROESPERA_H
#include <string>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

class RegistroEspera {
private:
    Cliente* cliente;
    Cancha* cancha;
    int posicionFranja;
    int idSolicitudEspera;
    char estadoAtencion;

public:
    //Constructores
    RegistroEspera();
    RegistroEspera(int idSolicitudEspera, char estadoAtencion, Cliente* cliente, Cancha* cancha, int posicionFranja);

    //Get (necesarios para ListaRegistroEspera: buscar por cancha/franja, mostrar, cambiar estado)
    int getIdSolicitudEspera();
    char getEstadoAtencion();
    Cliente* getCliente();
    Cancha* getCancha();
    int getPosicionFranja();

    //Set (necesario para cambiar estado: esperando -> asignado / cancelado)
    void setEstadoAtencion(char nuevoEstado);
    void setIdSolicitudEspera(int id);

    //To String
    string toStringRegistroEspera(int idSolicitudEspera);

    //Destructor
    ~RegistroEspera();
};

#endif 