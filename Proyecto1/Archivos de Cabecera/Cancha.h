//
// Created by Ken on 30/8/2026.
//

#ifndef PROYECTO1_CANCHA_H
#define PROYECTO1_CANCHA_H
#include <iostream>
#include <string>
using namespace std;

class Cancha {
    private:
    int idCancha;
    string tipoDeporte;
    char dispHora[12];
    float precioHora;

    public:
    //Constructores
    Cancha();
    Cancha(int idCancha, string tipoDeporte, float precioHora, char dispHora[]);

    //Metodos propios
    char consultarFranja(int posicion);
    bool cambiarEstadoFranja(int posicion, char estado);

    //Get
    char getdispHora(int posicion);
    int getIdCancha();
    string getTipoDeporte();
    float getPrecioHora();


    //Set
    void setIdCancha(int id);
    void setTipoDeporte(string tipoDeporte);
    void setPrecioHora(float precioHora);

    //To String
    string toStringCancha();

    //Destructor
    ~Cancha();
};


#endif //PROYECTO1_CANCHA_H
