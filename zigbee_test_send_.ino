#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);	//���׺�� �Ƶ��̳� ����.

boolean connect_raspi = false;

void setup() {
	Serial.begin(9600);		//�ø������� ���
	xbee.begin(9600);		//���׺� ��żӵ�

	Serial.println("Arduino Ready.");
	xbee.print("Arduino Ready.");
}

//��������̷� ���� ���Ź޴� ���, ���ڿ� ����� ���� �κ�
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
	long value = random(0, 256);	//0~255������ ���� �߻�.
	char type = '1';		//���Ŀ� ������ ������ ���� ����
	String send_data;		//��������̷� �����ϱ� ���� ����Ÿ��, ������ ��ġ�� ����

	delay(3000);
	receive_str = readSerial();
	if (receive_str != "")		//���ŵ� ������ ������ ��쿡 ����.
		Serial.println("Receive : " + receive_str);

	//��������̿� ����� �������� Ȯ��.
	if(connect_raspi == false){
		Serial.println("not connect to Raspberry Pi");
		if (receive_str.indexOf("Hello") != -1) {
			connect_raspi = true;
			Serial.println("Connection success.");
		}
	}
	else if (connect_raspi == true) {
		send_data = String(type) + "," + String(value) + ";";	//��ġ��
		Serial.println("Send data : " + send_data);
		xbee.println(send_data);		//���׺�� ����
		if (receive_str.indexOf("Bye") != -1)
			connect_raspi = false;
	}
}