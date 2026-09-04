#include "../Archivos de Cabecera/ListaRegistroEspera.h"
#include <sstream>

//Constructor
ListaRegistroEspera::ListaRegistroEspera() {
    tam = 10;
    cant = 0;
    idEspera = 0;
    for (int i = 0; i < tam; i++) {
        arrayEspera[i] = nullptr;
    }
}

//Metodos propios
bool ListaRegistroEspera::AgregarRegistroEspera(RegistroEspera* ePtr) {
    if (cant >= tam) {
        return false; // ya hay 10 clientes en espera (limite del enunciado)
    }

    // Regla: un mismo cliente no puede estar dos veces "esperando"
    // por la misma cancha y la misma franja horaria
    for (int i = 0; i < cant; i++) {
        if (arrayEspera[i]->getEstadoAtencion() == 'E' &&
            arrayEspera[i]->getCancha()->getIdCancha() == ePtr->getCancha()->getIdCancha() &&
            arrayEspera[i]->getPosicionFranja() == ePtr->getPosicionFranja() &&
            arrayEspera[i]->getCliente()->getIdCliente() == ePtr->getCliente()->getIdCliente()) {
            return false;
        }
    }

    idEspera++;
    ePtr->setIdSolicitudEspera(idEspera); // numero consecutivo generado por el sistema
    arrayEspera[cant++] = ePtr;
    return true;
}

RegistroEspera* ListaRegistroEspera::buscarEsperaPorCanchaFranja(int idCancha, int posicionFranja) {
    for (int i = 0; i < cant; i++) {
        // solo interesa a quien sigue "esperando" (E), no a asignados/cancelados
        if (arrayEspera[i]->getEstadoAtencion() == 'E' &&
            arrayEspera[i]->getCancha()->getIdCancha() == idCancha &&
            arrayEspera[i]->getPosicionFranja() == posicionFranja) {
            return arrayEspera[i];
        }
    }
    return nullptr;
}

RegistroEspera* ListaRegistroEspera::buscarEspera(int idEspera) {
    for (int i = 0; i < cant; i++) {
        if (arrayEspera[i]->getIdSolicitudEspera() == idEspera) {
            return arrayEspera[i];
        }
    }
    return nullptr;
}

bool ListaRegistroEspera::cambiarEstadoSolicitud(int idEspera, char nuevoEstado) {
    if (nuevoEstado != 'E' && nuevoEstado != 'A' && nuevoEstado != 'C') {
        return false;
    }

    RegistroEspera* registro = buscarEspera(idEspera);
    if (registro == nullptr) {
        return false;
    }

    registro->setEstadoAtencion(nuevoEstado);
    return true;
}

//To String
string ListaRegistroEspera::toStringListaEspera() {
    stringstream ss;
    ss << "============= LISTADO DE ESPERA =============" << endl;

    if (cant == 0) {
        ss << "No hay clientes en el listado de espera." << endl;
    }

    for (int i = 0; i < cant; i++) {
        ss << arrayEspera[i]->toStringRegistroEspera(arrayEspera[i]->getIdSolicitudEspera()) << endl;
    }
    return ss.str();
}

//Destructor
ListaRegistroEspera::~ListaRegistroEspera() {
    for (int i = 0; i < cant; i++) {
        delete arrayEspera[i];
        arrayEspera[i] = nullptr;
    }
}