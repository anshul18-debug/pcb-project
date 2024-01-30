#include <Servo.h>



int sensorValue = 0;

int outputValue = 0;

Servo servo_9;

void setup()
{
  pinMode(A0, INPUT);
  servo_9.attach(9);
  
}

void loop()
{
  sensorValue = analogRead(A0);
   outputValue = map(sensorValue,0,1023,0,180);
  servo_9.write(outputValue);
  delay(10);//delay alittle bit to improve stimulation
}