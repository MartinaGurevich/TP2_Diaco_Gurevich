#include "../headers/pokemon.hpp"
#include <string>

using namespace std;

//constructor
Pokemon::Pokemon(const string nombre_, int experiencia_): nombre(nombre_), experiencia(experiencia_){};

Pokemon::Pokemon(const Pokemon& other): nombre(other.nombre), experiencia(other.experiencia) {}

//getters
string Pokemon::getNombre() const {
    return nombre;
}

int Pokemon::getExperiencia() const{
    return experiencia;
}

//sobrecarga del operador ==, compara nombre de pokemon.
bool Pokemon::operator==(const Pokemon& other) const{
    return nombre == other.getNombre();
}


