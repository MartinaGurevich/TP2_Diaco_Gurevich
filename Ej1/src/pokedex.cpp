#include "../headers/pokedex.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//construnctor sobrecargado para serializar
Pokedex::Pokedex(const string& file) {
    serializar(file);
}

//metodos
void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info) {
    this->info[pokemon] = info;
}

void Pokedex::eliminarPokemon(const Pokemon& pokemon) {
    this->info.erase(pokemon); //ver si hay que sobrecargar algo
}

void Pokedex::mostrar(const Pokemon& pokemon)const{
    auto it = info.find(pokemon);
    if(it != info.end())
        ////muestrainfo
        info_pokemon = info[pokemon]
        cout<<"Tipo: "<<info_pkemon.getTipo()<<endl;
        cout<<info_pkemon.getDescripcion()<<endl;
        cout<<"Ataques disponibles: "<<info_pkemon.getAtaquedispoporNivel()<<endl;
        cout<<"Experiencia para el proximo nivel: "<<info_pkemon.getExperienciaProxNivel()<<endl;
    else
        cout<< "¡Pokemon desconocido!"<<endl;
}

void Pokemon::mostrarTodos()const{
    for(const auto& pokemon: info){
        //ver si hacer funcion para no repetir
        info_pokemon = info[pokemon]
        cout<<"nTipo: "<<info_pkemon.getTipo()<<endl;
        cout<<info_pkemon.getDescripcion()<<endl;
        cout<<"Ataques disponibles: "<<to_string(info_pkemon.getAtaquedispoporNivel())<<endl;
        cout<<"Experiencia para el proximo nivel: "<<to_string(info_pkemon.getExperienciaProxNivel())<<endl;
    }
}