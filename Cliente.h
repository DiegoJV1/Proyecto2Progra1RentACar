#pragma once
#include<iostream>

using namespace std;
class Cliente {
protected:
	string id, nombre, residencia;
	int contador;
public:
	Cliente();
	Cliente(string id, string nom, string resi);

	virtual ~Cliente();
	void setId(string id);
	void setNombre(string nom);
	void setResidencia(string resi);

	void aumentaContador();
	string getId();
	string getNombre();
	string getResidencia();
	int getCantidadDeSolicitudes();


	virtual string toString();
};
