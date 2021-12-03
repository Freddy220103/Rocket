#include <Solenoide.h>

class Claw{
    
    private:
       Joystick control{0};  
       DoubleSolenoid garrita { 4, 5 };
       DoubleSolenoid muneca { 1 , 2 };
    
    public:
    
        Claw(){};
        void Open(); //Abrir garra
        void Close(); //Cerrar garra
        void Retract(); //Retrae\Sube la garra
        void Expand();//Baja la garra
        void Off();
}