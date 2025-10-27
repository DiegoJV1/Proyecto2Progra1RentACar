#pragma once
#include<iostream>
#include"Fecha.h"
using namespace std;
class SolicitudAlquiler {
protected:
	string codigo;
	string idCliente;
	string idColaborador;
	string idSucursal;
	string placa;
	int canDias;
	Fecha* inicio;
	Fecha* entrega;
	double precioDia;
	double precioTotal;
	string estado;
public:
	SolicitudAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, double pDia);
	virtual ~SolicitudAlquiler();

	string getCodigo();
	string getIdCliente();
	string getIdColaborador();
	string getIdSucursal();
	string getPlaca();
	int getCanDias();
	Fecha* getInicio();
	Fecha* getEntrega();
	double getPrecioDia();
	double getPrecioTotal();
	string getEstado();


	void setCodigo(string);
	void setIdCliente(string);
	void setIdColaborador(string);
	void setIdSucursal(string);
	void setPlaca(string);
	void setCanDias(int);
	void setInicio(Fecha*);
	void setEntrega(Fecha*);
	void setPrecioDia(double);

	void calcularPrecioTotal();
	virtual void setEstado(int nuevoEstado);
	virtual string toString();
};


