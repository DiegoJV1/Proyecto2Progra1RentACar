#pragma once
#include"NodoContratoAlquiler.h"
class ColeccionContratoAlquiler{
private:
	NodoContratoAlquiler* inicio;
	NodoContratoAlquiler* actual;
public:
	ColeccionContratoAlquiler();
	~ColeccionContratoAlquiler();
	void insertarContrato(ContratoAlquiler* aux);
	ContratoAlquiler* buscarContrato(string cod);
	bool esMayorFecha(Fecha* f1, Fecha* f2);
	bool esMenorFecha(Fecha* f1, Fecha* f2);
	void ordenarContratosMenorAMayor();

	ContratoAlquiler* getContratoCliente(string id);
	ContratoAlquiler* getContratoVehiculo(string placa);
	ContratoAlquiler* getContratoColaborador(string id);

	string ImprimirContratoCliente(string id);
	string ImprimirContratoVehiculo(string id);
	string ImprimirContratoColaborador(string id);
	void ubicarInicio();
	void ubicarSig();
	ContratoAlquiler* getObjActual();

	string toString();
};

