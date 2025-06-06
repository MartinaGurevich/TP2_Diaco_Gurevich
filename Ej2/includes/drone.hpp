#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
using namespace std;

struct Drone{
    const string& nombre;
    std::mutex m1;

    Drone(const string& nombre);
    
};

void volar(Drone& drone, vector<int> disponibilidad, int i);