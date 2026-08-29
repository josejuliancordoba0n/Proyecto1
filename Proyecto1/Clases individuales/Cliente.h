//
// Created by Ken on 28/8/2026.
//
#ifndef PROYECTO1_CLIENTE_H
#define PROYECTO1_CLIENTE_H
#include <iostream>
#include <sstream>
using namespace std;



class Cliente {
    private:
    int idCliente;
    string nombreCliente;
    int numeroCliente;

    public:
    Cliente();
    Cliente(string nombreCliente, int numeroCliente);
    string getNombreCliente();
    int getIdCliente();
    int getNumeroCliente();
    void setNombreCliente(string nombreCliente);
    void setNumeroCliente(int numeroCliente);
    void setIdCliente(int idCliente);


    ~Cliente();
};



#endif //PROYECTO1_CLIENTE_H
