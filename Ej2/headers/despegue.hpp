#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#define ZONAS 5
using namespace std;

class Despegue{
    private:
        //vector de zonas
        mutex zonas[ZONAS]; //array de mutex para proteger las zonas
        mutex m2; //mutex para proteger las impresiones por pantalla

    public:
        //constructor
        Despegue() = default;

        //metodos
        void volar(int i);

        //destructor
        ~Despegue() = default;

};