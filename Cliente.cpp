#include "Cliente.h"
#include<sstream>
Cliente::Cliente() : id(""), nombre(""), residencia(""), contador(0) {

}
Cliente::~Cliente() {

}
Cliente::Cliente(string id, string nom, string resi) : id(id), nombre(nom), residencia(resi), contador(0) {

}
void Cliente::setId(string id) { this->id = id; }
void Cliente::setNombre(string nom) { this->nombre = nom; }
void Cliente::setResidencia(string resi) { this->residencia = resi; }
void Cliente::aumentaContador() { contador++; }
string Cliente::getId() { return id; }
string Cliente::getNombre() { return nombre; }
string Cliente::getResidencia() { return residencia; }
int Cliente::getCantidadDeSolicitudes() { return contador; }
void Cliente::reiniciarContador() {
	this->contador = 0; 
}
string Cliente::toString() {
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Id: " << id << endl;
	ss << "Lugar de Residencia: " << residencia << endl;
	return ss.str();
}
