#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;


class PokemonInfo
{
private:
   string tipo;
   string descripcion;
   map<string, int> ataquesDisponiblesPorNivel;
   map<int,int> experienciaProximoNivel;

public:
    PokemonInfo(string tipo, string descripcion, 
        map<string, int> ataquesDisponiblesPorNivel,
        map<int,int> experienciaProximoNivel
    );

    string getTipo() const;
    string getDescripcion() const;
    map<string,int> getAtaquedispoporNivel() const;
    map<int,int> getExperienciaProxNivel() const;

    ~PokemonInfo()=default;
};


