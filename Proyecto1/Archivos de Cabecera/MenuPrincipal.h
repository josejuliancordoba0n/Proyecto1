
//
// Created by Ken on 30/8/2026.
//

#ifndef PROYECTO1_MENUPRINCIPAL_H
#define PROYECTO1_MENUPRINCIPAL_H
#include "ListaCanchas.h"
#include "ListaCliente.h"
#include "ListaRegistroEspera.h"

class MenuPrincipal {
private:
    ListaCanchas coleccionCanchas;
    ListaCliente coleccionClientes;
    ListaRegistroEspera coleccionEspera;

public:
    //Constructor
    MenuPrincipal();

    //Metodos Propios (Canchas)
    void iniciar();
    void menuCanchas();
    void registrarCancha();
    void mostrarCanchas();
    void buscarCancha();
    void modificarPrecio();
    void mantenimientoCancha();
    void reporteOcupacion();

    //Metodos Propios (Clientes)
    void menuClientes();
    void registrarCliente();
    void mostrarClientes();
    void buscarCliente();
    void mostrarReservasCliente();

    //Metodos Propios (Listado de espera)
    void menuEspera();
    void registrarEnEspera();
    void mostrarListadoEspera();
    void cambiarEstadoEspera();

    //Destructor
    ~MenuPrincipal();
};


#endif //PROYECTO1_MENUPRINCIPAL_H

