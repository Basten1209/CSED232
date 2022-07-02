#pragma once
#include <iostream>
using namespace std;

class Rider
{
private://Rider Class ��� ���� ����
	float money;
	float earnMoney;
	float time;
public://Rider Class ��� �Լ� ����
	Rider();//������ �����ε�
	Rider(float money, float earnMoney, float time);
	Rider(const Rider& rider);//���������
	~Rider();//�Ҹ���
	float asset() const;
	float reportMoney() const;
	float reportTime() const;
	void deliver(float price, float time);//���
	friend ostream& operator<<(ostream& os, const Rider& x);//<<������ - ����� ����
};

