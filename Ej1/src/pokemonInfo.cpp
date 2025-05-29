#include "../headers/pokemonInfo.hpp>"
#include <string>

using namespace std;

PokemonInfo::PokemonInfo(const string& tipo_, const string& descripcion_, 
        map<string, int> ataquesDisponiblesPorNivel_,
        map<int,int> experienciaProximoNivel_):
        
        tipo(tipo_), 
        descripcion(descripcion_), 
        ataquesDisponiblesPorNivel(ataquesDisponiblesPorNivel_),
        experienciaProximoNivel(experienciaProximoNivel_){};

string PokemonInfo::getTipo() const{
    return tipo;
}

string PokemonInfo::getDescripcion() const{
    return descripcion;
}

map<string,int> PokemonInfo:: getAtaquedispoporNivel() const{
    
    return ataquesDisponiblesPorNivel;
}

map<int,int> PokemonInfo::getExperienciaProxNivel() const{
    return experienciaProximoNivel;
} 

