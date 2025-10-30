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


	//Las sucursales el codigo de las sucursales son del 1 al 10, y se llaman en el menu con ese numero
    Sucursal* suc1 = new Sucursal("San Joaquin", "1");
    Sucursal* suc2 = new Sucursal("San Lorenzo", "2");
    Sucursal* suc3 = new Sucursal("Santa Ana", "3");
    Sucursal* suc4 = new Sucursal("Tres Rios", "4");
    Sucursal* suc5 = new Sucursal("Puerto Viejo", "5");
    Sucursal* suc6 = new Sucursal("Orotina", "6");
    Sucursal* suc7 = new Sucursal("Heredia", "7");
    Sucursal* suc8 = new Sucursal("Escazu", "8");
    Sucursal* suc9 = new Sucursal("San Pedro", "9");
    Sucursal* suc10 = new Sucursal("Guapiles", "10");

    empresa->insertarSucursal(suc1);
    empresa->insertarSucursal(suc2);
    empresa->insertarSucursal(suc3);
    empresa->insertarSucursal(suc4);
    empresa->insertarSucursal(suc5);
    empresa->insertarSucursal(suc6);
    empresa->insertarSucursal(suc7);
    empresa->insertarSucursal(suc8);
    empresa->insertarSucursal(suc9);
    empresa->insertarSucursal(suc10);


    for (int i = 1; i <= 300; i++) {
		//Los clientes tienen id del 1 al 300, y se llaman en el menu con ese numero
        string id = numero(i);
        string nom = "Cliente " + numero(i);
        Cliente* cli = new Cliente(id, nom, "Residencia" + numero(i));

        if (i <= 30) suc1->insertarCliente(cli);
        else if (i <= 60) suc2->insertarCliente(cli);
        else if (i <= 90) suc3->insertarCliente(cli);
        else if (i <= 120) suc4->insertarCliente(cli);
        else if (i <= 150) suc5->insertarCliente(cli);
        else if (i <= 180) suc6->insertarCliente(cli);
        else if (i <= 210) suc7->insertarCliente(cli);
        else if (i <= 240) suc8->insertarCliente(cli);
        else if (i <= 270) suc9->insertarCliente(cli);
        else suc10->insertarCliente(cli);
    }

    for (int i = 1; i <= 50; i++) {
		//Los colaboradores tienen id del 1 al 50, y se llaman en el menu con ese numero
        string id = numero(i);
        string nom = "Empleado " + numero(i);
        Fecha* fechaIngreso = new Fecha(i, 1, 2025);
        Colaborador* col = new Colaborador(id, nom, fechaIngreso);

        if (i <= 5) suc1->insertarColaborador(col);
        else if (i <= 10) suc2->insertarColaborador(col);
        else if (i <= 15) suc3->insertarColaborador(col);
        else if (i <= 20) suc4->insertarColaborador(col);
        else if (i <= 25) suc5->insertarColaborador(col);
        else if (i <= 30) suc6->insertarColaborador(col);
        else if (i <= 35) suc7->insertarColaborador(col);
        else if (i <= 40) suc8->insertarColaborador(col);
        else if (i <= 45) suc9->insertarColaborador(col);
        else suc10->insertarColaborador(col); 
    }


    string letras[] = {
        "A", "B", "C", "D", "E",
        "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T"
    };
    char tipos[] = { '1', '2', '3', '4' };
    for (int i = 1; i <= 20; i++) {
		//Los planteles tienen id de A1, B2, C3 y asi hasta T20, y se llaman en el menu con ese codigo
        string inicial = letras[i - 1];
        string identi = generarID(inicial, i);
        char tipo = tipos[i % 4];
        Plantel* p = new Plantel(identi, tipo, 5, 6);

        if (i <= 2) suc1->insertarPlantel(p);
        else if (i <= 4) suc2->insertarPlantel(p);
        else if (i <= 6) suc3->insertarPlantel(p);
        else if (i <= 8) suc4->insertarPlantel(p);
        else if (i <= 10) suc5->insertarPlantel(p);
        else if (i <= 12) suc6->insertarPlantel(p);
        else if (i <= 14) suc7->insertarPlantel(p);
        else if (i <= 16) suc8->insertarPlantel(p);
        else if (i <= 18) suc9->insertarPlantel(p);
        else suc10->insertarPlantel(p);
    }

    char categorias[] = { 'A', 'B', 'C', 'D' };
    string licencias[] = { "A1", "B2", "C3" };
	string marcas[] = { "Toyota", "Honda", "Ford" };
    for (int i = 1; i <= 400; i++) {
		//Los vehiculos tienen placa del 1 al 400, y se llaman en el menu con ese numero
        string placa = numero(i);
        char cat = categorias[i % 4];
        string lic = licencias[i % 3];

        Vehiculo* v = new Vehiculo(placa, "Modelo-" + numero(i % 10), marcas[i%3], cat, lic);

        if (i <= 40) {
            suc1->insertarVehiculo(v);
            if (i <= 20) {
                suc1->getPlanteles()->getPlantel("A1")->insertarDisponible(v);
            }
            else {
                suc1->getPlanteles()->getPlantel("B2")->insertarDisponible(v);
            }
        }
        else if (i <= 80) {
            suc2->insertarVehiculo(v);
            int j = i - 40;
            if (j <= 20) {
                suc2->getPlanteles()->getPlantel("C3")->insertarDisponible(v);
            }
            else {
                suc2->getPlanteles()->getPlantel("D4")->insertarDisponible(v);
            }
        }
        else if (i <= 120) {
            suc3->insertarVehiculo(v);
            int j = i - 80;
            if (j <= 20) {
                suc3->getPlanteles()->getPlantel("E5")->insertarDisponible(v);
            }
            else {
                suc3->getPlanteles()->getPlantel("F6")->insertarDisponible(v);
            }
        }
        else if (i <= 160) {
            suc4->insertarVehiculo(v);
            int j = i - 120;
            if (j <= 20) {
                suc4->getPlanteles()->getPlantel("G7")->insertarDisponible(v);
            }
            else {
                suc4->getPlanteles()->getPlantel("H8")->insertarDisponible(v);
            }
        }
        else if (i <= 200) { 
            suc5->insertarVehiculo(v);
            int j = i - 160;
            if (j <= 20) {
                suc5->getPlanteles()->getPlantel("I9")->insertarDisponible(v);
            }
            else {
                suc5->getPlanteles()->getPlantel("J10")->insertarDisponible(v);
            }
        }
        else if (i <= 240) {
            suc6->insertarVehiculo(v);
            int j = i - 200;
            if (j <= 20) {
                suc6->getPlanteles()->getPlantel("K11")->insertarDisponible(v);
            }
            else {
                suc6->getPlanteles()->getPlantel("L12")->insertarDisponible(v);
            }
        }
        else if (i <= 280) {
            suc7->insertarVehiculo(v);
            int j = i - 240;
            if (j <= 20) {
                suc7->getPlanteles()->getPlantel("M13")->insertarDisponible(v);
            }
            else {
                suc7->getPlanteles()->getPlantel("N14")->insertarDisponible(v);
            }
        }
        else if (i <= 320) {
            suc8->insertarVehiculo(v);
            int j = i - 280;
            if (j <= 20) {
                suc8->getPlanteles()->getPlantel("O15")->insertarDisponible(v);
            }
            else {
                suc8->getPlanteles()->getPlantel("P16")->insertarDisponible(v);
            }
        }
        else if (i <= 360) { 
            suc9->insertarVehiculo(v);
            int j = i - 320;
            if (j <= 20) {
                suc9->getPlanteles()->getPlantel("Q17")->insertarDisponible(v);
            }
            else {
                suc9->getPlanteles()->getPlantel("R18")->insertarDisponible(v);
            }
        }
        else { 
            suc10->insertarVehiculo(v);
            int j = i - 360;
            if (j <= 20) {
                suc10->getPlanteles()->getPlantel("S19")->insertarDisponible(v);
            }
            else {
                suc10->getPlanteles()->getPlantel("T20")->insertarDisponible(v);
            }
        }
    }

    for (int i = 1; i <= 20; i++) {
        string id = numero(i);
        string nom = "Empleado " + numero(i);
        Fecha* fechaIngreso = new Fecha(i, 2, 2025);
        Colaborador* col = new Colaborador(id, nom, fechaIngreso);

        if (i <= 2) suc1->insertarColaborador(col);
        else if (i <= 4) suc2->insertarColaborador(col);
        else if (i <= 6) suc3->insertarColaborador(col);
        else if (i <= 8) suc4->insertarColaborador(col);
        else if (i <= 10) suc5->insertarColaborador(col);
        else if (i <= 12) suc6->insertarColaborador(col);
        else if (i <= 14) suc7->insertarColaborador(col);
        else if (i <= 16) suc8->insertarColaborador(col);
        else if (i <= 18) suc9->insertarColaborador(col);
        else suc10->insertarColaborador(col);
    }
    for (int i = 1; i <= 100; i++) {
        string cod = numero(i);
        string idCte = numero(i);

        string idCol = numero((i - 1) % 20 + 1);
        string placa = numero(i);

        Fecha* inicio = new Fecha(10, 10, 2025);
        Fecha* entrega = new Fecha(15, 10, 2025);

        SolicitudAlquiler* sol = new SolicitudAlquiler(cod, idCte, idCol, "", placa, 5, inicio, entrega, 25000.0);

        if (i <= 10) {
            sol->setIdSucursal("1"); 
            suc1->insertarSolicitud(sol);
        }
        else if (i <= 20) {
            sol->setIdSucursal("2");
            suc2->insertarSolicitud(sol);
        }
        else if (i <= 30) {
            sol->setIdSucursal("3");
            suc3->insertarSolicitud(sol);
        }
        else if (i <= 40) {
            sol->setIdSucursal("4");
            suc4->insertarSolicitud(sol);
        }
        else if (i <= 50) {
            sol->setIdSucursal("5");
            suc5->insertarSolicitud(sol);
        }
        else if (i <= 60) {
            sol->setIdSucursal("6");
            suc6->insertarSolicitud(sol);
        }
        else if (i <= 70) {
            sol->setIdSucursal("7");
            suc7->insertarSolicitud(sol);
        }
        else if (i <= 80) {
            sol->setIdSucursal("8");
            suc8->insertarSolicitud(sol);
        }
        else if (i <= 90) {
            sol->setIdSucursal("9");
            suc9->insertarSolicitud(sol);
        }
        else {
            sol->setIdSucursal("10");
            suc10->insertarSolicitud(sol);
        }
    }

    Menu* menu = new Menu(empresa);
    menu->ejecutar();
    delete menu;
    return 0;
}