#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);	//지그비와 아두이노 연결.

boolean connect_raspi = false;

void setup() {
	Serial.begin(9600);		//시리얼모니터 사용
	xbee.begin(9600);		//지그비 통신속도

	Serial.println("Arduino Ready.");
	xbee.print("Arduino Ready.");
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
	String receive_str;
	long value = random(0, 256);	//0~255까지의 난수 발생.
	char type = '1';		//차후에 센서값 구분을 위한 변수
	String send_data;		//라즈베리파이로 전송하기 위한 센서타입, 센서값 합치는 변수

	delay(3000);
	receive_str = readSerial();
	if (receive_str != "")		//수신된 내용이 존재할 경우에 수행.
		Serial.println(receive_str);

	//라즈베리파이와 연결된 상태인지 확인.
	if(connect_raspi == false){
		if (receive_str.indexOf("Hello") != -1)
			connect_raspi = true;
		Serial.println("not connect to Raspberry Pi");
	}
	else if (connect_raspi == true) {
		send_data = String(type) + "," + String(value) + ";";	//합치기
		Serial.println("Send data : " + send_data);
		xbee.println(send_data);		//지그비로 전송
		if (receive_str.indexOf("Bye") != -1)
			connect_raspi = false;
	}
	Serial.println("connect : " + String(connect_raspi));

	//수신된 내용이 존재하지 않을 경우,
}