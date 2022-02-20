#include <DigiCDC.h>

int in;
int count;

void setup() {                
  // initialize 
  SerialUSB.begin();
  pinMode(0, OUTPUT); //module power
  pinMode(1, OUTPUT); //internal LED
  pinMode(2, INPUT);  //motion detected
  digitalWrite(0, HIGH); //switch module on
}

void loop() {
  in = digitalRead(2);
  if (in == HIGH) {
    digitalWrite(1, HIGH);
    if (SerialUSB.available()) {
      SerialUSB.println(count);
      count++;
    }
  }
  else {
    digitalWrite(1, LOW);
  }
   SerialUSB.delay(100);               // keep usb alive // can alos use SerialUSB.refresh();
}
