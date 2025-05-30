#include "../headers/pokemonInfo.hpp"
#include <string>

using namespace std;

//constructores
PokemonInfo::PokemonInfo() //este constructor es necesario para poder agregar nuevos (key, value) al unordered_map
    :tipo(""), descripcion(""), ataques(), experienciaProxNivel() {}

PokemonInfo::PokemonInfo(const string tipo_, const string descripcion_, 
        unordered_map<string, int> ataques_,
        vector<int> experienciaProxNivel_):
        
        tipo(tipo_), 
        descripcion(descripcion_), 
        ataques(ataques_),
        experienciaProxNivel(experienciaProxNivel_){};

PokemonInfo::PokemonInfo(const PokemonInfo& other):
        tipo(other.tipo), 
        descripcion(other.descripcion), 
        ataques(other.ataques),
        experienciaProxNivel(other.experienciaProxNivel) {}


//getters
string PokemonInfo::getTipo() const{
    return tipo;
}

string PokemonInfo::getDescripcion() const{
    return descripcion;
}

unordered_map<string, int>& PokemonInfo::getAtaques(){
    
    return ataques;
}

vector<int>& PokemonInfo::getExperienciaProxNivel(){
    return experienciaProxNivel;
} 


void PokemonInfo::serializarInfo(ofstream& out) const {
  
    //serializo el tipo
    size_t tipoSize = tipo.size();
    out.write(reinterpret_cast<const char*>(&tipoSize), sizeof(tipoSize));
    out.write(tipo.c_str(), tipoSize);

    //serializo la descripcion
    size_t descripcionSize = descripcion.size();
    out.write(reinterpret_cast<const char*>(&descripcionSize), sizeof(descripcionSize));
    out.write(descripcion.c_str(), descripcionSize);

    //serializo ataques
    size_t mapSize = ataques.size();
    out.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));
    
    for(const auto& ataque_daño: ataques){
        //serializo key
        size_t keySize = ataque_daño.first.size();
        out.write(reinterpret_cast<const char*>(&keySize), sizeof(keySize));
        out.write(ataque_daño.first.c_str(), keySize);

        //serializo value
        out.write(reinterpret_cast<const char*>(&ataque_daño.second), sizeof(ataque_daño.second));

    }

    //serializo experiencia para el proximo nivel
    size_t expSize = experienciaProxNivel.size();
    out.write(reinterpret_cast<char*>(&expSize), sizeof(expSize));
    out.write(reinterpret_cast<char*>(const_cast<int*>(experienciaProxNivel.data())), expSize*sizeof(int));
}

void PokemonInfo::deserializarInfo(ifstream& in) {
    //deserializo el tipo
    size_t tipoSize = tipo.size();
    in.read(reinterpret_cast<char*>(&tipoSize), sizeof(tipoSize));
    string tipo_ = string(tipoSize, '\0');
    in.read(&(tipo_)[0], tipoSize); 

    //deserializo la descripcion
    size_t descripcionSize = descripcion.size();
    in.read(reinterpret_cast<char*>(&descripcionSize), sizeof(descripcionSize));
    string descripcion_ = string(descripcionSize, '\0');
    in.read(&(descripcion_)[0], descripcionSize); 

    //deserializo ataques
    for(auto& ataque_daño: ataques){
        //deserializo key
        size_t keySize = ataque_daño.first.size();
        in.read(reinterpret_cast<char*>(&keySize), sizeof(keySize));
        string key_ = string(keySize, '\0');
        in.read(&(key_)[0], keySize); 

        //deserializo value
        in.read(reinterpret_cast<char*>(&ataque_daño.second), sizeof(ataque_daño.second));

    }

    //deserializo experiencia para el proximo nivel
    size_t expSize;
    in.read(reinterpret_cast<char*>(&expSize), sizeof(expSize));
    experienciaProxNivel.resize(expSize);
    in.read(reinterpret_cast<char*>(experienciaProxNivel.data()), expSize*sizeof(int));
}