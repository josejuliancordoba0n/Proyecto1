#include "../Archivos de Cabecera/ListaCliente.h"
#include <sstream>

ListaCliente::ListaCliente() {
    cant = 0;
    tam = 100;
    for (int i = 0; i < tam; i++) {
        arrayCliente[i] = nullptr;
    }
}

bool ListaCliente::agregarCliente(Cliente* nuevoCliente) {
    if (cant >= tam) {
        return false;
    }
    if (buscarCliente(nuevoCliente->getIdCliente()) != nullptr) {
        return false;
    }
    arrayCliente[cant++] = nuevoCliente;
    return true;
}

Cliente* ListaCliente::buscarCliente(int idCliente) {
    for (int i = 0; i < cant; i++) {
        if (idCliente == arrayCliente[i]->getIdCliente()) {
            return arrayCliente[i];
        }
    }
    return nullptr;
}

Cliente* ListaCliente::getCliente(int posicion) {
    if (posicion >= 0 && posicion < cant) {
        return arrayCliente[posicion];
    }
    return nullptr;
}

int ListaCliente::getCantidad() {
    return cant;
}

string ListaCliente::toStringListaClientes() {
    stringstream ss;
    ss << "============= LISTADO DE CLIENTES =============" <<endl;
    for (int i = 0; i < cant; i++) {
        ss << arrayCliente[i]->toStringCliente() <<endl;
    }
    return ss.str();
}

ListaCliente::~ListaCliente() {
    for (int i = 0; i < cant; i++) {
        delete arrayCliente[i];
        arrayCliente[i] = nullptr;
    }
}