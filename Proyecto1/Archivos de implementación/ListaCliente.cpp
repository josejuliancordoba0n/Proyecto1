#include "ListaCliente.h"
#include <string>
using namespace std;
ListaCliente::ListaCliente(int tam=100) {
	cant = 0;
	tam = 100;
	this->tam = tam;
	for (int i = 0; i < tam; i++) {
		arrayCliente[i] = nullptr;
	}
}
bool ListaCliente::agregarCliente(Cliente* nuevoCliente) {
	if (cant >= tam) {
		return false;
	}
	
	arrayCliente[cant++] = nuevoCliente;
	cantidad++;
	return true;
}

bool ListaCliente::buscarCliente(int idCliente) {
	for (int i = 0; i < cant; i++) {
		if (idCliente == arrayCliente[i]->getidCliente()) {
			return true;
		}
	}
	return false;
}
int ListaCliente::getCantidad() {
	return cant;
}

string ListaCliente::toStringListaClientes() {
	stringstream ss;
	
	
	for (int i = 0; i < cant; i++) {
		ss << arrayCliente[i]->toStringCliente() << endl;
	}
	return ss.str();
}
ListaCliente::~ListaCliente() {

}


