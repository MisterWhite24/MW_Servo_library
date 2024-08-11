#define SERVO_DEBUG
#define COMUNICATION
//#define SERVO_ISR_SPEEDTEST
#include <MW_Servo_library.h>


SManager *servoManager;
void update(){servoManager->update();}

void setup() 
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("serial ok");

  servoManager = new SManager(update);

  servoManager->addServo(PB_8,180);
  servoManager->addServo(PB_9,180);
  servoManager->begin(1);
}

 uint8_t i = 0;
void loop() 
{
 
  if(!servoManager->getServo(0)->isMoving && i==0)
  {
    servoManager->getServo(0)->jump(0);
    servoManager->getServo(1)->jump(0);
    i=1;
  }
  
  if(!servoManager->getServo(0)->isJump && i==1)
  {
    servoManager->getServo(0)->moveTime(180,9000);
    servoManager->getServo(1)->moveTime(180,5000);
    i=2;
  }
  
  if(!servoManager->getServo(0)->isMoving && i==2)
  {
    servoManager->getServo(0)->move(0,100);
    servoManager->getServo(1)->Stop();
    i=3;
  }

  if(!servoManager->getServo(0)->isMoving && i==3)
  {
    servoManager->getServo(0)->disable();
    servoManager->getServo(1)->disable();
    i=0;
  }
}
