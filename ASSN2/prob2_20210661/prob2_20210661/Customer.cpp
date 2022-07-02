#include "Customer.h"
#include <iostream>

Customer::Customer() { //기본 생성자.
	money = 1000;
	paidMoney = 0;
	time = 0;
}
Customer::Customer(float money, float paidMoney, float time) { //생성자 오버로딩, 각 값을 받을 때의 생성자
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
}
Customer::Customer(const Customer& customer) { //복사 생성자
	money = customer.money;
	paidMoney = customer.paidMoney;
	time = customer.time;
}
Customer::~Customer() { //소멸자
}
float Customer::asset() const { //현재 보유 자산 반환
	return money;
}
float Customer::reportMoney() const { //현재 번 수익 반환
	return paidMoney;
}
float Customer::reportTime() const { //현재까지 배달 대기 시간 반환
	return time;
}
void Customer::pay(float price, float time) {//피자 금액 지불에 따른 값 변화
	money = money - price;
	paidMoney = paidMoney + price;
	this->time += time;
}
ostream& operator<<(ostream& os, const Customer& x) {//<<연산자, money, paidMoney, time 값 출력 반환
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