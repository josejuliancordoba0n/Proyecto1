#ifndef PROYECTO1_LISTAREGISTROESPERA_H
#define PROYECTO1_LISTAREGISTROESPERA_H
#include "RegistroEspera.h"
#include <string>
using namespace std;

class ListaRegistroEspera {
private:
    int tam;
    int cant;
    RegistroEspera* arrayEspera[10];
    int idEspera;

public:
    //Constructor
    ListaRegistroEspera();

    //Metodos propios
    bool AgregarRegistroEspera(RegistroEspera* ePtr);
    RegistroEspera* buscarEsperaPorCanchaFranja(int idCancha, int posicionFranja);
    RegistroEspera* buscarEspera(int idEspera);
    bool cambiarEstadoSolicitud(int idEspera, char nuevoEstado);

    //To String
    string toStringListaEspera();

    //Destructor
    ~ListaRegistroEspera();
};

#endif //PROYECTO1_LISTAREGISTROESPERA_H