 const int zpin = A3;
const int ypin = A2;
const int xpin = A1;
int calibrate = 0;
int x_right, x_left;
int y_back, y_front;
const int volt = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(volt, OUTPUT);
  digitalWrite(volt, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  int x = analogRead(xpin);
  int y = analogRead(ypin);
  int z = analogRead(zpin);
  if (calibrate == 0)
  { delay(3000);
    x = analogRead(xpin);
    y = analogRead(ypin);
    z = analogRead(zpin);
    x_right = x - 15;
    x_left = x + 15;
    y_back = y - 15;
    y_front = y + 15 ;
    calibrate = 1;
  }
  else
  { if (x <= x_right)
      Serial.write("r");
    else if (x >= x_left)
      Serial.write("l");
    else if (y >= y_front)
      Serial.write("f");
    else if (y <= y_back)
      Serial.write("b");
    else Serial.write("s");

    delay(100);

  }

  
}
