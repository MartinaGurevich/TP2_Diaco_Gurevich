#include "../headers/despegue.hpp"
#include <thread>
#include <memory>
using namespace std;

int main(){

    // vector<jthread> threads;
    Despegue despegue;
    despegue.simulador();

    // for (int i = 0; i < ZONAS; i++){
    //     //CAMBIAR
    //     threads.emplace_back([&despegue, i]() {
    //         despegue.volar(i);  // Método no estático
    //     });

    // }
    return 0;
}