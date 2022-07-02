

#include "Vector_Customer.h"
#include "Vector_Rider.h"
#include "Rider.h"
#include "Customer.h"
#pragma once
#include <iostream>

using namespace std;

class Pizza
{
public: //Pizza Class ��� ���� ����
	float money;
	float priceA;
	float priceB;
	float feeA;
	float feeB;
	float timeA;
	float timeB;
	Vector_Customer A;
	Vector_Customer B;
	Vector_Rider R;
	//����Լ� ����
	Pizza();//������ �����ε�
	Pizza(float money);
	Pizza(const Pizza& pizza);
	~Pizza();//�Ҹ���
	void setPrice();//���� �缳��
	void setPrice(float a, float b);//�����ε�
	void hire(const Rider& rider);//���̴� ���
	void hire(const Rider* riders, int size);//�����ε�
	void enroll(const Customer& customer, bool a);//�� �߰�
	void enroll(const Customer* customers, int size, bool a);//�����ε�
	float reportMoney() const;//���Թ�ȯ
	int numRiders() const;//���̴� �� ��ȯ
	int numCustomers(bool a) const;//������ȯ
	float meanFee() const;//��չ�޺��ȯ
	float meanTimeRiders() const;//��չ�޽ð���ȯ
	float meanMoneyCustomers() const;//����ڻ��ȯ
	float meanTimeCustomers() const;//��չ�޽ð���ȯ
	void deliver();//���
	friend ostream& operator<<(ostream& os, const Pizza& x);//<<������ - ����� ����
};
