#pragma once
#include <unordered_map>


class Pokedex{
    private:
        std::unorder_map<Pokemon, PokemonInfo> info; //completar
    
    public:
        //constructor
        Pokedex() = 
        Pokedex(const std::string& file); //sobrecarga de sontructor para serializar
 
        //sobrecarga del Hash
        //ver si pasar a privado

        namespase std ////ahora lo vep con martu

        //metodos
        void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void mostrar(const Pokemon& pokemon) const; //ver si se pasa por parametro
        void mostrarTodos() const;

}