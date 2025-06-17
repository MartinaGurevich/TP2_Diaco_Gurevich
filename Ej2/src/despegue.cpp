#include "../headers/despegue.hpp"
using namespace std;


void Despegue::volar(int i){
    //establecemos las zonas a bloquear
    mutex& izq = zonas[i];
    mutex& der = zonas[(i+1) % ZONAS];

    m2.lock();
    cout<<"Drone "<<i<<" esperando para despegar..."<<endl;
    m2.unlock();
    
    lock(izq, der); //bloqueamos las zonas adyacentes. Si no se puede bloquear, espera hasta que se liberen ambas zonas
    //una vez bloqueadas, se desbloquean en el orden correcto para evitar deadlocks
    
    m2.lock();
    cout<<"Drone "<<i<<" despegando..."<<endl;
    m2.unlock();
    
    this_thread::sleep_for(chrono::seconds(5)); //tiempo de vuelo hasta alcanzar los 10m
    
    m2.lock();
    cout<<"Drone "<<i<<" alcanzo los 10 metros de altura."<<endl;
    m2.unlock();
    
    
    izq.unlock(); der.unlock();

}

