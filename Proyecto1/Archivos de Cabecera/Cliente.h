#include <string>
using namespace std;

class Cliente {
private: 
	int idCliente; 
	string nombreCliente; 
	string numTel;
public: 
	//Constructores
	Cliente();
	Cliente(int, string, string);
	string toStringCliente();
	int getidCliente() { return idCliente; }
	string  getnombreCliente() { return nombreCliente; }
	string numTelCliente() { return numTel; }
	void setidCliente(int id) { idCliente = id; }
	void setnombreCliente(string nombre) { nombreCliente = nombre; }
	void numTelCliente(string numTel) { numTel = numTel; }
	~Cliente();
};