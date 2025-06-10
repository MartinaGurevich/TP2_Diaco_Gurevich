#include "../headers/pokedex.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//construnctor sobrecargado para serializar
Pokedex::Pokedex(const string& fileName_): fileName(fileName_){
    //descargarArchivo(); //descarga el archivo si existe
}

//metodo privado
void Pokedex::mostrar_(Pokemon& pokemon, PokemonInfo& info) const {
    cout<<"==="<<pokemon.getNombre()<<"==="<<endl;
    cout<<"Tipo: "<<info.getTipo()<<endl;
    cout<<"\""<<info.getDescripcion()<<"\""<<endl;
    cout<<"Experiencia Actual: "<<pokemon.getExperiencia()<<endl;
    cout<<"Ataques disponibles: ";
    for(const auto& ataque : info.getAtaques()){
        cout<<"- " + ataque.first << " (Daño: " << ataque.second << ") ";
    }
    cout<<"\nExperiencia necesaria para cada nivel: Nivel 1: " 
        << info.getExperienciaProxNivel()[0] << ", Nivel 2: "
        << info.getExperienciaProxNivel()[1] <<", Nivel 3: "
        << info.getExperienciaProxNivel()[2] << endl;

}

//metodos
void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info_pokemon, bool serializar) {
    if(info.find(pokemon) != info.end()) {
        cout << "¡Pokemon " << pokemon.getNombre() << " ya está en el Pokedex!" << endl;
        return; // Si el Pokemon ya existe, no lo agregamos
    }
    
    info[pokemon] = info_pokemon;

    //sobreescribo el archivo cada vez que agrego un pokemon
    if(!fileName.empty() && serializar){
        cargarArchivo(); //carga el archivo
        cout<< "¡Pokemon " << pokemon.getNombre() << " agregado al Pokedex!" << endl;
    }

}

void Pokedex::eliminarPokemon(const Pokemon& pokemon) {
    info.erase(pokemon); //Fuenciona pues se cobrecargo el operdor == para Pokemon

    //sobreescribo el archivo cada vez que elimino un pokemon
    if(!fileName.empty()){
        cargarArchivo(); //carga el archivo
    }

    cout<< "¡Pokemon " << pokemon.getNombre() << " eliminado del Pokedex!" << endl;
}

void Pokedex::mostrar(const Pokemon& pokemon)const{
    auto it = info.find(pokemon);
    if(it != info.end()){
        PokemonInfo info_pokemon = it -> second;
        Pokemon pokemon = it -> first;
        
        mostrar_(pokemon, info_pokemon);
    }else
        cout<< "¡Pokemon desconocido!"<<endl;
}

void Pokedex::mostrarTodos()const{
    if(info.empty()){
        cout << "¡Pokedex vacía!" << endl;
        return;
    }
    
    cout<<"======= Pokedex ======="<<endl;
    for(const auto& pokemon_info: info){
        //ver si hacer funcion para no repetir
        PokemonInfo info_pokemon = pokemon_info.second;
        Pokemon pokemon = pokemon_info.first;
        
        cout<<"-----------------------------------"<<endl;
        mostrar_(pokemon, info_pokemon);
    }
}

void Pokedex::cargarArchivo(){
    ofstream out(fileName, ios::binary);
    
    if(out.is_open()){
        size_t infoSize = info.size();
        out.write(reinterpret_cast<const char*>(&infoSize), sizeof(infoSize));
    
        for(const auto& pokemon_info : info){
            pokemon_info.first.serializarPoke(out);
            pokemon_info.second.serializarInfo(out);
        }
        out.close();
    }

    else {
        cerr << "Error al abrir el archivo" << endl;
    }
    
    return;
}

void Pokedex::descargarArchivo() {
    ifstream in(fileName, ios::binary);
    
    if(in.is_open()){
        size_t infoSize;
        in.read(reinterpret_cast<char*>(&infoSize), sizeof(infoSize));

        for(int i = 0; i < infoSize; ++i){
            Pokemon pokemon("", 0); //creamos un pokemon temporal
            PokemonInfo pokemon_info;
            pokemon.deserializarPoke(in);
            pokemon_info.deserializarInfo(in);
            
            agregarPokemon(pokemon, pokemon_info, false); //agregamos al pokedex
        }
        in.close();
    }

    else {
        cerr << "Error al abrir el archivo" << endl;
    }
    
    return;
}

//Hash como functor
size_t PokemonHash::operator()(const Pokemon& pokemon) const {
    return hash<string>()(pokemon.getNombre());
}