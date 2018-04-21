#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);	//���׺�� �Ƶ��̳� ����.

void setup() {
	Serial.begin(9600);		//�ø������� ���
	xbee.begin(9600);		//���׺� ��żӵ�
	
	char type = '1';		//���Ŀ� ������ ������ ���� ����
	int data = 1234;		//�������� �ش��ϴ� ����

	String send_data;		//��������̷� �����ϱ� ���� ����Ÿ��, ������ ��ġ�� ����
	send_data = String(type) + "," + String(data) + ";";	//��ġ��
	Serial.println(send_data);		//�ø������ͷ� ���
	xbee.println(send_data);		//���׺�� ����
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
	String str;
	str = readSerial();
	if(str != "")		//���ŵ� ������ ������ ��쿡 ����.
		Serial.println(str);
	Serial.println("I am keep ruuning!");
	delay(1000);
}