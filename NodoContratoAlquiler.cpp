#include "NodoContratoAlquiler.h"
NodoContratoAlquiler::NodoContratoAlquiler() : obj(nullptr), sig(nullptr) {}
NodoContratoAlquiler::NodoContratoAlquiler(ContratoAlquiler* aux) :obj(aux), sig(nullptr) {}
NodoContratoAlquiler::~NodoContratoAlquiler() {
	delete obj;
	obj = nullptr;
	sig = nullptr;
}
void NodoContratoAlquiler::setObj(ContratoAlquiler* aux) { this->obj = aux; }
void NodoContratoAlquiler::setSig(NodoContratoAlquiler* aux) { this->sig = aux; }
ContratoAlquiler* NodoContratoAlquiler::getObj() { return obj; }
NodoContratoAlquiler* NodoContratoAlquiler::getSig() { return sig; }
