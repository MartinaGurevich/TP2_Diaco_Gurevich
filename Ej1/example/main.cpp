#include "../headers/pokedex.hpp"

int main(){
   //creo pokedex y cargo el archivo
    Pokedex pokedex("pokedex.dat");

    //pokemon1
    Pokemon p1("Squirtle", 100);
    PokemonInfo info1("Agua", "Una tortuga pequeña que lanza chorros de agua.",  
                        {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}}, 
                        {0, 400, 1000});

    //pokemon 2
    Pokemon p2("Bulbasaur", 270); 
    PokemonInfo info2("Planta", "Tiene una semilla en su lomo que crece con el tiempo", 
                        {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}}, 
                        {0, 300, 1100});

    //pokemon 3
    Pokemon p3("Charmander", 633); 
    PokemonInfo info3("Fuego", "Una lagartija con una llama en su cola", 
                        {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}}, 
                        {0, 250, 1300});
    
    //agrego pokemons al pokedex
    cout<<"\nAgregando Pokemons al Pokedex..."<<endl;
    pokedex.agregarPokemon(p1, info1);
    pokedex.agregarPokemon(p2, info2);
    pokedex.agregarPokemon(p3, info3);

    cout<<"\ngregando Pokemon repetido..."<<endl;
    pokedex.agregarPokemon(p1, info1); //pokemon repetido

    //muestro pokemons
    cout<<"\nMostrando un Pokemon..."<<endl;
    pokedex.mostrar(p1);

    //muestro todos los pokemons
    cout<<"\nMostrando todos los Pokemons..."<<endl;
    pokedex.mostrarTodos();

    //eliminar pokemon
    cout<<"\nEliminando un Pokemon..."<<endl;
    pokedex.eliminarPokemon(p2);

    //mostrar pokemon eliminado
    cout<<"\nMostrando Pokemon eliminado..."<<endl;
    pokedex.mostrar(p2);

    //descargo el archivo
    Pokedex pokedex2("pokedex.dat");
    pokedex2.descargarArchivo();
    cout<<"\n=== Pokedex descargado desde el archivo ===\n";
    pokedex2.mostrarTodos();
    return 0;
}


/*
IMPORTANTE -->
notyfy_one() notify_all() --> si hay thr dormidos notify one depierta un thr , notyfyall dspierta todos

cuando imprimimos --> hay que ver que se imprima todo bien --> ponemos otro mutex, imprime y lo libera asi no se pisa
*/