#pragma once
#include <unordered_map>
#include "pokemon.hpp"

//funcion de Hash para el nombre del Pokemon implementada como functor

class PokemonHash{
    public:
        std::size_t operator()(const Pokemon& pokemon) const {
            return std::hash<std::string>()(pokemon.getNombre());
        }
};

class Pokedex{
    private:
        std::unorder_map<Pokemon, PokemonInfo, PokemonHash> info; //completar
    
    public:
        //constructor
        Pokedex() = default;
        Pokedex(const std::string& file); //sobrecarga de sontructor para serializar
 
        
        //metodos
        void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void eliminarPokemon(const Pokemon& pokemon);
        void mostrar(const Pokemon& pokemon) const; //ver si se pasa por parametro
        void mostrarTodos() const;
        
        void serializar(const std::string& file) const; //serializa el pokedex a un archivo
        void deserializar(const std::string& file); //deserializa el pokedex desde un archivo
        
};