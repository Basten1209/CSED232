#pragma once
#include <iostream>

using namespace std;

class Customer
{
private: //멤버 변수 선언
	float money;
	float paidMoney;
	float time;
public://멤버 함수 선언
	Customer();//생성자 3개 오버로딩
	Customer(float money, float paidMoney, float time);
	Customer(const Customer& customer);
	~Customer();//소멸자

	float asset() const;
	float reportMoney() const;
	float reportTime() const;
	void pay(float price, float time);
	friend ostream& operator <<(ostream& os, const Customer& x);//<<연산자 - 출력을 위함
};

