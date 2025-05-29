#include "../headers/pokemonInfo.hpp"
#include <string>

using namespace std;

//constructores
PokemonInfo::PokemonInfo()
    :tipo(""), descripcion(""), ataques(), experienciaProxNivel() {}

PokemonInfo::PokemonInfo(const string tipo_, const string descripcion_, 
        map<string, int> ataques_,
        map<int,int> experienciaProxNivel_):
        
        tipo(tipo_), 
        descripcion(descripcion_), 
        ataques(ataques_),
        experienciaProxNivel(experienciaProxNivel_){};

PokemonInfo::PokemonInfo(const PokemonInfo& other):
        tipo(other.tipo), 
        descripcion(other.descripcion), 
        ataques(other.ataques),
        experienciaProxNivel(other.experienciaProxNivel) {}


//getters
string PokemonInfo::getTipo() const{
    return tipo;
}

string PokemonInfo::getDescripcion() const{
    return descripcion;
}

map<string,int>& PokemonInfo::getAtaques(){
    
    return ataques;
}

map<int,int>& PokemonInfo::getExperienciaProxNivel(){
    return experienciaProxNivel;
} 

