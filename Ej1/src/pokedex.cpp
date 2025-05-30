#include "../headers/pokedex.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//funcion de hash
size_t PokemonHash::operator()(const Pokemon& pokemon) const {
    return hash<string>()(pokemon.getNombre());
}

//construnctor sobrecargado para serializar
Pokedex::Pokedex(const string& fileName_): fileName(fileName_){
    //Pokedex::cargarArchivo(fileName); //HAY QUE VER COMO PASAR BIEN LSO DATOS
}

//metodos
void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info_pokemon) {
    info[pokemon] = info_pokemon;
}

void Pokedex::eliminarPokemon(const Pokemon& pokemon) {
    info.erase(pokemon); //Fuenciona pues se cobrecargo el operdor == para Pokemon
}

void Pokedex::mostrar(const Pokemon& pokemon)const{
    auto it = info.find(pokemon);
    if(it != info.end()){
        ////muestrainfo
        PokemonInfo info_pokemon = it -> second;
        
        cout<<"==="<<pokemon.getNombre()<<"==="<<endl;
        cout<<"Tipo: "<<info_pokemon.getTipo()<<endl;
        cout<<info_pokemon.getDescripcion()<<endl;
        //cout<<"Ataques disponibles: "<<to_string(info_pokemon.getAtaquedispoporNivel())<<endl; HAY QUE ARMAR BIEN LA SALIDA
        //cout<<"Experiencia para el proximo nivel: "<<to_string(info_pokemon.getExperienciaProxNivel())<<endl;
    }else
        cout<< "¡Pokemon desconocido!"<<endl;
}

void Pokedex::mostrarTodos()const{
    for(const auto& pokemon_info: info){
        //ver si hacer funcion para no repetir
        PokemonInfo info_pokemon = pokemon_info.second;
        Pokemon pokemon = pokemon_info.first;

        cout<<"==="<<pokemon.getNombre()<<"==="<<endl;
        cout<<"\nnTipo: "<<info_pokemon.getTipo()<<endl;
        cout<<info_pokemon.getDescripcion()<<endl;
        //cout<<"Ataques disponibles: "<<to_string(info_pokemon.getAtaquedispoporNivel())<<endl; ARMAR BIEN LA SALIDA
        //cout<<"Experiencia para el proximo nivel: "<<to_string(info_pokemon.getExperienciaProxNivel())<<endl;
    }
}

void Pokedex::cargarArchivo(const string& fileName) const{
    //serializo info
    ofstream out(fileName, ios::binary)

    if(out.is_open()){
        for(const auto& pokemon_info : info){
            pokemon_info.first.serializarPoke(out)
            pokemon_info.second.serializarInfo(out)
        }
        out.close();
    }

//TERMINAR
}