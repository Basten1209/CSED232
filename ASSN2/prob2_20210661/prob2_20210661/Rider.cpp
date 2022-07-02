#include "Rider.h"
#include <iostream>

using namespace std;

Rider::Rider() {//�⺻ ������
	money = 0;
	earnMoney = 0;
	time = 0;
}
Rider::Rider(float money, float earnMoney, float time) {//���� �Է� ���� ������
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;
}
Rider::Rider(const Rider& rider) {//���� ������
	money = rider.money;
	earnMoney = rider.earnMoney;
	time = rider.time;
}
Rider::~Rider() {//�Ҹ���

}
float Rider::asset() const {//���� �ڻ� ��ȯ
	return money;
}
float Rider::reportMoney() const {//���� ���� ��ȯ
	return earnMoney;
}
float Rider::reportTime() const {//������� ��� �ð� ��ȯ
	return time;
}
void Rider::deliver(float price, float time) {//��� ���� �� �ڻ�, ����, ��޽ð� ��ȭ
	earnMoney += price;
	money += price;
	this->time += time;
}
ostream& operator<<(ostream& os, const Rider& x) {//���̴� ���� ���
	os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << ")";
	return os;
}