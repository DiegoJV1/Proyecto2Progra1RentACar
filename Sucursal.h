#pragma once
#include"ColeccionColaborador.h"
#include"ColeccionCliente.h"
#include"ColeccionVehiculo.h"
#include"ColeccionPlantel.h"
#include"ColeccionSolicitudAlquiler.h"
#include"ColeccionContratoAlquiler.h"
class Sucursal {
private:
	string ubicacion, num;
	ColeccionPlantel* planteles;
	ColeccionCliente* clientes;
	ColeccionVehiculo* vehiculos;
	ColeccionColaborador* colaboradores;
	ColeccionSolicitudAlquiler* solicitudes;
	ColeccionContratoAlquiler* contratos;
public:
	Sucursal();
	Sucursal(string ubi, string num);
	~Sucursal();
	void setNum(string num);
	string getNum();
	void setUbicacion(string ubi);
	string getUbicaion();
	void insertarCliente(Cliente* aux);
	void insertarVehiculo(Vehiculo* aux);
	void insertarColaborador(Colaborador* aux);
	void insertarPlantel(Plantel* aux);
	void insertarSolicitud(SolicitudAlquiler* aux);
	void insertarContrato(ContratoAlquiler* aux);

	ColeccionPlantel* getPlanteles();
	ColeccionCliente* getClientes();
	ColeccionColaborador* getColaboradores();
	ColeccionVehiculo* getVehiculos();
	ColeccionSolicitudAlquiler* getSolicitudes();
	ColeccionContratoAlquiler* getContratos();
	
	void eliminarCliente(string id);
	void eliminarVehiculo(string placa);
	void eliminarColaborador(string id);
	void eliminarPlantel(string iden);

	Cliente* getCliente(string id);
	Vehiculo* getVehiculo(string placa);
	Colaborador* getColaborador(string id);
	Plantel* getPlantel(string iden);
	SolicitudAlquiler* getSolicitud(string cod);
	ContratoAlquiler* getContrato(string cod);

	void modificarContadorClientes();
	string recomendacionDePlantel();

	string imprimirClientesYContratos();
	string toString();

};

