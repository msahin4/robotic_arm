#include <Servo.h>

Servo servoAlt;
Servo servoSag;
Servo servoSol;
Servo servoGripper;

void setup() {
  // put your setup code here, to run once:
servoAlt.attach(6); //110
servoSag.attach(7); //90
servoSol.attach(8); //70
servoGripper.attach(9);//30


defaultPosition();

Serial.begin(9600);
}



void loop() {
  
  if (Serial.available() > 0) {
    String komut = Serial.readStringUntil('\n'); 

    if (komut == "moveBlackBox") {
      moveBlackBox(); 
    } else if (komut == "moveOrangeBox") {
      moveOrangeBox(); 
    }
  }
  
}

void moveBlackBox () {
    
  int i;

  for (i=90;i<=110;i++){
    servoSag.write(i);
    delay(40);
    }  
  for (i=70;i>=35;i--){
    servoSol.write(i);
    delay(40);
    }
  for (i=110;i<=135;i++){
    servoSag.write(i);
    delay(40);
    } 
  for (i=35;i<=53;i++){
    servoSol.write(i);
    delay(40);
    }
  for (i=135;i<=140;i++){
    servoSag.write(i);
    delay(40);
    } 

servoGripper.write(0);
delay(500);
  for (i=53;i<=70;i++){
    servoSol.write(i);
    delay(40);
    }

  for (i=142;i>=90;i--){
    servoSag.write(i);
    delay(40);
    } 

  for (i=110;i>=57;i--){
    servoAlt.write(i);
    delay(40);
    }


  for (i=90;i<=145;i++){
    servoSag.write(i);
    delay(40);
    } 

  for (i=70;i>=40;i--){
    servoSol.write(i);
    delay(40);
    }

servoGripper.write(20);
delay(500);
  for (i=40;i>=15;i--){
    servoSol.write(i);
    delay(40);
    }

defaultPosition(); 
}







void moveOrangeBox(){
  
  int i;

  for (i=90;i<=110;i++){
    servoSag.write(i);
    delay(40);
    }  
  for (i=70;i>=35;i--){
    servoSol.write(i);
    delay(40);
    }
  for (i=110;i<=135;i++){
    servoSag.write(i);
    delay(40);
    } 
  for (i=35;i<=53;i++){
    servoSol.write(i);
    delay(40);
    }
  for (i=135;i<=140;i++){
    servoSag.write(i);
    delay(40);
    } 

servoGripper.write(0);
delay(500);

  for (i=53;i<=70;i++){
    servoSol.write(i);
    delay(40);
    }

  for (i=142;i>=90;i--){
    servoSag.write(i);
    delay(40);
    } 

  for (i=110;i>=15;i--){
    servoAlt.write(i);
    delay(40);
    }
    

  for (i=90;i<=145;i++){
    servoSag.write(i);
    delay(40);
    } 

  for (i=70;i>=40;i--){
    servoSol.write(i);
    delay(40);
    }

servoGripper.write(20);
delay(500);
  for (i=40;i>=15;i--){
    servoSol.write(i);
    delay(40);
    }

defaultPosition();
}


void defaultPosition() {
  

servoAlt.write(100);
delay(1000);


servoSag.write(90);
delay(1000);


servoSol.write(70);
delay(1000);

servoGripper.write(30);
delay(1000);

}
