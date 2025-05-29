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

// void Pokedex::cargarArchivo(const string& fileName) const{
//     for(const auto& pokemon_info : info){
//         PokemonInfo info_pokemon = pokemon_info.second;
//         Pokemon pokemon = pokemon_info.first;

//         //serializo el pokemon
//         //PASAR ESTO A UN SERIALIZAR PARA POKEMON!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         //serializo el nombre
//         size_t tamaño_nombre = pokemon.getNombre().size();
//         outFile.write(reinterpret_cast<const char*>(&tamaño_nombre), sizeof(tamaño_nombre));
//         // file.write(pokemon.gentNombre().c_str(), tamaño_nombre);

//         //serializar experiencia
//         int experiencia = pokemon.getExperiencia();
//         outFile.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));

//         //selializo la info
//     }
// }