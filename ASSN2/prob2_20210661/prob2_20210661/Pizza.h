

#include "Vector_Customer.h"
#include "Vector_Rider.h"
#include "Rider.h"
#include "Customer.h"
#pragma once
#include <iostream>

using namespace std;

class Pizza
{
public: //Pizza Class 멤버 변수 선언
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
	//멤버함수 선언
	Pizza();//생성자 오버로딩
	Pizza(float money);
	Pizza(const Pizza& pizza);
	~Pizza();//소멸자
	void setPrice();//가격 재설정
	void setPrice(float a, float b);//오버로딩
	void hire(const Rider& rider);//라이더 고용
	void hire(const Rider* riders, int size);//오버로딩
	void enroll(const Customer& customer, bool a);//고객 추가
	void enroll(const Customer* customers, int size, bool a);//오버로딩
	float reportMoney() const;//수입반환
	int numRiders() const;//라이더 수 반환
	int numCustomers(bool a) const;//고객수반환
	float meanFee() const;//평균배달비반환
	float meanTimeRiders() const;//평균배달시간반환
	float meanMoneyCustomers() const;//평균자산반환
	float meanTimeCustomers() const;//평균배달시간반환
	void deliver();//배달
	friend ostream& operator<<(ostream& os, const Pizza& x);//<<연산자 - 출력을 위함
};
