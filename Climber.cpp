#include "Climber.h"

Climber::Climber(){};

void Climber::Tangle(){
climber_m.Set(climberup_); 
    
}

void Climber::Untangle(){
climber_m.Set(climberdown_*-1);   

}
