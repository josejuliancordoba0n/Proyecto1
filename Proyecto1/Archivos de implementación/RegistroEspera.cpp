#include "RegistroEspera.h"
#include <sstream>

//Constructores
RegistroEspera::RegistroEspera() {
    idSolicitudEspera = 0;
    estadoAtencion = 'E';
    cliente = nullptr;
    cancha = nullptr;
    posicionFranja = -1;
}

RegistroEspera::RegistroEspera(int idSolicitudEspera, char estadoAtencion, Cliente* cliente, Cancha* cancha, int posicionFranja) {
    this->idSolicitudEspera = idSolicitudEspera;
    this->estadoAtencion = estadoAtencion;
    this->cliente = cliente;
    this->cancha = cancha;
    this->posicionFranja = posicionFranja;
}

//Metodo propio
string RegistroEspera::toStringRegistroEspera(int idSolicitudEspera) {
    stringstream ss;

    string estadoTexto;
    if (estadoAtencion == 'E') estadoTexto = "Esperando";
    else if (estadoAtencion == 'A') estadoTexto = "Asignado";
    else if (estadoAtencion == 'C') estadoTexto = "Cancelado";
    else estadoTexto = "Desconocido";

    int horaInicio = 8 + posicionFranja;
    int horaFin = 9 + posicionFranja;

    ss << "=====================\n";
    ss << "REGISTRO DE ESPERA\n";
    ss << "=====================\n";
    ss << "Numero de solicitud: [" << this->idSolicitudEspera << "]" << endl;
    ss << "Cliente: [" << (cliente != nullptr ? cliente->getNombreCliente() : "N/A") << "]" << endl;
    ss << "Cancha: [" << (cancha != nullptr ? cancha->getIdCancha() : -1) << "]" << endl;
    ss << "Franja solicitada: [" << horaInicio << ":00 - " << horaFin << ":00]" << endl;
    ss << "Estado: [" << estadoTexto << "]" << endl;

    return ss.str();
}

//Get
int RegistroEspera::getIdSolicitudEspera() {
    return idSolicitudEspera;
}

char RegistroEspera::getEstadoAtencion() {
    return estadoAtencion;
}

Cliente* RegistroEspera::getCliente() {
    return cliente;
}

Cancha* RegistroEspera::getCancha() {
    return cancha;
}

int RegistroEspera::getPosicionFranja() {
    return posicionFranja;
}

//Set
void RegistroEspera::setEstadoAtencion(char nuevoEstado) {
    if (nuevoEstado == 'E' || nuevoEstado == 'A' || nuevoEstado == 'C') {
        estadoAtencion = nuevoEstado;
    }
}
void RegistroEspera::setIdSolicitudEspera(int id) {
    idSolicitudEspera = id;
}

//Destructor
RegistroEspera::~RegistroEspera() {
    
}