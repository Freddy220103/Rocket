#include <VictorSP.h>

class Climber{
    private:
        Joystick control{0};  
        VictorSP climberm_{5};
        float climberup_ = control.GetRawAxis(3); 
        float climberdown_ = control.GetRawAxis(2);  
    
    public:
    
        Elevator(){};
        void Tangle(); //Retrae la cuerda haciendo que el robot suba
        void Untangle();//Desenreda la cuerda para que el robot baje
    
}