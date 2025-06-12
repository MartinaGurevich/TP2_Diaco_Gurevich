#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <chrono>
#include <string>
using namespace std;

mutex mtx;
condition_variable condicionEsperada;
bool terminado = false;
int sensores_terminados = 0;
const int NUM_SENSORES = 3;
const int NUM_ROBOTS = 3;


struct Tarea{
    int idSensor;
    int idTarea;
    string descripcionTarea;
    Tarea(int idSensor_,  int idTarea_, string descripcionTarea_){
        idSensor = idSensor_;
        idTarea = idTarea_;
        descripcionTarea = descripcionTarea_;
    }
};

queue<Tarea> cola; //cola de tareas 

void Sensor(int idSensor){
    for(int i = 1; i <= 3; ++i){
        {
        lock_guard<mutex> lock(mtx);
        Tarea tarea(idSensor, idSensor*10 +i,"Tarea "+to_string(idSensor*10 +i)+ " fue creada.");
        cola.push(tarea);
        cout<<"[Sensor "<< idSensor<<"] "<< tarea.descripcionTarea<<endl; 

        }
        
        condicionEsperada.notify_all(); //se notifica que el sensor agrego tarea a la cola
        this_thread::sleep_for(chrono::milliseconds(175)); //lo que tarda en ser creada 

    }
    {
    lock_guard<mutex> lock(mtx);
    sensores_terminados++;
    if (sensores_terminados == NUM_SENSORES) {
        terminado = true;
        condicionEsperada.notify_all(); // Se notifica que terminó el ultimo sensor.
        }
    }

}

void Robot( int idRobot){
    while(true){
        unique_lock<mutex> lockUnique(mtx);
        condicionEsperada.wait(lockUnique, [] { return !cola.empty() || terminado; }); //espero que llegue el notify
        if (!cola.empty()) { // Si hay productos en la cola…
            Tarea tarea = cola.front();
            cola.pop();
            cout << "[Robot " << idRobot << "] Ejecutando Tarea " << tarea.idTarea << endl;
            lockUnique.unlock(); // Para que la cola se use en produccion
            this_thread::sleep_for(chrono::milliseconds(250));

        }else if (terminado) // Salir si no hay elementos y…
            break; //… ya terminó la producción
        }
    cout << "Robot "<<idRobot<<" ha finalizado sus tareas.\n";
    }


int main() {
    vector<jthread> sensores;
    for (int i = 0; i < NUM_SENSORES; ++i)
        sensores.emplace_back(Sensor, i + 1);
    
    vector<jthread> robots;
    for (int i = 0; i < NUM_ROBOTS; ++i)
        robots.emplace_back(Robot, i + 1);
    return 0;
}