#include<sstream>
class ListaCliente {
private:
	int cant;
	int tam;
	Cliente* arrayCliente[100];

public:
	//Constructor
	ListaCliente(int tam=100);
	//Metodos Propios
	bool agregarCliente(Cliente* aPtr);
	bool buscarCliente(int idCliente);
		Cliente* getCliente(int posicion);
	int getCantidad();
	//To String
	string toStringListaClientes();
	//Destructor
	~ListaCliente();

};