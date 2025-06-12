#include "../headers/despegue.hpp"
#include <thread>
#include <memory>
using namespace std;

int main(){

    //inicio de simulacion
    Despegue despegue;
    vector<jthread> threads;

    for (int i = 0; i < ZONAS; i++){
        //creamos los hilos representando a cada Drone
        //e inicia la etapa de despegue
        threads.emplace_back(&Despegue::volar, &despegue, i);

    }
    
    return 0;
}