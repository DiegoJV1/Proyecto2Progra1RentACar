#pragma once
#include<iostream>

using namespace std;
class Cliente {
protected:
	string id, nombre, residencia, tipo;
	int contador;
public:
	Cliente();
	Cliente(string id, string nom, string resi, string tipo);

	virtual ~Cliente();
	void setId(string id);
	void setNombre(string nom);
	void setResidencia(string resi);

	void aumentaContador();
	string getId();
	string getNombre();
	string getResidencia();
	int getCantidadDeSolicitudes();
	string getTipo();

	

	virtual string toString();
};
