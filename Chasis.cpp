#include "Chasis.h"

Chasis::Chasis(){};

void Chasis::Move(){
    chasis.ArcadeDrive(0.7,0); 

}

void Chasis::TurnLeft(){
    chasis.ArcadeDrive(0,-0.4);

}

void Chasis::TurnRight(){
    chasis.ArcadeDrive(0,0.4); 
}

void Chasis::TelepMove(){
chasis.ArcadeDrive(ejeY,ejeX); 

}

void Chasis::Stop(){
chasis.ArcadeDrive(0,0)    
}