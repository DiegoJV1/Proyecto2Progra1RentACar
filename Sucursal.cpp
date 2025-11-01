#include "Sucursal.h"
#include<sstream>
Sucursal::Sucursal() : ubicacion(""), num("") {
	clientes = new ColeccionCliente();
	colaboradores = new ColeccionColaborador();
	vehiculos = new ColeccionVehiculo();
	planteles = new ColeccionPlantel();
	solicitudes = new ColeccionSolicitudAlquiler();
	contratos = new ColeccionContratoAlquiler();
}
Sucursal::Sucursal(string ubi, string num) : ubicacion(ubi), num(num) {
	clientes = new ColeccionCliente();
	colaboradores = new ColeccionColaborador();
	vehiculos = new ColeccionVehiculo();
	planteles = new ColeccionPlantel();
	solicitudes = new ColeccionSolicitudAlquiler();
	contratos = new ColeccionContratoAlquiler();
}
Sucursal::~Sucursal() {
	delete clientes;
	delete colaboradores;
	delete vehiculos;
	delete planteles;
	delete solicitudes;
	delete contratos;
}
void Sucursal::setNum(string num) { this->num = num; }
string Sucursal::getNum() { return num; }
void Sucursal::setUbicacion(string ubi) { this->ubicacion = ubi; }
string Sucursal::getUbicaion() { return ubicacion; }
void Sucursal::insertarPlantel(Plantel* aux) {
	if (!planteles) {
		planteles = new ColeccionPlantel();
		planteles->insertarPlantel(aux);
	}
	else {
		planteles->insertarPlantel(aux);
	}

}
void Sucursal::insertarCliente(Cliente* aux) {
	if (!clientes) {
		clientes = new ColeccionCliente();
		clientes->insertarCliente(aux);
	}
	else {
		clientes->insertarCliente(aux);
	}
}
void Sucursal::insertarVehiculo(Vehiculo* aux) {
	if (!vehiculos) {
		vehiculos = new ColeccionVehiculo();
		vehiculos->insertarVehiculo(aux);
	}
	else {
		vehiculos->insertarVehiculo(aux);
	}
}
void Sucursal::insertarColaborador(Colaborador* aux) {
	if (!colaboradores) {
		colaboradores = new ColeccionColaborador();
		colaboradores->insertarColaborador(aux);
	}
	else {
		colaboradores->insertarColaborador(aux);
	}
}
void Sucursal::insertarSolicitud(SolicitudAlquiler* aux) {
	solicitudes->insertarSolicitud(aux);
	getCliente(aux->getIdCliente())->aumentaContador();
}

void Sucursal::insertarContrato(ContratoAlquiler* aux) {
	contratos->insertarContrato(aux);
	getCliente(aux->getIdCliente())->aumentaContador();

}
void Sucursal::eliminarCliente(string id) {
	if (clientes) {
		clientes->eliminarCliente(id);
	}
	else {
		return;
	}
}
void Sucursal::eliminarVehiculo(string placa) {
	if (vehiculos) {
		vehiculos->eliminarVehiculo(placa);
	}
	else {
		return;
	}
}
void Sucursal::eliminarColaborador(string id) {
	if (colaboradores) {
		colaboradores->eliminarColaborador(id);
	}
	else {
		return;
	}
}
void Sucursal::eliminarPlantel(string identificacion) {
	if (planteles) {
		planteles->eliminarPlantel(identificacion);
	}
	else {
		return;
	}
}

Cliente* Sucursal::getCliente(string id) {
	return clientes->getCliente(id);
}
Vehiculo* Sucursal::getVehiculo(string placa) {
	return vehiculos->getVehiculo(placa);
}
Colaborador* Sucursal::getColaborador(string id) {
	return colaboradores->getColaborador(id);
}
Plantel* Sucursal::getPlantel(string iden) {
	return planteles->getPlantel(iden);
}
SolicitudAlquiler* Sucursal::getSolicitud(string cod) {
	return solicitudes->buscarSolicitud(cod);
}
ContratoAlquiler* Sucursal::getContrato(string cod) {
	return contratos->buscarContrato(cod);
}
ColeccionPlantel* Sucursal::getPlanteles() { return planteles; }
ColeccionCliente* Sucursal::getClientes() { return clientes; }
ColeccionColaborador* Sucursal::getColaboradores() { return colaboradores; }
ColeccionVehiculo* Sucursal::getVehiculos() { return vehiculos; }
ColeccionSolicitudAlquiler* Sucursal::getSolicitudes() { return solicitudes; }
ColeccionContratoAlquiler* Sucursal::getContratos() { return contratos; }

string Sucursal::recomendacionDePlantel() {
	if (planteles) {
		return planteles->plantelRecomendado();
	}
}
void Sucursal::modificarContadorClientes() {
	clientes->ubicarInicio();
	while (clientes->getObjActual()) {
		clientes->getObjActual()->reiniciarContador();

		contratos->ubicarInicio();
		while (contratos->getObjActual()) {
			if (contratos->getObjActual()->getIdCliente() == clientes->getObjActual()->getId()) {
				clientes->getObjActual()->aumentaContador();
			}
			contratos->ubicarSig();
		}
		clientes->ubicarSig();
	}
}

string Sucursal::imprimirClientesYContratos() {
	stringstream ss;
	clientes->ubicarInicio();
	while (clientes->getObjActual()) {
		ss << "ID: "<<clientes->getObjActual()->getId() << endl;
		ss << "Nombre: "<<clientes->getObjActual()->getNombre() << endl;
		ss << "Cantidad de Contratos: " << clientes->getObjActual()->getCantidadDeSolicitudes() << endl;
		contratos->ubicarInicio();
		while (contratos->getObjActual()) {
			if (contratos->getObjActual()->getIdCliente() == clientes->getObjActual()->getId()) {
				ss <<"Contrato: "<< contratos->getObjActual()->getCodigo() << endl<<endl;
			}
			contratos->ubicarSig();
		}
		clientes->ubicarSig();
	}
	return ss.str();
}


string Sucursal::toString() {
	stringstream ss;
	ss << "----Sucursal " << num << "----" << endl;
	ss << "Ubicacion: " << ubicacion << endl;
	if (planteles) {
		ss << "Detalle de Planteles: " << endl;
		ss << planteles->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Planteles: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (clientes) {
		ss << "Detalle de Clientes: " << endl;
		ss << clientes->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Clientes: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (vehiculos) {
		ss << "Detalle de Vehiculos: " << endl;
		ss << vehiculos->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Vehiculos: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (colaboradores) {
		ss << "Detalle de Colaboradores: " << endl;
		ss << colaboradores->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Colaboradores: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}
	return ss.str();
}

