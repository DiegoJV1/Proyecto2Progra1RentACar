#pragma once
#include"ContratoAlquiler.h"
class NodoContratoAlquiler{
private:
	ContratoAlquiler* obj;
	NodoContratoAlquiler* sig;
public:
	NodoContratoAlquiler();
	NodoContratoAlquiler(ContratoAlquiler* aux);
	~NodoContratoAlquiler();
	void setObj(ContratoAlquiler* aux);
	void setSig(NodoContratoAlquiler* aux);
	ContratoAlquiler* getObj();
	NodoContratoAlquiler* getSig();
};

