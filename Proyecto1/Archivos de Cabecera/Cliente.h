#ifndef PROYECTO1_CLIENTE_H
#define PROYECTO1_CLIENTE_H
#include <string>
using namespace std;

class Cliente {
private:
    int idCliente;
    string nombreCliente;
    string numTel;
public:
    Cliente();
    Cliente(int idCliente, string nombreCliente, string numTel);
    string toStringCliente();

    int getIdCliente() { return idCliente; }
    string getNombreCliente() { return nombreCliente; }
    string getNumTel() { return numTel; }

    void setIdCliente(int id) { idCliente = id; }
    void setNombreCliente(string nombre) { nombreCliente = nombre; }
    void setNumTel(string numTelNuevo) { numTel = numTelNuevo; }

    ~Cliente();
};


#endif //PROYECTO1_CLIENTE_H