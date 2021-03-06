//  forward=7 backward=8 apportnum=9 left=13 right12 apportnum1=10
  
  int motorA1  = 7;  // Pin  2 of L293
  int motorA2  = 8;  // Pin  7 of L293
  int motorB1  = 13; // Pin 10 of L293
  int motorB2  = 12;  // Pin 14 of L293
  int BTState = 2;
  int state;
  int vspeed=220;     // Default speed, from 0 to 255
  int aportnum=9;
  int aportnum1=10;
  int fullspeed=250;

void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(aportnum,OUTPUT);
    pinMode(aportnum1,OUTPUT);
    pinMode(BTState, INPUT);
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
 //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0)
    {
      state = Serial.read();   
    }
  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') 
    {
      analogWrite(aportnum,fullspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorA1, HIGH);
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') 
    {
      analogWrite(aportnum,vspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorB2, LOW); 
      digitalWrite(motorB1, HIGH);       
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') 
    {
      analogWrite(aportnum,vspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorB1, LOW);      
      digitalWrite(motorB2, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorA1, HIGH); 
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') 
    {
      analogWrite(aportnum,fullspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorB1, LOW);      
      digitalWrite(motorB2, LOW);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH); 
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') 
    {
      analogWrite(aportnum,vspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorB2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, HIGH);
             
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') 
    {
      analogWrite(aportnum,vspeed);
      analogWrite(aportnum1,fullspeed);
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH); 
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') 
    {
      analogWrite(aportnum1,fullspeed);
      analogWrite(aportnum,fullspeed);
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB2, LOW);
      digitalWrite(motorB1, HIGH);       
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') 
    {
      analogWrite(aportnum1,fullspeed);
      analogWrite(aportnum,fullspeed);
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);      
      digitalWrite(motorB2, HIGH); 
    }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S')
    {
      analogWrite(aportnum,0);
      analogWrite(aportnum1,0);
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);      
      digitalWrite(motorB2, LOW); 
    }
}
