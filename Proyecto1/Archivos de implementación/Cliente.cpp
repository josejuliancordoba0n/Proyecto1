#include "../Archivos de Cabecera/Cliente.h"
#include <sstream>

Cliente::Cliente() {
    idCliente = 0;
    nombreCliente = "INDEFINIDO";
    numTel = "00000";
}

Cliente::Cliente(int idCliente, string nombreCliente, string numTel) {
    this->idCliente = idCliente;
    this->nombreCliente = nombreCliente;
    this->numTel = numTel;
}

string Cliente::toStringCliente() {
    stringstream ss;
    ss << "=====================\n";
    ss << "DATOS DEL CLIENTE\n";
    ss << "=====================\n";
    ss << "ID del cliente: " << idCliente <<endl
        << "Nombre del cliente: " << nombreCliente <<endl
        << "Numero de telefono: " << numTel <<endl;
    return ss.str();
}

Cliente::~Cliente() {
}