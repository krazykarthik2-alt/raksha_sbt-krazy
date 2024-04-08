#include<SoftwareSerial.h>
#define TOUCHPIN 2
int count = 0, touch;
long long int lasttouch = 0;
#define THRESHOLD 700
SoftwareSerial btserial(12,11);
void setup() {
  Serial.begin(9600); 
  btserial.begin(38400);
  pinMode(touch, INPUT);
}

void loop() {

 touch= digitalRead(TOUCHPIN);
  Serial.println(count);
  if (touch == 1) {
    int mill = millis();//current millis

    if (lasttouch == 0) { //first time
      lasttouch = mill;//first time
     
    }

    else {
      if ((mill - lasttouch) < THRESHOLD)//if this touch and last touch are less than threshol time diff
      {
      } else {
        count = 0;
      }
    }
    count++;
    while (digitalRead(TOUCHPIN) == 1) {
      delay(10);
    }
    lasttouch = millis();

  }
  if (count == 3) {
    btserial.write('a');
    Serial.println(10);
    count = 0;
  }
  if (count != 3)
  {
    btserial.write('0');
  }



  if((millis()-lasttouch)>THRESHOLD){
    count=0;
  }
  
  delay(50);
}
