#pragma once
#include <unordered_map>
#include "pokemon.hpp"
#include "pokemonInfo.hpp"

//funcion de Hash para el nombre del Pokemon implementada como functor
class PokemonHash{
    public:
        std::size_t operator()(const Pokemon& pokemon) const;
}; 

class Pokedex{
    private:
        std::unordered_map<Pokemon, PokemonInfo, PokemonHash> info;
        std::string fileName; //nombre del archivo para cargar los datos

        void mostrar_(Pokemon& pokemon, PokemonInfo& info) const;
    
    public:
        //constructor
        Pokedex() = default;
        Pokedex(const std::string& fileName_, bool serializar = true); //sobrecarga de sontructor para serializar
        //el bool será false si lo que se quiere es descargar el archivo,
 
        //metodos
        void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info_pokemon, bool serializar = true);
        void eliminarPokemon(const Pokemon& pokemon);
        void mostrar(const Pokemon& pokemon) const; //ver si se pasa por parametro
        void mostrarTodos() const;
        
        void cargarArchivo(); //carga el pokedex a un archivo
        void descargarArchivo(); //descarga el pokedex desde un archivo
        
        //destructor
        ~Pokedex() = default;
};
