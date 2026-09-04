//
// Created by Ken on 30/8/2026.
//

#include "../Archivos de Cabecera/Cancha.h"
#include <sstream>

//Constructores

Cancha::Cancha() {
    idCancha = 0;
    tipoDeporte = "INDEFINIDO";
    precioHora = 0.0;

    for(int i = 0; i < 12; i++) {
        dispHora[i] = 'L';
    }
}

Cancha::Cancha(int idCancha,string tipoDeporte,float precioHora,char dispHora[]) {
    this->idCancha = idCancha;
    this->tipoDeporte = tipoDeporte;
    this->precioHora = precioHora;

    for(int i = 0; i < 12; i++) {
        this->dispHora[i] = dispHora[i];
    }
}

//Metodos Propios

char Cancha::consultarFranja(int posicion) {
    if(posicion < 0 || posicion >= 12) {
        return '?';
    }
    return dispHora[posicion];
}


bool Cancha::cambiarEstadoFranja(int posicion, char estado) {
    if(posicion < 0 || posicion >= 12) {
        return false;
    }

    if(estado != 'L' && estado != 'O' && estado != 'M') {
        return false;
    }

    if(estado == 'M' && dispHora[posicion] == 'O') {
        return false;
    }

    dispHora[posicion] = estado;
    return true;
}

// Get

char Cancha::getdispHora(int posicion) {
    if(posicion >= 0 && posicion < 12) {
        return dispHora[posicion];
    }
    return '?';
    }

int Cancha::getIdCancha() {
    return this -> idCancha;
}

string Cancha::getTipoDeporte() {
    return tipoDeporte;
}

float Cancha::getPrecioHora() {
    return precioHora;
}

//Set

void Cancha::setIdCancha(int id) {
     this -> idCancha = id;
}

void Cancha::setTipoDeporte(string tipoDeporte) {
    this->tipoDeporte = tipoDeporte;
    }

void Cancha::setPrecioHora(float precioHora) {
    if(precioHora > 0)
        this->precioHora = precioHora;
}

string Cancha::toStringCancha() {
    stringstream ss;

    ss << "=====================\n";
    ss << "DATOS DE LA CANCHA\n";
    ss << "=====================\n" <<endl;

    ss << "Codigo de cancha: [" << idCancha
        << "]\nTipo de deporte para el cual se usa: ["
        << tipoDeporte
        << "]\nPrecio de alquiler por hora: [CRC "
        << precioHora
        << "]\nDisponibilidad de cancha segun las horas:\n"
        << "(O -> Ocupado, L -> Libre, M -> En Mantenimiento)"
        <<endl;

    for (int i = 0; i < 12; i++) {
        int horaInicio = 8 + i;
        int horaFin = 9 + i;

        ss << "["
            << horaInicio
            << ":00 - "
            << horaFin
            << ":00] --> "
            << dispHora[i]
            <<endl;
    }

    return ss.str();
}


Cancha::~Cancha() {

}