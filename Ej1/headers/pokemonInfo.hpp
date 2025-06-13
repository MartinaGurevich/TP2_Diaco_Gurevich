#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;


class PokemonInfo{
    private:
        string tipo;
        string descripcion;
        unordered_map<string, int> ataques;
        vector<int> experienciaProxNivel;

    public:
        //constructor
        PokemonInfo();
        PokemonInfo(const string tipo_, const string descripcion_, 
           unordered_map<string, int> ataques_,
           vector<int> experienciaProxNivel_
        );
        
        //getters
        string getTipo() const;
        string getDescripcion() const;
        unordered_map<string, int>& getAtaques();
        vector<int>& getExperienciaProxNivel();

        //serializar y deserializar
        void serializarInfo(ofstream& out) const;
        void deserializarInfo(ifstream& in);

        //destructor
        ~PokemonInfo() = default;
};


