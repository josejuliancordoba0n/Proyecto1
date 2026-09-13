#include "../Archivos de Cabecera/ListaReservas.h"
#include <sstream>


ListaReservas::ListaReservas() {
    tam = 120;
    cant = 0;
    siguienteNumero = 1;
    arrayReserva = new Reserva*[tam]; 
    for (int i = 0; i < tam; i++) {
        arrayReserva[i] = nullptr;
    }
}


bool ListaReservas::registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas) {
    if (cliente == nullptr || cancha == nullptr) return false;
    if (cant >= tam) return false;
    if (franjaInicial < 0 || cantidadFranjas < 1 || (franjaInicial + cantidadFranjas) > 12) return false;

   
    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        if (cancha->consultarFranja(i) != 'L') {
            return false; 
        }
    }

    float monto = cancha->getPrecioHora() * cantidadFranjas;
    Reserva* nueva = new Reserva(siguienteNumero, cliente, cancha, franjaInicial, cantidadFranjas, monto);

   
    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        cancha->cambiarEstadoFranja(i, 'O');
    }

    arrayReserva[cant] = nueva;
    cant++;
    siguienteNumero++;
    return true;
}

Reserva* ListaReservas::buscarReserva(int numeroReserva) {
    for (int i = 0; i < cant; i++) {
        if (arrayReserva[i]->getNumeroReserva() == numeroReserva) {
            return arrayReserva[i];
        }
    }
    return nullptr;
}

bool ListaReservas::cancelarReserva(int numeroReserva) {
    Reserva* r = buscarReserva(numeroReserva);
    if (r == nullptr || r->getEstado() != 'A') return false;

    r->setEstado('C');
    Cancha* c = r->getCancha();
    int inicio = r->getFranjaInicial();
    int cantidad = r->getCantidadFranjas();
    for (int i = inicio; i < inicio + cantidad; i++) {
        c->cambiarEstadoFranja(i, 'L');
    }
    return true;
}


Reserva* ListaReservas::getReserva(int posicion) {
    if (posicion < 0 || posicion >= cant) return nullptr;
    return arrayReserva[posicion];
}

int ListaReservas::getCantidad() {
    return cant;
}


int ListaReservas::contarReservasActivasPorCancha(int idCancha) {
    int contador = 0;
    for (int i = 0; i < cant; i++) {
        if (arrayReserva[i]->getEstado() == 'A' && arrayReserva[i]->getCancha()->getIdCancha() == idCancha) {
            contador++;
        }
    }
    return contador;
}

int ListaReservas::contarReservasActivasPorCliente(int idCliente) {
    int contador = 0;
    for (int i = 0; i < cant; i++) {
        if (arrayReserva[i]->getEstado() == 'A' && arrayReserva[i]->getCliente()->getIdCliente() == idCliente) {
            contador++;
        }
    }
    return contador;
}

string ListaReservas::mostrarReservasPorCliente(int idCliente) {
    string resultado = "";
    bool encontrada = false;
    for (int i = 0; i < cant; i++) {
        if (arrayReserva[i]->getCliente()->getIdCliente() == idCliente) {
            resultado += arrayReserva[i]->toStringReserva() + "\n";
            encontrada = true;
        }
    }
    if (!encontrada) {
        resultado = "Este cliente no tiene reservas registradas.\n";
    }
    return resultado;
}

string ListaReservas::mostrarReservasPorCancha(int idCancha) {
    string resultado = "";
    bool encontrada = false;
    for (int i = 0; i < cant; i++) {
        if (arrayReserva[i]->getCancha()->getIdCancha() == idCancha) {
            resultado += arrayReserva[i]->toStringReserva() + "\n";
            encontrada = true;
        }
    }
    if (!encontrada) {
        resultado = "Esta cancha no tiene reservas registradas.\n";
    }
    return resultado;
}


string ListaReservas::toStringListaReservas() {
    string resultado = "";
    for (int i = 0; i < cant; i++) {
        resultado += arrayReserva[i]->toStringReserva() + "\n";
    }
    return resultado;
}


ListaReservas::~ListaReservas() {
    for (int i = 0; i < cant; i++) {
        delete arrayReserva[i];
    }
    delete[] arrayReserva;
}
