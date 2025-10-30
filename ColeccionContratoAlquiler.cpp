#include "ColeccionContratoAlquiler.h"
#include<sstream>
ColeccionContratoAlquiler::ColeccionContratoAlquiler() : inicio(nullptr), actual(nullptr) {}
ColeccionContratoAlquiler::~ColeccionContratoAlquiler() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual;
	}
}
void ColeccionContratoAlquiler::insertarContrato(ContratoAlquiler* aux) {
	NodoContratoAlquiler* nuevo = new NodoContratoAlquiler(aux);
	if (!inicio) {
		inicio = nuevo;
		return;
	}
	else {
		actual = inicio;
		while (actual->getSig()) {
			if (actual->getObj()->getCodigo() == aux->getCodigo()) {
				cout << "ERROR: Ya existe la solicitud" << endl;
				return;
			}
			actual = actual->getSig();
		}
		actual->setSig(nuevo);
	}
}
ContratoAlquiler* ColeccionContratoAlquiler::buscarContrato(string cod) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getCodigo() == cod) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
string ColeccionContratoAlquiler::toString() {
	stringstream ss;
	ss << "Lista de Contratos/Solicitudes de alquiler: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Solicitud/Contrato #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();

}
bool ColeccionContratoAlquiler::esMayorFecha(Fecha* f1, Fecha* f2) {
	if (f1->getAnnio() != f2->getAnnio()) {
		return f1->getAnnio() > f2->getAnnio();
	}
	if (f1->getMes() != f2->getMes()) {
		return f1->getMes() > f2->getMes();
	}
	return f1->getDia() > f2->getDia();
}
bool ColeccionContratoAlquiler::esMenorFecha(Fecha* f1, Fecha* f2) {
	if (f1->getAnnio() != f2->getAnnio()) {
		return f1->getAnnio() > f2->getAnnio();
	}
	if (f1->getMes() != f2->getMes()) {
		return f1->getMes() > f2->getMes();
	}
	return f1->getDia() > f2->getDia();
}

void ColeccionContratoAlquiler::ordenarSolicitudesMenorAMayor() {
	if (inicio == nullptr || inicio->getSig() == nullptr) return;

	NodoContratoAlquiler* nuevoInicio = nullptr;
	NodoContratoAlquiler* actual = inicio;

	while (actual) {
		NodoContratoAlquiler* siguiente = actual->getSig();
		Fecha* fechaActual = actual->getObj()->getInicio();
		if (!nuevoInicio || esMenorFecha(fechaActual, nuevoInicio->getObj()->getInicio())) {
			Fecha* fechaActual = actual->getObj()->getInicio();
			if (!nuevoInicio || esMayorFecha(fechaActual, nuevoInicio->getObj()->getInicio())) {
				actual->setSig(nuevoInicio);
				nuevoInicio = actual;
			}
			else {
				NodoContratoAlquiler* s = nuevoInicio;
				while (s->getSig() && !esMenorFecha(fechaActual, s->getSig()->getObj()->getInicio())) {
					s = s->getSig();
				}
			}
			if (!nuevoInicio || esMayorFecha(fechaActual, nuevoInicio->getObj()->getInicio())) {
				actual->setSig(nuevoInicio);
				nuevoInicio = actual;
			}
			else {
				NodoContratoAlquiler* s = nuevoInicio;
				while (s->getSig() && !esMayorFecha(fechaActual, s->getSig()->getObj()->getInicio())) {
					s = s->getSig();
				}
				actual->setSig(s->getSig());
				s->setSig(actual);
			}
			actual = siguiente;
		}
		inicio = nuevoInicio;
	}
}
ContratoAlquiler* ColeccionContratoAlquiler::getContratoCliente(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getIdCliente() == id) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
}
ContratoAlquiler* ColeccionContratoAlquiler::getContratoVehiculo(string placa) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getPlaca() == placa) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
}
ContratoAlquiler* ColeccionContratoAlquiler::getContratoColaborador(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getIdColaborador() == id) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
}

string ColeccionContratoAlquiler::ImprimirContratoCliente(string id) {
	stringstream ss;
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getIdCliente() == id) {
			ss << "Codigo del contrato: "<<actual->getObj()->getCodigo()<<endl;
			ss << "Placa del Vehiculo: "<<actual->getObj()->getPlaca()<<endl<<endl;
		}
		actual = actual->getSig();
	}
	return ss.str();
}
string ColeccionContratoAlquiler::ImprimirContratoVehiculo(string placa) {
	stringstream ss;
	actual = inicio;
	ss << "Placa: " << placa << endl;
	while (actual) {
		if (actual->getObj()->getPlaca() == placa) {
			ss << actual->getObj()->toString()<<endl;
		}
		actual = actual->getSig();
	}
	return ss.str();
}
string ColeccionContratoAlquiler::ImprimirContratoColaborador(string id) {
	stringstream ss;
	actual = inicio;
	ss << "Id: " << id << endl;
	while (actual) {
		if (actual->getObj()->getIdColaborador() == id) {
			ss << actual->getObj()->toString() << endl;
		}
		actual = actual->getSig();
	}
	return ss.str();
}

void ColeccionContratoAlquiler::ubicarInicio() { actual = inicio; }
void ColeccionContratoAlquiler::ubicarSig() { if (actual) { actual = actual->getSig(); } }
ContratoAlquiler* ColeccionContratoAlquiler::getObjActual() { 
	if (actual) { return actual->getObj(); }
	else { return nullptr; }
}
