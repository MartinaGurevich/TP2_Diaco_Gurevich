#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;


class PokemonInfo{
    private:
        string tipo;
        string descripcion;
        map<string, int> ataques; //considerar unordered_map
        map<int,int> experienciaProxNivel; //considerar vector

    public:
        //constructor
        PokemonInfo();
        PokemonInfo(const string tipo_, const string descripcion_, 
            map<string, int> ataques_,
            map<int,int> experienciaProxNivel_
        );
        PokemonInfo(const PokemonInfo& other); //constructor de copia

        //getters
        string getTipo() const;
        string getDescripcion() const;
        map<string,int>& getAtaques();
        map<int,int>& getExperienciaProxNivel();

        //destructor
        ~PokemonInfo() = default;
};


