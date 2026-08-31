//
// Created by Ken on 30/8/2026.
//

#ifndef PROYECTO1_MENUPRINCIPAL_H
#define PROYECTO1_MENUPRINCIPAL_H
#include "ListaCanchas.h"

class MenuPrincipal {
    private:
    ListaCanchas coleccionCanchas;

    public:
    //Constructor
    MenuPrincipal();

    //Metodos Propios
    void iniciar();
    void menuCanchas();
    void registrarCancha();
    void mostrarCanchas();
    void buscarCancha();
    void modificarPrecio();
    void mantenimientoCancha();
    void reporteOcupacion();

    //Destructor
    ~MenuPrincipal();
};


#endif //PROYECTO1_MENUPRINCIPAL_H
