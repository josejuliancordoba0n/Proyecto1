
//
// Created by Ken on 30/8/2026.
//

#ifndef PROYECTO1_MENUPRINCIPAL_H
#define PROYECTO1_MENUPRINCIPAL_H
#include "ListaCanchas.h"
#include "ListaCliente.h"
#include "ListaRegistroEspera.h"
#include "ListaReservas.h" 

class MenuPrincipal {
private:
    ListaCanchas coleccionCanchas;
    ListaCliente coleccionClientes;
    ListaRegistroEspera coleccionEspera;
    ListaReservas coleccionReservas;

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

    //Metodos Propios (Reservas)
    void menuReservas();
    void registrarReserva();
    void mostrarReservas();
    void buscarReservaMenu();
    void mostrarReservasPorCanchaMenu();
    void cancelarReservaMenu();

    //Metodos Propios (Reportes)
    void menuReportes();
    void reporteClienteMasReservas();
    void reporteCanchaMasReservas();
    void reporteIngresoTotal();
    void reporteOcupacionPorcentaje();
    void reporteHorasMayorMenor();



    //Destructor
    ~MenuPrincipal();
};


#endif //PROYECTO1_MENUPRINCIPAL_H

