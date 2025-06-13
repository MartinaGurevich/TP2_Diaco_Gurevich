#include "../headers/pokemon.hpp"
#include <string>
#include <fstream>

using namespace std;

//constructor
Pokemon::Pokemon(const string nombre_, int experiencia_): nombre(nombre_), experiencia(experiencia_){};

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

//serializar 
void Pokemon::serializarPoke(ofstream& out)const{
    //serializo el nombre
    size_t tamaño_nombre = nombre.size();
    out.write(reinterpret_cast<const char*>(&tamaño_nombre), sizeof(tamaño_nombre));
    out.write(nombre.c_str(), tamaño_nombre);

    //serializo Experiencia 
    out.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));
}

void Pokemon::deserializarPoke(ifstream& in){
    //nombre
    size_t nombreSize;
    in.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
    nombre.resize(nombreSize);
    in.read(&nombre[0], nombreSize);

    //experiencia
    in.read(reinterpret_cast<char*>(&experiencia), sizeof(experiencia));
    
}

