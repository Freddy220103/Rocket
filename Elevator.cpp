#include "Elevator.h"

Elevator::Elevator(){};

void Elevator::Up(){
elevator_m.Set(0.4);
    
}

void Elevator::TelepElev(){
elevator_m.Set(elevatorup_-elevatordown_); 
}

void Elevator::Down(){
elevator_m.Set(-0.3)    

}