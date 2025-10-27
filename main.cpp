#include<iostream>
#include <sstream>
#include "Menu.h"
string intToStr(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string generarID(string prefijo, int num) {
    stringstream ss;
    ss << prefijo;
    if (num < 10) ss << "0";
    if (num < 100) ss << "0";
    ss << num;
    return ss.str();
}

int main() {

    RentACar* empresa = new RentACar();
    empresa->setNombre("GLOBAL RENT");

    Sucursal* suc1 = new Sucursal("CENTRAL", "S01");
    Sucursal* suc2 = new Sucursal("NORTE", "S02");
    Sucursal* suc3 = new Sucursal("SUR", "S03");

    empresa->insertarSucursal(suc1);
    empresa->insertarSucursal(suc2);
    empresa->insertarSucursal(suc3);


    for (int i = 1; i <= 100; i++) {
        string id = generarID("C", i);
        string nom = "Cliente " + intToStr(i);
        Cliente* cli = new Cliente(id, nom, "Residencia" + intToStr((i % 5) + 1));

        if (i <= 33) suc1->insertarCliente(cli);
        else if (i <= 66) suc2->insertarCliente(cli);
        else suc3->insertarCliente(cli);
    }

    for (int i = 1; i <= 30; i++) {
        string id = generarID("E", i);
        string nom = "Empleado " + intToStr(i);
        Fecha* fIngreso = new Fecha(10 + i, 1, 2024);
        Colaborador* col = new Colaborador(id, nom, fIngreso);

        if (i <= 10) suc1->insertarColaborador(col);
        else if (i <= 20) suc2->insertarColaborador(col);
        else suc3->insertarColaborador(col);
    }

    char tipos[] = { 'A', 'B', 'C' };
    for (int i = 1; i <= 9; i++) {
        string iden = generarID("P", i);
        char tipo = tipos[(i - 1) % 3]; 
        Plantel* p = new Plantel(iden, tipo, 1, 3);

        if (i <= 3) suc1->insertarPlantel(p);
        else if (i <= 6) suc2->insertarPlantel(p);
        else suc3->insertarPlantel(p);
    }

    char categorias[] = { 'A', 'B', 'C', 'D' };
    string licencias[] = { "A1", "B2", "C3" };

    for (int i = 1; i <= 200; i++) {
        string placa = "PLACA" + generarID("", i);
        char cat = categorias[(i - 1) % 4];
        string lic = licencias[(i - 1) % 3];

        Vehiculo* v = new Vehiculo(placa, "Modelo-" + intToStr(i % 5), "Marca-" + intToStr(i % 3), cat, lic);

        if (i <= 66) suc1->insertarVehiculo(v);
        else if (i <= 133) suc2->insertarVehiculo(v);
        else suc3->insertarVehiculo(v);
    }

    for (int i = 1; i <= 60; i++) {
        string cod = generarID("SOL", i);
        string idCte = generarID("C", (i % 100) + 1);
        string idCol = generarID("E", (i % 30) + 1);
        string placa = "PLACA" + generarID("", (i % 200) + 1);

        Fecha* inicio = new Fecha(10, 10, 2025);
        Fecha* entrega = new Fecha(15, 10, 2025);

        SolicitudAlquiler* sol = new SolicitudAlquiler(cod, idCte, idCol, "", placa, 5, inicio, entrega, 25000.0);

        if (i <= 20) {
            sol->setIdSucursal("S01");
            suc1->insertarSolicitud(sol);
        }
        else if (i <= 40) {
            sol->setIdSucursal("S02");
            suc2->insertarSolicitud(sol);
        }
        else {
            sol->setIdSucursal("S03");
            suc3->insertarSolicitud(sol);
        }
        if (i % 2 == 0) sol->setEstado(1);
    }

    Menu* menu = new Menu(empresa);
    menu->ejecutar();
    delete menu;
    return 0;
}