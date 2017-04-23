int val;
int tempPin = A8;
int tempLed = 5;
int ldrLed = 6;
int pirLed = 7;
int tankLed = 8;
int rec;
void setup()
{
Serial.begin(38400);
pinMode(tempPin,INPUT);
pinMode(tempLed,OUTPUT);
pinMode(ldrLed,OUTPUT);
pinMode(tankLed,OUTPUT);
pinMode(pirLed,OUTPUT);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
//float farh = (cel*9)/5 + 32;
if (Serial.available() > 0){
rec = Serial.read();
}
if (rec == '1'){
   analogWrite(ldrLed, 0);
} else if(rec == '2'){
  analogWrite(ldrLed, 63);
} else if(rec == '3'){
  analogWrite(ldrLed, 127);
} else if(rec == '4'){
  analogWrite(ldrLed, 190);
}else if(rec == '5'){
  analogWrite(ldrLed, 255);
}else if(rec == '6'){
  digitalWrite(pirLed, HIGH);
}else if(rec == '7'){
  digitalWrite(pirLed, LOW);
}else if(rec == '8'){
  digitalWrite(tankLed, HIGH);
}else if(rec == '9'){
  digitalWrite(tankLed, LOW);
}

if(cel >  25){
  digitalWrite(tempLed, 1);
}else{
  digitalWrite(tempLed, 0);
}
}


