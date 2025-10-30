#include "ContratoAlquiler.h"
#include<sstream>
ContratoAlquiler::ContratoAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, float pDia) : SolicitudAlquiler(cod, idCte, idCol, idSuc, pl, dias, ini, ent, pDia) {}
void ContratoAlquiler::setEstado(int nuevoEstado) {
    switch (nuevoEstado) {
    case 1: {
        estado = "aprobado en alquiler";
        break;
    }
    case 2: {
        estado = "aprobado pendiente de ejecucion";
        break;
    }
    case 3: {
        estado = "finalizado con multa";
        break;
    }
    case 4: {
        estado = "finalizado con reintegro";
        break;
    }
    case 5: {
        estado = "finalizado sin vargos adicionales";
        break;
    }
    }
}
void ContratoAlquiler::setPrecioTotal(float pre) {
    precioTotal = pre;
}
string ContratoAlquiler::toString() {
    stringstream ss;
    ss << "----Contrato de Alquiler----" << endl;
    ss << "Codigo: " << codigo << endl;
    ss << "Colaborador-Id: " << idColaborador << endl;
    ss << "Cliente-Id: " << idCliente << endl;
    ss << "Placa-Vehiculo: " << placa << endl;
    ss << "Sucursal-Id: " << idSucursal << endl;
    ss << "Fecha de inicio: " << inicio->toString() << endl;
    ss << "Fecha de entega: " << entrega->toString() << endl;
    ss << "Costo Diario: " << precioDia << endl;
    ss << "Costo Total: " << precioTotal << endl;
    ss << "Estado: " << estado << endl;
    return ss.str();
}
