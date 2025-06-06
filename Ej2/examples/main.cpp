#include "../headers/drone.hpp"
#include <thread>
#include <memory>
using namespace std;

int main(){

    unique_ptr<Drone> drone1 = make_unique<Drone> ("Drone1");
    unique_ptr<Drone> drone2 = make_unique<Drone> ("Drone2");

    // Drone drone1("Drone1");
    // Drone drone2("Drone2");
    // Drone drone3("Drone3");
    // Drone drone4("Drone4");
    // Drone drone5("Drone5");
   
    vector<unique_ptr<Drone>> drones;
    drones.push_back(std::move(drone1));
    drones.push_back(std::move(drone2));
    // drones.push_back(drone3);
    // drones.push_back(drone4);
    // drones.push_back(drone5);

    vector<std::jthread> threads;

    for (int i = 0; i<2; i++){
        threads.emplace_back(volar, ref(drones[i]), i);
    }

    // for(auto& t: threads){
    //     t.join();
    // }

    return 0;
}