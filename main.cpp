#include <IterativeRobot.h>
#include <RobotDrive.h>
#include <WPILib.h>
#include <VictorSP.h>
#include <drive/DifferentialDrive.h>
#include <Solenoid.h>
#include <Joystick.h>
#include <CameraServer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <SpeedControllerGroup.h>
#include <Timer.h>
#include <Encoder.h>

#include "Claw.h"
#include "Elevator.h"
#include "Climber.h"
#include "Chasis.h"

using namespace frc;

class Robot: public IterativeRobot {
  public:
      Robot() { };

  private:
    Chasis drivetrain;
    Claw claw;
    Elevator elevator;
    Climber climber;
    Timer timer;
    Encoder encoder {0,3};//Encoder para chasis
    Encoder encodelev {4};//Encoder para elevador
    Joystick control{0}; 

    void RobotInit() {
      CameraServer::GetInstance()->StartAutomaticCapture();
      cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
      camera.SetResolution(640, 480);
      encoder.SetDistancePerPulse(1./256.);
      encodelev.SetDistancePerPulse(1./256.);
    }

    void AutonomousInit() override {
      claw.Expand();
    }

    void AutonomousPeriodic() override {
      if(encoder.GetDistance < 13) { //13foot
        drivetrain.Move();
      }
      else if (encoder.GetDistance < 13.5) {
        drivetrain.TurnRight();
        //chasis.TurnLeft();
        if(encodelev.GetDistance<2){
        elevator.Up(); 
        }
        else{
        claw.Open(); 
        }
      else{
      drivetrain.Stop();
      }
    }
     /* AUTONOMO POR TIEMPO
     Aqui no hay tiempo exacto  por el tanteo
      float seconds = timer.Get(); //Segundos pasados de autónomo
      if(seconds<1){
        claw.Expand();
        drivetrain.Move(); 
      //Robot moves forward during second 0 and 1 at a speed of 70%
      }
      else if(seconds<2){ 
        drivetrain.TurnRight(); 
      //Robot turns right during second 1 and 2 at a speed of 40%
      }
      
      //IF ROBOT TURNS LEFT:
      //drivetrain.TurnLeft()
      
      else if(seconds<2.2){
        elevator.Up();
      }
      //elevator goes up during sec 2 and 2.5 sec at 30% speed
      
      else if(seconds<2.4){
        claw.Open();
        drivetrain.Move();
      } 

      else{
        drivetrain.Stop();
      }
      */

      }

    void TeleopInit() override {
        claw.Off();

        }

   void TeleopPeriodic() override {
          
    //CHASIS
    drivetrain.TelepMove();
    //ELEVATOR
    elevator.TelepElev();

    //CLAW
    if(control.GetRawButton(0)) {
      claw.Open() //Estirar pistón
      }
    
    else if(control.GetRawButton(1)){
    claw.Close(); //Contraer pistón
     }
  
    else if(control.GetRawButton(2)){
    claw.Retract(); 
    }
  
    else if(control.GetRawButton(3)){
    claw.Expand(); 
     }
    else{ 
    claw.Off();
    }

    //CLIMBER
    climber.Tangle()
    climber.Untangle()

    }
//Written by Fredy Gómez
}



