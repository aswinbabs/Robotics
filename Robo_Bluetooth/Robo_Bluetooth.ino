// ROBOTICS
//Here is a connection for a robot having Arduino, two- servo motors , The program will manage to control the orentation of motor

//Controls the robot using Application using Bluetooth(HC-05 module)        from Playstore/ Serial Bluetooth terminal

/*  Bluetooth module connection
     RXD - D1
     TXD - D0
     GND - GND
     VCC - VCC
*/



/*
IN1    IN2    OUTPUT

0       0      OFF
0       1      F/W
1       0      B/W
1       1      0FF


*/

const int motor1_IN1 = A0;   //servo motor 1
const int motor1_IN2 = A1;
const int motor1_EN = 5;

const int motor2_IN1 = A2;    //servo motor 2
const int motor2_IN2 = A3;
const int motor2_EN = 6;

void setup()
{
  //INIT MOTOR 1
  pinMode(motor1_IN1, OUTPUT);  
  pinMode(motor1_IN2, OUTPUT);
  pinMode(motor1_EN, OUTPUT);

  //INIT MOTOR 2
  pinMode(motor2_IN1, OUTPUT);
  pinMode(motor2_IN2, OUTPUT);
  pinMode(motor2_EN, OUTPUT);

  delay(1000);

  Serial.begin(9600);
}

void loop()
{ 
  
  if(Serial.available())
  {
  char input = Serial.read();

   
  //ROBOT F/W

  if(input == 'w')
  {
    Serial.println("MOVING F/W");

    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, HIGH);  //MOTOR 1  F/W
    analogWrite(motor1_EN, 75);
    
    digitalWrite(motor2_IN1, HIGH);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  F/W
    analogWrite(motor2_EN, 75);
    delay(3000);
    Serial.println("OFF");
  }

  

  //ROBOT B/W
   
   else if(input == 'x')
  {
    Serial.println("MOVING B/W");

    digitalWrite(motor1_IN1, HIGH);  //MOTOR 1  B/W
    digitalWrite(motor1_IN2, LOW);
    analogWrite(motor1_EN, 75);
    

    digitalWrite(motor2_IN1, LOW);  //MOTOR 2  B/W
    digitalWrite(motor2_IN2, HIGH);
    analogWrite(motor2_EN, 75);
    delay(3000);
    Serial.println("OFF");
  }

  //ROBOT LEFT
  
  else if(input == 'a')
  {
    Serial.println("MOVING LEFT");

    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, HIGH);  //MOTOR 1  
    analogWrite(motor1_EN, 75);
    
    digitalWrite(motor2_IN1, LOW);
    digitalWrite(motor2_IN2, HIGH);  //MOTOR 2   
    analogWrite(motor2_EN, 75);
    delay(3000);
    Serial.println("OFF");
  }

  //ROBOT RIGHT

  else if(input == 'd')
  {
    Serial.println("MOVING RIGHT");

    digitalWrite(motor1_IN1, HIGH);
    digitalWrite(motor1_IN2, LOW);  //MOTOR 1   
    analogWrite(motor1_EN, 75);
    
    digitalWrite(motor2_IN1, HIGH);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  
    analogWrite(motor2_EN, 75);
    delay(3000);
    Serial.println("OFF");
  }

  //IDLE OFF

  else
  {
    Serial.println("Press Button"); //w- f/w  ,  x- b/w  , a- left ,  d-right

    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);  //MOTOR 1  OFF
    analogWrite(motor1_EN, 75);
    
    digitalWrite(motor2_IN1, LOW);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  OFF
    analogWrite(motor2_EN, 75);
    delay(3000);
  }
  

  }
  

}


