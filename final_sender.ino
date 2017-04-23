int i=1;
volatile int ldr, ldr1=-7,ldr2=-2, pir, pir1=-8, pir2=-3,ir, ir1=-9, ir2=-4,c=0;
void setup() {
  
Serial.begin(38400);


}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  int ldr= analogRead(A0);
  int pir= digitalRead(7);
  int ir= digitalRead(6); 
 
if(ldr>0 && ldr<164)
  {
    ldr1 = 1;
  }
  else if(ldr>163 && ldr<300)
  {
    ldr1 = 2;
   // analogWrite(A3,63);
  }
  else if(ldr>299 && ldr<500)
  {
    ldr1 = 3;
    //analogWrite(A3,126);
    }
  else if(ldr>499 && ldr<750)
  {
    ldr1 = 4;
    //analogWrite(A3,190);
  }
  else if(ldr>749 && ldr<1025)
  {
    ldr1 = 5;
  }

  if(ldr1!=ldr2){
    Serial.println(ldr1);
    ldr2=ldr1;
  }
 
  
  if(pir==HIGH)
  {
    pir1=6;
  }
  else if(pir==LOW)
  {
    pir1=7;
  }
  
   if(pir1!=pir2){
    Serial.println(pir1);
    pir2=pir1;
  }
  if(ir==HIGH)
  {
     c++;
  }
  else if (ir==LOW)
  {
     c=0;
  }
  
   if(c>=11){
    ir1=8;}else ir1=9;
    
 if(ir1!=ir2){   
    Serial.println(ir1);
    ir2=ir1;
 }
 
  delay(500);
 
  }

