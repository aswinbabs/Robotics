// ROBOTICS
//Here is a connection for a robot having Arduino, two- servo motors , The program will manage to control the orentation of motor



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
    digitalWrite(motor1_EN, HIGH);
    
    digitalWrite(motor2_IN1, HIGH);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  F/W
    digitalWrite(motor2_EN, HIGH);
    delay(3000);
  }

  

  //ROBOT B/W
   
   else if(input == 'x')
  {
    Serial.println("MOVING B/W");

    digitalWrite(motor1_IN1, HIGH);  //MOTOR 1  B/W
    digitalWrite(motor1_IN2, LOW);
    digitalWrite(motor1_EN, HIGH);
    

    digitalWrite(motor2_IN1, LOW);  //MOTOR 2  B/W
    digitalWrite(motor2_IN2, HIGH);
    digitalWrite(motor2_EN, HIGH);
    delay(3000);
  }

  //ROBOT LEFT
  
  else if(input == 'a')
  {
    Serial.println("MOVING LEFT");

    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, HIGH);  //MOTOR 1  
    digitalWrite(motor1_EN, HIGH);
    
    digitalWrite(motor2_IN1, LOW);
    digitalWrite(motor2_IN2, HIGH);  //MOTOR 2   
    digitalWrite(motor2_EN, HIGH);
    delay(3000);
  }

  //ROBOT RIGHT

  else if(input == 'd')
  {
    Serial.println("MOVING RIGHT");

    digitalWrite(motor1_IN1, HIGH);
    digitalWrite(motor1_IN2, LOW);  //MOTOR 1   
    digitalWrite(motor1_EN, HIGH);
    
    digitalWrite(motor2_IN1, HIGH);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  
    digitalWrite(motor2_EN, HIGH);
    delay(3000);
  }

  //IDLE OFF

  else
  {
    Serial.println("OFF");

    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);  //MOTOR 1  OFF
    digitalWrite(motor1_EN, LOW);
    
    digitalWrite(motor2_IN1, LOW);
    digitalWrite(motor2_IN2, LOW);  //MOTOR 2  OFF
    digitalWrite(motor2_EN, LOW);
    delay(3000);
  }
  

  }
  

}


