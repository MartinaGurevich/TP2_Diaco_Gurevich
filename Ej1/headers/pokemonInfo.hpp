#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class PokemonInfo{
    private:
        string tipo;
        string descripcion;
        unordered_map<string, int> ataques;//cambiamos de map a unordered
        vector<int> experienciaProxNivel; //cambiamos a vector de map

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
        unordered_map<string, int>& getAtaques();
        vector<int>& getExperienciaProxNivel();

        void serializarInfo(ofstream& out) const;
        void deserializarInfo(ifstream& in);

        //destructor
        ~PokemonInfo() = default;
};


