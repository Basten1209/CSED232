#include "Customer.h"
#include <iostream>

Customer::Customer() { //�⺻ ������.
	money = 1000;
	paidMoney = 0;
	time = 0;
}
Customer::Customer(float money, float paidMoney, float time) { //������ �����ε�, �� ���� ���� ���� ������
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
}
Customer::Customer(const Customer& customer) { //���� ������
	money = customer.money;
	paidMoney = customer.paidMoney;
	time = customer.time;
}
Customer::~Customer() { //�Ҹ���
}
float Customer::asset() const { //���� ���� �ڻ� ��ȯ
	return money;
}
float Customer::reportMoney() const { //���� �� ���� ��ȯ
	return paidMoney;
}
float Customer::reportTime() const { //������� ��� ��� �ð� ��ȯ
	return time;
}
void Customer::pay(float price, float time) {//���� �ݾ� ���ҿ� ���� �� ��ȭ
	money = money - price;
	paidMoney = paidMoney + price;
	this->time += time;
}
ostream& operator<<(ostream& os, const Customer& x) {//<<������, money, paidMoney, time �� ��� ��ȯ
	os << "(money, paidMoney, time) : ("
		<< x.money
		<< ", "
		<< x.paidMoney
		<< ", "
		<< x.time
		<< ")"
		<< endl;
	return os;
}