#include <VictorSP.h>
#include <Solenoide.h>

class Chasis{
    
    private:
    //Puertos
    Joystick control{0};  
    VictorSP m_frontderecho{ 0 };
    VictorSP m_frontizquierdo{ 1 };
    VictorSP m_rearderecho{ 2 };
    VictorSP m_rearizquierdo{ 3 };
    SpeedControllerGroup m_derecho{m_frontderecho, m_rearderecho};
    SpeedControllerGroup m_izquierdo{m_frontizquierdo,m_rearizquierdo};
    //Drivetrain
    DifferentialDrive chasis{m_derecho, m_izquierdo};
    //.get
    float axisY = -control.GetRawAxis(1)*0.7; 
    float axisX = control.GetRawAxis(0)*0.7; 
    public:
    
        Chasis(){};
        void Move(); 
        void TurnRight();
        void TurnLeft(); 
        void TelepMove(); //Movement based on Control
        void Stop();
}