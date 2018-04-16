#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);

void setup() {
  // put your setup code here, to run once:
  xbee.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xbee.print('A');
  delay(1000);
}
