#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;


class PokemonInfo{
    private:
        string tipo;
        string descripcion;
        map<string, int> ataquesDisponiblesPorNivel;
        map<int,int> experienciaProximoNivel;

    public:
        //constructor
        PokemonInfo(const string& tipo_, const string& descripcion_, 
            map<string, int> ataquesDisponiblesPorNivel_,
            map<int,int> experienciaProximoNivel_
        );

        //getters
        string getTipo() const;
        string getDescripcion() const;
        map<string,int> getAtaquedispoporNivel() const;
        map<int,int> getExperienciaProxNivel() const;

        //destructor
        ~PokemonInfo()=default;
};


