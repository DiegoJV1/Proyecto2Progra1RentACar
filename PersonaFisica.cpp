#include "PersonaFisica.h"
#include<sstream>
PersonaFisica::PersonaFisica() : Cliente() {}
PersonaFisica::PersonaFisica(string id, string nom, string resi, string tipo) : Cliente(id, nom, resi, tipo) {}
PersonaFisica::~PersonaFisica() {}

