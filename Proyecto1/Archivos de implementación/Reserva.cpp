#include "../Archivos de Cabecera/Reserva.h"
#include <sstream>


Reserva::Reserva() {
    numeroReserva = 0;
    cliente = nullptr;
    cancha = nullptr;
    franjaInicial = 0;
    cantidadFranjas = 0;
    monto = 0.0f;
    estado = 'A';
}

Reserva::Reserva(int numeroReserva, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas, float monto) {
    this->numeroReserva = numeroReserva;
    this->cliente = cliente;
    this->cancha = cancha;
    this->franjaInicial = franjaInicial;
    this->cantidadFranjas = cantidadFranjas;
    this->monto = monto;
    this->estado = 'A';
}


string Reserva::toStringReserva() {
    stringstream ss;

    string estadoTexto = (estado == 'A') ? "Activa" : "Cancelada";
    string clienteNombre = (cliente != nullptr) ? cliente->getNombreCliente() : "N/A";
    int canchaId = (cancha != nullptr) ? cancha->getIdCancha() : -1;

    int horaInicio = 8 + franjaInicial;
    int horaFin = horaInicio + cantidadFranjas;

    ss << "=====================\n";
    ss << "DATOS DE LA RESERVA\n";
    ss << "=====================\n";
    ss << "Numero de reserva: [" << numeroReserva << "]" <<endl;
    ss << "Cliente: [" << clienteNombre << "]" <<endl;
    ss << "Cancha: [C-";

    if (canchaId != -1) {

        if (canchaId < 10) {
            ss << "0";
        }

        ss << canchaId;
    }
    else {
        ss << "??";
    }

    ss << "]" << endl;

    ss << "Horario reservado: [" << horaInicio << ":00 - " << horaFin << ":00]" <<endl;
    ss << "Monto: [CRC " << monto << "]" <<endl;
    ss << "Estado: [" << estadoTexto << "]" <<endl;

    return ss.str();
}


int Reserva::getNumeroReserva() { return numeroReserva; }
Cliente* Reserva::getCliente() { return cliente; }
Cancha* Reserva::getCancha() { return cancha; }
int Reserva::getFranjaInicial() { return franjaInicial; }
int Reserva::getCantidadFranjas() { return cantidadFranjas; }
float Reserva::getMonto() { return monto; }
char Reserva::getEstado() { return estado; }


void Reserva::setEstado(char nuevoEstado) {
    estado = nuevoEstado;
}
Reserva::~Reserva() {

}
