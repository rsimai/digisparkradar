/* Doppler radar hooked on a Digispark, to detect movement. rsimai 2022 */

#include <DigiCDC.h>
int i;
int in;
int poll;

void setup() {                
  pinMode(0, OUTPUT);    // 5V module power
  pinMode(1, OUTPUT);    // Digispark internal LED
  pinMode(2, INPUT);     // motion detected high
  digitalWrite(0, HIGH); // switch module on

  SerialUSB.begin();

  /* do some blinking until the sensor is ready */
  for (i=0; i<20; i++) {
    digitalWrite(1, HIGH);
    SerialUSB.delay(250);
    digitalWrite(1, LOW);
    SerialUSB.delay(250);
  }
}

void loop() {
  in = digitalRead(2);
  if (in == HIGH) {
    digitalWrite(1, HIGH); // LED on when motion
  }
  else {
    digitalWrite(1, LOW);
  }
  if (SerialUSB.available()) { // check if poll for output
    poll = SerialUSB.read();
  }
  if (poll) {
    SerialUSB.print(in);     // output motion 1 or not 0
    poll = SerialUSB.read(); // read one more byte
    poll = 0;
  }
  SerialUSB.delay(50);               // remember to keep usb alive
}
