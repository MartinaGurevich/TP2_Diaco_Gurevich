#include "../includes/drone.hpp"
#include <thread>
using namespace std;

int main(){

    Drone drone1("Drone1");
    Drone drone2("Drone2");
    Drone drone3("Drone3");
    Drone drone4("Drone4");
    Drone drone5("Drone5");
   
    vector<Drone> drones;
    drones.push_back(drone1);
    drones.push_back(drone2);
    drones.push_back(drone3);
    drones.push_back(drone4);
    drones.push_back(drone5);

    vector<std::jthread> threads;

    for (int i = 0; i<5; i++){
        threads.emplace_back(volar, drones[i], i);
    }

    // for(auto& t: threads){
    //     t.join();
    // }

    return 0;
}