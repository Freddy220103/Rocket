#include "Claw.h"

Claw::Claw(){};

void Claw::Open(){
    garrita.Set(DoubleSolenoid::Value::kForward);
    
}

void Claw::Close(){
    garrita.Set(DoubleSolenoid::Value::kReverse);

}

void Claw::Off(){
    garrita.Set(DoubleSolenoid::Value::kOff);
    muneca.Set(DoubleSolenoid::Value::kOff);
}

void Claw::Retract(){
    muneca.Set(DoubleSolenoid::Value::kReverse);
}

void Claw::Expand(){
    muneca.Set(DoubleSolenoid::Value::kForward);   
}