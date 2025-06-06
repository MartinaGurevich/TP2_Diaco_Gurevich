#include "../includes/drone.hpp"
using namespace std;


std:: mutex m2; //para los cout

void volar(Drone& drone, vector<int> disponibilidad, int i){
    while(true){

        drone.m1.lock(); //accede al mutex de struct Drone
        if(i==0){
            if(disponibilidad[-1] == 1 && disponibilidad[i+1] == 1){
                while(true){
                    if(m2.try_lock()){
                        cout<<drone.nombre<<" despegando..."<<endl;
                        disponibilidad[i]= 0;
                        m2.unlock();
                        this_thread::sleep_for(chrono::seconds(5));
                        disponibilidad[i]= 1;
                        while(true){
                            if(m2.try_lock()){
                            cout<<drone.nombre<<" Altura de 10 metros."<<endl;
                            m2.unlock();
                            break;
                            }
                        break;
                        }
                    } else cout<<drone.nombre<<" esperando para despegar... "<<endl;
            }
        }
    }
        if(i==4){
            if(disponibilidad[i-1] == 1 && disponibilidad[0] == 1){  
                while(true){
                    if(m2.try_lock()){
                        cout<<drone.nombre<<" despegando..."<<endl;
                        disponibilidad[i]= 0;
                        m2.unlock();
                        this_thread::sleep_for(chrono::seconds(5));
                        disponibilidad[i]= 1;
                        while(true){
                            if(m2.try_lock()){
                            cout<<drone.nombre<<" Altura de 10 metros."<<endl;
                            m2.unlock();
                            break;
                            }
                        break;
                        }
                    } else cout<<drone.nombre<<" esperando para despegar... "<<endl;
            } 
        }
    }
        if(disponibilidad[i-1] == 1 && disponibilidad[i+1] == 1){
            while(true){
                if(m2.try_lock()){
                    cout<<drone.nombre<<" despegando..."<<endl;
                    disponibilidad[i]= 0;
                    m2.unlock();
                    this_thread::sleep_for(chrono::seconds(5));
                    disponibilidad[i]= 1;
                    while(true){
                        if(m2.try_lock()){
                        cout<<drone.nombre<<" Altura de 10 metros."<<endl;
                        m2.unlock();
                        break;
                        }
                    break;
                    }
                } else cout<<drone.nombre<<" esperando para despegar... "<<endl;
            }
       
        }
    }

}