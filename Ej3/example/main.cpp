#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <chrono>
#include <string>
#include <atomic> 
using namespace std;

struct Tarea{
    int idSensor;
    int idTarea;
    string descripcionTarea;

    //constructor
    Tarea(int idSensor_,  int idTarea_, string descripcionTarea_)
        :idSensor(idSensor_), idTarea(idTarea_), descripcionTarea(descripcionTarea_){}

};


int sensores_terminados = 0; //contador para llevar registro de aquellos sensores que terminan de realizar tareas
const int NUM_SENSORES = 3;
const int NUM_ROBOTS = 3;

mutex mtx;
condition_variable condicionEsperada;

bool terminado = false;
atomic_int contadorTareas(1); //variable átomica para utilizar como IdTarea.

queue<Tarea> cola; //cola de tareas 


void Sensor(int idSensor){
    //bucle que genera tareas y las agrega a la cola
    for(int i = 1; i <= 3; ++i){
        
        //creamos un scope tal que el lock guar se desbloquea
        //automaticamente al salir de él
        {
            lock_guard<mutex> lock(mtx);
            //cramos la tarea
            Tarea tarea(idSensor, contadorTareas,"Tarea " + to_string(contadorTareas));
            ++contadorTareas; //aumentamos el numero de tarea
            cola.push(tarea); //agrego tarea a la cola
            
            cout<<"[Sensor "<< idSensor<<"] "<<tarea.descripcionTarea<<" fue creada."<<endl; 
        }
        
        condicionEsperada.notify_all(); //se notifica que el sensor termino de agregar tareas a la cola
        this_thread::sleep_for(chrono::milliseconds(175)); //tiempo de creacion de la tarea

    }
    
    {
        lock_guard<mutex> lock(mtx);
        sensores_terminados++; //incremento el contador de sensores que terminaron de generar tareas
        
        //en el caso de que todos los sensores hayn terminado, se lo notifica a los robots
        if (sensores_terminados == NUM_SENSORES) {
            terminado = true;
            condicionEsperada.notify_all(); // Se notifica que terminó el ultimo sensor.
        }
    }

}

void Robot( int idRobot){
    //Mientras que haya sensores agregando tareas...
    while(true){
        unique_lock<mutex> lockUnique(mtx);

        //el robot espera a que haya algo en la cola, o que los sensores hayan terminado
        condicionEsperada.wait(lockUnique, [] { return !cola.empty() || terminado; });
        
        //En el caso que haya productos en la cola --> se ejecuta la primer tarea en espera
        if (!cola.empty()) {
            Tarea tarea = cola.front(); //accedemos a la tarea
            cola.pop();
            cout << "[Robot " << idRobot << "] Ejecutando Tarea " << tarea.idTarea << endl;
            lockUnique.unlock();
            
            this_thread::sleep_for(chrono::milliseconds(250)); //tiempo de procesamiento de la tarea

        }else if (terminado) break; //se rompe el ciclo cuando lo sensores terminaron
    }
    
    cout << "Robot "<<idRobot<<" ha finalizado sus tareas."<<endl;
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