#pragma once 
#include <string>

using namespace std;

class Pokemon
{
private:
    string nombre;
    int experiencia;
public:
    Pokemon(string nombre, int experiencia);
    void getNombre();
    void getExperiencia();
    ~Pokemon()= default;
};

