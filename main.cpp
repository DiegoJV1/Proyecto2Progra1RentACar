#include<iostream>
#include "Menu.h"
int main(){
    Cliente* cli1 = new Cliente("C101", "Ana Gomez", "Heredia");
    Cliente* cli2 = new Cliente("C102", "Juan Perez", "Alajuela");
    Cliente* cli3 = new Cliente("C103", "Maria Lopez", "San Jose");
    Cliente* cli4 = new Cliente("C104", "Carlos Ruiz", "Cartago");
    Cliente* cli5 = new Cliente("C105", "Laura Mora", "Guanacaste");
    Cliente* cli6 = new Cliente("C106", "David Soto", "Puntarenas");
    Cliente* cli7 = new Cliente("C107", "Elena Castro", "Limon");
    Cliente* cli8 = new Cliente("C108", "Fernando Diaz", "San Jose");
    Cliente* cli9 = new Cliente("C109", "Gabriela Nuñez", "Heredia");
    Cliente* cli10 = new Cliente("C110", "Hugo Torres", "Alajuela");
    Cliente* cli11 = new Cliente("C111", "Isabel Vargas", "Cartago");
    Cliente* cli12 = new Cliente("C112", "Javier Moya", "Limon");
    Cliente* cli13 = new Cliente("C113", "Karla Chaves", "Puntarenas");
    Cliente* cli14 = new Cliente("C114", "Luis Alpizar", "Guanacaste");
    Cliente* cli15 = new Cliente("C115", "Marta Solis", "Heredia");
    Cliente* cli16 = new Cliente("C116", "Oscar Vega", "San Jose");
    Cliente* cli17 = new Cliente("C117", "Patricia Mata", "Alajuela");
    Cliente* cli18 = new Cliente("C118", "Ramon Cedeño", "Cartago");
    Cliente* cli19 = new Cliente("C119", "Sofia Brenes", "Limon");
    Cliente* cli20 = new Cliente("C120", "Tomas Zuniga", "Puntarenas");
    Fecha* f1 = new Fecha(15, 8, 2021);
    Fecha* f2 = new Fecha(20, 1, 2022);
    Fecha* f3 = new Fecha(5, 12, 2020);
    Fecha* f4 = new Fecha(1, 4, 2023);
    Fecha* f5 = new Fecha(10, 6, 2021);
    Fecha* f6 = new Fecha(28, 9, 2022);
    Fecha* f7 = new Fecha(3, 3, 2024);
    Fecha* f8 = new Fecha(12, 11, 2020);
    Fecha* f9 = new Fecha(7, 7, 2023);
    Fecha* f10 = new Fecha(22, 2, 2022);

    // 10 Instancias de Colaborador (id, nombre, Fecha*)
    Colaborador* col1 = new Colaborador("CL01", "Ricardo Araya", f1);
    Colaborador* col2 = new Colaborador("CL02", "Sofia Herrera", f2);
    Colaborador* col3 = new Colaborador("CL03", "Andres Mora", f3);
    Colaborador* col4 = new Colaborador("CL04", "Viviana Solis", f4);
    Colaborador* col5 = new Colaborador("CL05", "Jorge Guzman", f5);
    Colaborador* col6 = new Colaborador("CL06", "Carmen Rojas", f6);
    Colaborador* col7 = new Colaborador("CL07", "Pablo Zuniga", f7);
    Colaborador* col8 = new Colaborador("CL08", "Diana Alfaro", f8);
    Colaborador* col9 = new Colaborador("CL09", "Esteban Quiros", f9);
    Colaborador* col10 = new Colaborador("CL10", "Fabiola Vargas", f10);

    Sucursal* suc1 = new Sucursal("San Jose - Centro", "S01");
    Sucursal* suc2 = new Sucursal("Heredia - Aeropuerto", "S02");
    Sucursal* suc3 = new Sucursal("Limon - Puerto", "S03");

    RentACar* empresa1 = new RentACar();
    empresa1->setNombre("GlobalWheels Rent");
    ColeccionSucursal* coleccionPrincipal = new ColeccionSucursal();
    RentACar* empresa2 = new RentACar("Coast2Coast Rentals", coleccionPrincipal);
    RentACar* empresa3 = new RentACar();
    empresa3->setNombre("RapidDrive Autos");

    Plantel* p1_A = new Plantel("S01-A", 'A', 5, 5);
    suc1->insertarPlantel(p1_A);
    Plantel* p1_M = new Plantel("S01-M", 'M', 3, 3);
    suc1->insertarPlantel(p1_M);
    Plantel* p2_A = new Plantel("S02-P", 'A', 8, 5);
    suc2->insertarPlantel(p2_A);
    Plantel* p2_S = new Plantel("S02-S", 'S', 4, 4);
    suc2->insertarPlantel(p2_S);
    Plantel* p3_V = new Plantel("S03-V", 'V', 10, 8);
    suc3->insertarPlantel(p3_V);
    Plantel* p3_T = new Plantel("S03-T", 'T', 6, 3);
    suc3->insertarPlantel(p3_T);

    Cliente* cli1 = new Cliente("C101", "Ana Gomez", "Heredia");
    Cliente* cli2 = new Cliente("C102", "Juan Perez", "Alajuela");
    Cliente* cli3 = new Cliente("C103", "Maria Lopez", "San Jose");
    Cliente* cli4 = new Cliente("C104", "Carlos Ruiz", "Cartago");
    Cliente* cli5 = new Cliente("C105", "Laura Mora", "Guanacaste");
    Cliente* cli6 = new Cliente("C106", "David Soto", "Puntarenas");
    Cliente* cli7 = new Cliente("C107", "Elena Castro", "Limon");
    Cliente* cli8 = new Cliente("C108", "Fernando Diaz", "San Jose");
    Cliente* cli9 = new Cliente("C109", "Gabriela Nuñez", "Heredia");
    Cliente* cli10 = new Cliente("C110", "Hugo Torres", "Alajuela");
    Cliente* cli11 = new Cliente("C111", "Isabel Vargas", "Cartago");
    Cliente* cli12 = new Cliente("C112", "Javier Moya", "Limon");
    Cliente* cli13 = new Cliente("C113", "Karla Chaves", "Puntarenas");
    Cliente* cli14 = new Cliente("C114", "Luis Alpizar", "Guanacaste");
    Cliente* cli15 = new Cliente("C115", "Marta Solis", "Heredia");
    Cliente* cli16 = new Cliente("C116", "Oscar Vega", "San Jose");
    Cliente* cli17 = new Cliente("C117", "Patricia Mata", "Alajuela");
    Cliente* cli18 = new Cliente("C118", "Ramon Cedeño", "Cartago");
    Cliente* cli19 = new Cliente("C119", "Sofia Brenes", "Limon");
    Cliente* cli20 = new Cliente("C120", "Tomas Zuniga", "Puntarenas");

    suc1->insertarCliente(cli1);
    suc1->insertarCliente(cli2);
    suc1->insertarCliente(cli3);
    suc1->insertarCliente(cli4);
    suc1->insertarCliente(cli5);
    suc1->insertarCliente(cli6);
    suc1->insertarCliente(cli7);

    suc2->insertarCliente(cli8);
    suc2->insertarCliente(cli9);
    suc2->insertarCliente(cli10);
    suc2->insertarCliente(cli11);
    suc2->insertarCliente(cli12);
    suc2->insertarCliente(cli13);
    suc2->insertarCliente(cli14);

    suc3->insertarCliente(cli15);
    suc3->insertarCliente(cli16);
    suc3->insertarCliente(cli17);
    suc3->insertarCliente(cli18);
    suc3->insertarCliente(cli19);
    suc3->insertarCliente(cli20);



    suc1->insertarColaborador(col1);
    suc1->insertarColaborador(col2);
    suc1->insertarColaborador(col3);
    suc1->insertarColaborador(col4);

    suc2->insertarColaborador(col5);
    suc2->insertarColaborador(col6);
    suc2->insertarColaborador(col7);

    suc3->insertarColaborador(col8);
    suc3->insertarColaborador(col9);
    suc3->insertarColaborador(col10);



















    delete empresa1;
    delete empresa2;
    delete empresa3;

    delete suc1;
    delete suc2;
    delete suc3;

    delete col1;
    delete col2;
    delete col3;
    delete col4;
    delete col5;
    delete col6;
    delete col7;
    delete col8;
    delete col9;
    delete col10;

    delete cli1;
    delete cli2;
    delete cli3;
    delete cli4;
    delete cli5;
    delete cli6;
    delete cli7;
    delete cli8;
    delete cli9;
    delete cli10;
    delete cli11;
    delete cli12;
    delete cli13;
    delete cli14;
    delete cli15;
    delete cli16;
    delete cli17;
    delete cli18;
    delete cli19;
    delete cli20;
    return 0;
}