#pragma once 
#include <string>

using namespace std;

class Pokemon{
    private:
        string nombre;
        int experiencia;
    
    public:
        //constructor
        Pokemon(const string nombre_, int experiencia_);
        
        //getters
        string getNombre() const;
        int getExperiencia() const;
        
        //sobrecarga del operador ==
        bool operator==(const Pokemon& other)const;

        //serializar y deserializar
        void serializarPoke(ofstream& out) const;
        void deserializarPoke (ifstream& in);
        
        //destructor
        ~Pokemon()= default;
};

