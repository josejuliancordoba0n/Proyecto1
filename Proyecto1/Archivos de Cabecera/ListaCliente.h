#ifndef PROYECTO1_LISTACLIENTE_H
#define PROYECTO1_LISTACLIENTE_H
#include "Cliente.h"
#include <string>
using namespace std;

class ListaCliente {
private:
    int cant;
    int tam;
    Cliente* arrayCliente[100];

public:
    ListaCliente();
    bool agregarCliente(Cliente* cPtr);
    Cliente* buscarCliente(int idCliente);
    Cliente* getCliente(int posicion);
    int getCantidad();
    string toStringListaClientes();
    ~ListaCliente();
};
#endif //PROYECTO1_LISTACLIENTE_H