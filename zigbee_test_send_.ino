#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);

void setup() {
	Serial.begin(9600);
	xbee.begin(9600);
	char type = '1';
	int data = 1234;
	//char send[10];
	String send_data;
	send_data = String(type) + "," + String(data) + ";";
	Serial.println(send_data);
	//send_data.toCharArray(send, send_data.length());
	xbee.println(send_data);
}

String readSerial() {
	String str = "";
	char ch;
	if (xbee.available()) {
		while (xbee.available() > 0) {
			ch = xbee.read();
			str.concat(ch);
			delay(10);
		}
	}
	return str;
}

void loop() {
	String str;
	str = readSerial();
	if(str != "")
		Serial.println(str);
	Serial.println("I am keep ruuning!");
	delay(1000);
}