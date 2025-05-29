#pragma once
#include <unordered_map>
#include <fstream>
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
        bool serializar_;
    
    public:
        //constructor
        Pokedex();
        Pokedex(const std::string& fileName); //sobrecarga de sontructor para serializar
 
        
        //metodos
        void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void eliminarPokemon(const Pokemon& pokemon);
        void mostrar(const Pokemon& pokemon) const; //ver si se pasa por parametro
        void mostrarTodos() const;
        
        void serializar(std::ofstream& outFile) const; //serializa el pokedex a un archivo
        void deserializar(std::ifstream& inFile); //deserializa el pokedex desde un archivo
        
        //destructor
        ~Pokedex() = default;
};