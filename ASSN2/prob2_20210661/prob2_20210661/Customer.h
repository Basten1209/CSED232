#pragma once
#include <iostream>

using namespace std;

class Customer
{
private: //��� ���� ����
	float money;
	float paidMoney;
	float time;
public://��� �Լ� ����
	Customer();//������ 3�� �����ε�
	Customer(float money, float paidMoney, float time);
	Customer(const Customer& customer);
	~Customer();//�Ҹ���

	float asset() const;
	float reportMoney() const;
	float reportTime() const;
	void pay(float price, float time);
	friend ostream& operator <<(ostream& os, const Customer& x);//<<������ - ����� ����
};

