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
        std::unordered_map<Pokemon, PokemonInfo, PokemonHash> info; //completar
        std::string fileName; //nombre del archivo para serializar
    
    public:
        //constructor
        Pokedex() = default;
        Pokedex(const std::string& fileName_); //sobrecarga de sontructor para serializar
 
        
        //metodos
        void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void eliminarPokemon(const Pokemon& pokemon);
        void mostrar(const Pokemon& pokemon) const; //ver si se pasa por parametro
        void mostrarTodos() const;
        
        void cargarArchivo(const std::string& fileName) const; //serializa el pokedex a un archivo
        void descargarArchivo(const std::string& fileName); //deserializa el pokedex desde un archivo
        
        //destructor
        ~Pokedex() = default;
};