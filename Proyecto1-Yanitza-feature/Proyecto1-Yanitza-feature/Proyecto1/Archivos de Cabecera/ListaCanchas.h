//
// Created by Ken on 30/8/2026.
//

#ifndef PROYECTO1_LISTACANCHAS_H
#define PROYECTO1_LISTACANCHAS_H
#include "Cancha.h"


class ListaCanchas {
    private:
    int cant;
    int tam;
    Cancha* arrayCancha[10];

    public:
    //Constructor
    ListaCanchas();

    //Metodos Propios
    bool agregarCancha(Cancha* aPtr);
    Cancha* buscarCancha(int idCancha);
    bool modificarPrecio(int idCancha, float nuevoPrecio);

    //Get Cantidad (Para Reportes)
    Cancha* getCancha(int posicion);
    int getCantidad();

    //To String
    string toStringListaCanchas();

    //Destructor
    ~ListaCanchas();



};


#endif //PROYECTO1_LISTACANCHAS_H
