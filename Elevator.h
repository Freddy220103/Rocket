#include <VictorSP.h>
class Elevator{
    
    private:
        Joystick control{0};  
        VictorSP elevator_m{4};
        float elevatorup_ = control.GetRawAxis(3); 
        float elevatordown_ = control.GetRawAxis(2);  

    public:
    
        Elevator(){};
        void Up(); //Sube el elevador
        void Down();//Baja el elevador
        void TelepElev();
    
}