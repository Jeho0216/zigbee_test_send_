#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
	xbee.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
	xbee.write("A\n");
	delay(1000);
}