#include<iostream>
#include <sstream>
#include "Menu.h"

string numero(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string generarID(string prefijo, int num) {
    stringstream ss;
    ss << prefijo << num;
    return ss.str();
}

int main() {

    RentACar* empresa = new RentACar();
    empresa->setNombre("Renta A Car");

    //para probar
    /*
    Fecha* f = new Fecha(1, 2, 2020);
    Colaborador* t1 = new Colaborador("789", "f", f);
    Cliente* c1 = new Cliente("456", "h", "h");
    Plantel* p1 = new Plantel("A", 1, 3, 4);
    Sucursal* nueva = new Sucursal("H", "123");
    nueva->insertarCliente(c1);
    nueva->insertarColaborador(t1);
    Vehiculo* carro = new Vehiculo("0", "f", "t", 'A', "B1");
    p1->insertarVehiculo(carro, "A", 0, 0);
    nueva->insertarPlantel(p1);
    nueva->insertarVehiculo(carro);
    empresa->insertarSucursal(nueva);
    */


    //tienen que ser 10 sucursales
    Sucursal* suc1 = new Sucursal("Alajuela", "S1");
    Sucursal* suc2 = new Sucursal("Cartago", "S2");
    Sucursal* suc3 = new Sucursal("Heredia", "S3");

    empresa->insertarSucursal(suc1);
    empresa->insertarSucursal(suc2);
    empresa->insertarSucursal(suc3);


    for (int i = 1; i <= 100; i++) {
        string id = generarID("C", i);
        string nom = "Cliente " + numero(i);
        Cliente* cli = new Cliente(id, nom, "Residencia" + numero(i));

        if (i <= 33) suc1->insertarCliente(cli);
        else if (i <= 66) suc2->insertarCliente(cli);
        else suc3->insertarCliente(cli);
    }

    for (int i = 1; i <= 30; i++) {
        string id = generarID("E", i);
        string nom = "Empleado " + numero(i);
        Fecha* fechaIngreso = new Fecha(i, 1, 2025);
        Colaborador* col = new Colaborador(id, nom, fechaIngreso);

        if (i <= 10) suc1->insertarColaborador(col);
        else if (i <= 20) suc2->insertarColaborador(col);
        else suc3->insertarColaborador(col);
    }

    char tipos[] = { 'A', 'B', 'C' };
    for (int i = 0; i < 9; i++) {
        string iden = generarID("P", i + 1);
        char tipo = tipos[i % 3];
        Plantel* p = new Plantel(iden, tipo, 1, 3);

        if (i < 3) suc1->insertarPlantel(p);
        else if (i < 6) suc2->insertarPlantel(p);
        else suc3->insertarPlantel(p);
    }

    char categorias[] = { 'A', 'B', 'C', 'D' };
    string licencias[] = { "A1", "B2", "C3" };
    for (int i = 0; i < 200; i++) {
        string placa = "PLACA" + generarID("", i + 1);
        char cat = categorias[i % 4];
        string lic = licencias[i % 3];

        Vehiculo* v = new Vehiculo(placa, "Modelo-" + numero(i % 5), "Marca-" + numero(i % 3), cat, lic);

        if (i < 66) {
            suc1->insertarVehiculo(v);
            if (i < 22) {
                suc1->getPlanteles()->getPlantel("P1")->insertarDisponible(v);
            }
            else if (i < 44) {
                suc1->getPlanteles()->getPlantel("P2")->insertarDisponible(v);
            }
            else {
                suc1->getPlanteles()->getPlantel("P3")->insertarDisponible(v);
            }

        }
        else if (i < 133) {
            suc2->insertarVehiculo(v);
            if (i < 88) {
                suc2->getPlanteles()->getPlantel("P4")->insertarDisponible(v);
            }
            else if (i < 110) {
                suc2->getPlanteles()->getPlantel("P5")->insertarDisponible(v);
            }
            else {
                suc2->getPlanteles()->getPlantel("P6")->insertarDisponible(v);
            }
        }
        else {
            suc3->insertarVehiculo(v);
            if (i < 155) {
                suc3->getPlanteles()->getPlantel("P7")->insertarDisponible(v);
            }
            else if (i < 177) {
                suc3->getPlanteles()->getPlantel("P8")->insertarDisponible(v);
            }
            else {
                suc3->getPlanteles()->getPlantel("P9")->insertarDisponible(v);
            }
        }
    }

    for (int i = 1; i <= 60; i++) {
        string cod = generarID("SOL", i);
        string idCte = generarID("C", i);
        string idCol = generarID("E", i);
        string placa = "PLACA" + generarID("", i);

        Fecha* inicio = new Fecha(10, 10, 2025);
        Fecha* entrega = new Fecha(15, 10, 2025);

        SolicitudAlquiler* sol = new SolicitudAlquiler(cod, idCte, idCol, "", placa, 5, inicio, entrega, 25000.0);

        if (i <= 20) {
            sol->setIdSucursal("S1");
            suc1->insertarSolicitud(sol);
        }
        else if (i <= 40) {
            sol->setIdSucursal("S2");
            suc2->insertarSolicitud(sol);
        }
        else {
            sol->setIdSucursal("S3");
            suc3->insertarSolicitud(sol);
        }
        if (i % 2 == 0) sol->setEstado(1);
    }

    Menu* menu = new Menu(empresa);
    menu->ejecutar();
    delete menu;
    return 0;
}