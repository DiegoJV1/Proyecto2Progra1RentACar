#pragma once
#include"NodoSolicitudAlquiler.h"
#include"ContratoAlquiler.h"
class ColeccionSolicitudAlquiler {
private:
	NodoSolicitudAlquiler* inicio;
	NodoSolicitudAlquiler* actual;
public:
	ColeccionSolicitudAlquiler();
	~ColeccionSolicitudAlquiler();
	void insertarSolicitud(SolicitudAlquiler* aux);
	SolicitudAlquiler* buscarSolicitud(string cod);
	bool esMayorFecha(Fecha* f1, Fecha* f2);
	bool esMenorFecha(Fecha* f1, Fecha* f2);
	void ordenarSolicitudesMenorAMayor();

	SolicitudAlquiler* getSolicitudCliente(string id);
	SolicitudAlquiler* getSolicitudVehiculo(string placa);
	SolicitudAlquiler* getSolicitudColaborador(string id);

	string ImprimirSolicitudCliente(string id);
	string ImprimirSolicitudVehiculo(string id);
	string ImprimirSolicitudColaborador(string id);
	void ubicarInicio();
	void ubicarSig();
	SolicitudAlquiler* getObjActual();

	string toString();
};

