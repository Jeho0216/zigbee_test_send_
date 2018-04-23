#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);	//���׺�� �Ƶ��̳� ����.

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
	boolean connect_raspi = false;

	delay(5000);
	receive_str = readSerial();
	if (receive_str != "")		//���ŵ� ������ ������ ��쿡 ����.
		Serial.println(receive_str);
	//��������̿� ����� �������� Ȯ��.

	send_data = String(type) + "," + String(value) + ";";	//��ġ��
	Serial.println("Send data : " + send_data);
	xbee.println(send_data);		//���׺�� ����

	if(connect_raspi == false){
		Serial.println("not connect to Raspberry Pi");
	}

	//���ŵ� ������ �������� ���� ���,
}