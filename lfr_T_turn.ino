int ir1 = 2;
int ir2 = 3;
int ir3 = 4;
int ir4 = 5;
int ir5 = 6;
int ir6 = 11;
int ir7 = 12;

int lm1 = 9;
int lm2 = 7;
int rm1 = 10;
int rm2 = 8;
int c = 0;
int s = 205;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if ((!digitalRead(ir1) || !digitalRead(ir2)) && (!digitalRead(ir4) || !digitalRead(ir5)))    // Code for T turn
  {
    if (c % 2 == 0)
    {
      while (digitalRead(ir3))
      { 
        Serial.println("Right turn");
        analogWrite(lm1, s);
        analogWrite(lm2, 0);
        analogWrite(rm1, 0);
        analogWrite(rm2, 0);
      }
    }
    else
    {
      while (digitalRead(ir3))
      {
        Serial.println("Left turn");
        analogWrite(lm1, 0);
        analogWrite(lm2, 0);
        analogWrite(rm1, s);
        analogWrite(rm2, 0);
      }
    }
    c = 0;
  }
  else if (!digitalRead(ir3))
  {
    Serial.print("F    c = ");
    Serial.println(c);
    analogWrite(lm1, s);
    analogWrite(lm2, 0);
    analogWrite(rm1, s);
    analogWrite(rm2, 0);
  }
  else
  {
    if (!digitalRead(ir2) || !digitalRead(ir1))
    {
      Serial.println("L");
      analogWrite(lm1, 0);
      analogWrite(lm2, 0);
      analogWrite(rm1, s);
      analogWrite(rm2, 0);
    }
    else if (!digitalRead(ir4) || !digitalRead(ir5))
    {
      Serial.println("R");
      analogWrite(lm1, s);
      analogWrite(lm2, 0);
      analogWrite(rm1, 0);
      analogWrite(rm2, 0);
    }
    else
    {
      c++;
      while ( digitalRead(ir1) && digitalRead(ir2) && digitalRead(ir3) && digitalRead(ir4) &&  digitalRead(ir5) == 1)
      {
        if (!digitalRead(ir6))
        {
          c--;
          while (digitalRead(ir3))
          {
            Serial.println("6 Left");
            analogWrite(lm1, 0);
            analogWrite(lm2, 0);
            analogWrite(rm1, s);
            analogWrite(rm2, 0);
          }
        }
        else if (!digitalRead(ir7))
        {
          c--;
          while (digitalRead(ir3))
          {
            Serial.println("7 RIght");
            analogWrite(lm1, s);
            analogWrite(lm2, 0);
            analogWrite(rm1, 0);
            analogWrite(rm2, 0);
          }
        }
        else
        {
          Serial.print("fwd      c = ");
          Serial.println(c);
          analogWrite(lm1, s);
          analogWrite(lm2, 0);
          analogWrite(rm1, s);
          analogWrite(rm2, 0);
        }
      }
    }
  }
}
