#include "pokemonInfo.hpp"

PokemonInfo:: PokemonInfo(string tipo, string descripcion, 
        map<string, int> ataquesDisponiblesPorNivel,
        map<int,int> experienciaProximoNivel): 
        tipo(tipo), 
        descripcion(descripcion), 
        ataquesDisponiblesPorNivel(ataquesDisponiblesPorNivel),
        experienciaProximoNivel(experienciaProximoNivel){};

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

