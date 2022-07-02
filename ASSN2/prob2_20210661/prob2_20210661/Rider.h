#pragma once
#include <iostream>
using namespace std;

class Rider
{
private://Rider Class 멤버 변수 선언
	float money;
	float earnMoney;
	float time;
public://Rider Class 멤버 함수 선언
	Rider();//생성자 오버로딩
	Rider(float money, float earnMoney, float time);
	Rider(const Rider& rider);//복사생성자
	~Rider();//소멸자
	float asset() const;
	float reportMoney() const;
	float reportTime() const;
	void deliver(float price, float time);//배달
	friend ostream& operator<<(ostream& os, const Rider& x);//<<연산자 - 출력을 위함
};

