#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;


class PokemonInfo
{
private:
   string tipo;
   string descrpcion;
   map<string, int> ataquesDisponiblesPorNivel;
   map<int,int> experienciaProximoNivel;

public:
    PokemonInfo(string tipo, string descripcion, 
        map<string, int> ataquesDisponiblesPorNivel,
        map<int,int> experienciaProximoNivel
    );

    void getTipo();
    void getDescripcion();
    void getAtaquedispoporNivel();
    void getExperienciaProxNivel();

    ~PokemonInfo()=default;
};


