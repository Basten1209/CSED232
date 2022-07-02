#include "Rider.h"
#include <iostream>

using namespace std;

Rider::Rider() {//기본 생성자
	money = 0;
	earnMoney = 0;
	time = 0;
}
Rider::Rider(float money, float earnMoney, float time) {//값을 입력 받은 생성자
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;
}
Rider::Rider(const Rider& rider) {//복사 생성자
	money = rider.money;
	earnMoney = rider.earnMoney;
	time = rider.time;
}
Rider::~Rider() {//소멸자

}
float Rider::asset() const {//현재 자산 반환
	return money;
}
float Rider::reportMoney() const {//현재 수익 반환
	return earnMoney;
}
float Rider::reportTime() const {//현재까지 배달 시간 반환
	return time;
}
void Rider::deliver(float price, float time) {//배달 진행 시 자산, 수익, 배달시간 변화
	earnMoney += price;
	money += price;
	this->time += time;
}
ostream& operator<<(ostream& os, const Rider& x) {//라이더 정보 출력
	os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << ")";
	return os;
}