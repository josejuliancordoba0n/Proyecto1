//
// Created by Ken on 30/8/2026.
//

#include "../Archivos de Cabecera/ListaCanchas.h"
#include <sstream>

//Constructor

ListaCanchas::ListaCanchas() {
    cant = 0;
    tam = 10;
    for (int i = 0; i < tam; i++) {
        arrayCancha[i] = nullptr;
    }

}

//Metodos propios

bool ListaCanchas::agregarCancha(Cancha* aPtr) {
    if(cant >= tam) {
        return false;
    }

    if(buscarCancha(aPtr->getIdCancha()) != nullptr) {
        return false;
    }

    arrayCancha[cant++] = aPtr;
    return true;
}

Cancha* ListaCanchas::buscarCancha(int idCancha) {
    for (int i = 0; i < cant; i++) {
        if (idCancha == arrayCancha[i]->getIdCancha()) {
            return arrayCancha[i] ;
        }
    }
     return nullptr;
}

bool ListaCanchas::modificarPrecio(int idCancha, float nuevoPrecio) {
    Cancha* cancha = buscarCancha(idCancha);
    if(cancha == nullptr) {
        return false;
    }

    if(nuevoPrecio <= 0) {
        return false;
    }

    cancha->setPrecioHora(nuevoPrecio);
    return true;
}


//Get

int ListaCanchas::getCantidad() {
    return cant;
}

Cancha* ListaCanchas::getCancha(int posicion) {
    if(posicion >= 0 && posicion < cant) {
        return arrayCancha[posicion];
    }
    return nullptr;
}


//To String

string ListaCanchas::toStringListaCanchas() {
    stringstream ss;

    ss << "============= LISTADO DE CANCHAS =============" << endl;

    for (int i = 0; i < cant; i++) {
        if(arrayCancha[i] != nullptr)
            ss << arrayCancha[i]->toStringCancha() << endl;
    }
    return ss.str();
}

//Destructor

ListaCanchas::~ListaCanchas() {
    for (int i = 0; i < cant; i++) {
        delete arrayCancha[i];
        arrayCancha[i] = nullptr;
    }
};
