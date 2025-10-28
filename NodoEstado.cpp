#include "NodoEstado.h"
#include<sstream>
NodoEstado::NodoEstado() : obj(""), sig(nullptr), fechaCambio(nullptr), c(nullptr) {}
NodoEstado::NodoEstado(string aux, Colaborador* c, Fecha* fecha) :obj(aux), sig(nullptr), fechaCambio(fecha), c(c) {}
NodoEstado::~NodoEstado() {
	sig = nullptr;
	c = nullptr;
	delete fechaCambio;
}
void NodoEstado::setObj(string aux) { this->obj = aux; }
void NodoEstado::setSig(NodoEstado* aux) { this->sig = aux; }
void NodoEstado::setC(Colaborador* c) { this->c = c; }
void NodoEstado::setFechaCambio(Fecha* f) { this->fechaCambio = f; }
Colaborador* NodoEstado::getC() { return c; }
Fecha* NodoEstado::getFechaCambio() { return fechaCambio; }
string NodoEstado::getObj() { return obj; }
NodoEstado* NodoEstado::getSig() { return sig; }
string NodoEstado::toString() {
	stringstream ss;
	ss << "Estado: " << obj << endl;
	if (fechaCambio && c) {
		ss << "Fecha de Registro: " << fechaCambio << endl;
		ss << "Encargado: " << c->toString() << endl;
	}
	else {
		ss << "Fecha de Registro: nulo" << endl;
		ss << "Encargado: nulo" << endl;
	}
	return ss.str();
}

