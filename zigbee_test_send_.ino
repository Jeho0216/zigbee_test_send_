#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);	//지그비와 아두이노 연결.

void setup() {
	Serial.begin(9600);		//시리얼모니터 사용
	xbee.begin(9600);		//지그비 통신속도
	
	char type = '1';		//차후에 센서값 구분을 위한 변수
	int data = 1234;		//센서값에 해당하는 변수

	String send_data;		//라즈베리파이로 전송하기 위한 센서타입, 센서값 합치는 변수
	send_data = String(type) + "," + String(data) + ";";	//합치기
	Serial.println(send_data);		//시리얼모니터로 출력
	xbee.println(send_data);		//지그비로 전송
}

//라즈베리파이로 부터 수신받는 경우, 문자열 출력을 위한 부분
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
	if(str != "")		//수신된 내용이 존재할 경우에 수행.
		Serial.println(str);
	Serial.println("I am keep ruuning!");
	delay(1000);
}