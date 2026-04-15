// C++ code
int enA = 9;
int in1 = 8;
int in2 = 7; //pins for motor 1

int enB = 3;
int in3 = 5;
int in4 = 4; //pins for motor 2


void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  analogWrite(enA,0);
  analogWrite(enB,0);
  
  Serial.begin(9600);
  
}

void loop()
{
   char input = Serial.read();
  
   if(input=='w') //moving forward
    {
      delay(300);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in1,LOW); //both wheels moving forward 
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      Serial.println("forward");
    }

    if(input=='a') //turning left
    {
      delay(300);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in1,LOW); //left wheel moves forward ,right wheel backward
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      
      Serial.println("turning left");
    }

    if(input=='d') //turning right
    {
      delay(300);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW); //left wheel backward , right wheel forward
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      
      Serial.println("turning right");
    }

    if(input=='s') //reverse
    {
      delay(300);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW); //both wheels backward
      digitalWrite(in4,HIGH);
      Serial.println("reverse");
    }
    
}
