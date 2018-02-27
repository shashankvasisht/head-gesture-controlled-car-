//L293D
//Motor LEFT MOTOR
const int motorPin1  = 5;  // Pin 2.a 14 of L293
const int motorPin2  = 6;  // Pin 2.b 10 of L293
//Motor RIGHT MOTOR
const int motorPin4  = 9;  // Pin 1.a 2 of L293
const int motorPin3  = 10; // Pin 1.b  7 of L293

const int ground = 7;
const int volt = 8;
const int volt2 = 3;
const int trig=12;
const int echo=11;
long duration,inches,cm;
char data = 0;                //Variable for storing received data
void setup()
{
  Serial.begin(38400);         //Sets the data rate in bits per second (baud) for serial data transmission

  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(volt, OUTPUT);
  digitalWrite(volt, HIGH);
   pinMode(volt2, OUTPUT);
  digitalWrite(volt2, HIGH);
  digitalWrite(ground, LOW);
}
void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  inches = duration/74/2;
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();  //Read the incoming data and store it into variable data
     if(inches<4)
    {   digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, HIGH);
        delay(2000);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        delay(1000);
    }
    else if (data == 108)
    { Serial.print("l");
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }

    else if (data == 114)
    { Serial.print("r");
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      
    }
    else if (data == 102)
    { Serial.print("f");
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
    else if (data == 98)
    { Serial.print("b");
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH );
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }
    
  else if (data == 115)
  { Serial.print("s");
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
  }
      else 
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
  
  }
  }

}
