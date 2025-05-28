#include "pokemon.hpp"


Pokemon:: Pokemon(string nombre, int experiencia): nombre(nombre), experiencia(experiencia){};

string Pokemon:: getNombre() const {
    return nombre;
}

int Pokemon:: getExperiencia() const{
    return experiencia;
}

//sobrecarga del operador ==, compara nombre de pokemon.
bool Pokemon:: operator ==(const Pokemon& other) const{
    return nombre== other.getNombre();
}


