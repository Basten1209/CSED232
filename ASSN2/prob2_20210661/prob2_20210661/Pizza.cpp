#include "Pizza.h"
#include "customer.h"
#include "Vector_Customer.h"
#include "Vector_Rider.h"
#include <iostream>
#include <cstdbool>

Pizza::Pizza(){ //기본생성자
	money = 10000;
	timeA = 10;
	timeB = 20;
	A.Vector_Customer::Vector_Customer(5);
	B.Vector_Customer::Vector_Customer(5);
	R.Vector_Rider::Vector_Rider(5);
	setPrice();
}
Pizza::Pizza(float money) { //money 값이 들어올 때의 생성자 (오버로딩)
	this->money = money;
	timeA = 10;
	timeB = 20;
	A.Vector_Customer::Vector_Customer(5);
	B.Vector_Customer::Vector_Customer(5);
	R.Vector_Rider::Vector_Rider(5);
	setPrice();
}
Pizza::Pizza(const Pizza& pizza) { //복사 생성자
	money = pizza.money;
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeB;
	timeA = pizza.timeA;
	timeB = pizza.timeB;
	A = pizza.A;
	B = pizza.B;
	R = pizza.R;
}
Pizza::~Pizza() { //소멸자

}
void Pizza::setPrice() { //피자 가격과 배달료 책정
	priceA = 100 - 3 * A.size();
	priceB = 100 - 6 * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}
void Pizza::setPrice(float a, float b) { //피자 가격과 배달료 책정 오버로딩(한판의 가격이 기존과 다를때)
	priceA = 100 - a * A.size();
	priceB = 100 - b * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}
void Pizza::hire(const Rider& rider) {//라이더 고용, 맨 앞 라이더 지우고 뒤에 push_back
	R.erase(R.begin());
	R.push_back(rider);
}
void Pizza::hire(const Rider* riders, int size) {//여러 라이더 고용, 고용수만큼 앞에서부터 라이더 지우고 뒤에 insert.
	
	for (int i = 0; i < size; i++) {
		R.erase(R.begin());
	}
	R.insert(R.begin() + R.size(), riders, riders + size);
}
void Pizza::enroll(const Customer& customer, bool a) {//소비자 추가. 
	if (a == 1) {//a==1이면 A에 추가
		if (A.size() < 9) {//A에 인원을 추가 할 수 있는 경우
			B.erase(B.begin()); //B에서 삭제 후
			A.push_back(customer); //A에 추가
		}
		else if (A.size() == 9) {//A에 인원을 추가할 수 없는 상황인 경우
			A.erase(A.begin());//A에서 삭제 후
			A.push_back(customer);//A에 추가
		}
	}
	if (a == 0) {//a==0이면 B에 추가
		if (B.size() < 9) { 
			A.erase(A.begin());
			B.push_back(customer);
		}
		else if (B.size() == 9) {
			B.erase(B.begin());
			B.push_back(customer);
		}
	}
	setPrice();//가격 재정리
}
void Pizza::enroll(const Customer* customers, int size, bool a) { //여러 소비자 추가 case, 방식은 위의 1명 추가 enroll(오버로딩)과 동일.
	if (a == 1) {
		if (A.size() < 10 - size) {
			for (int i = 0; i < size; i++) {
				B.erase(B.begin());
			}
			A.insert(A.begin()+A.size(), customers, customers+size);
		}
		else if (A.size() >= 10 - size) {
			for (int i = 0; i < size; i++) {
				A.erase(A.begin());
			}
			A.insert(A.begin() + A.size(), customers, customers + size);
		}
	}
	else if (a == 0) {
		if (B.size() < 10 - size) {
			for (int i = 0; i < size; i++) {
				A.erase(A.begin());
			}
			B.insert(B.begin() + B.size(), customers, customers + size);
		}
		else if (B.size() >= 10 - size) {
			for (int i = 0; i < size; i++) {
				B.erase(B.begin());
			}
			B.insert(B.begin() + B.size(), customers, customers + size);
		}
	}
	setPrice();
	}
float Pizza::reportMoney() const {//현재 자산 표시
	return money;
}
int Pizza::numRiders() const {//라이더 수 표시
	return R.size();
}
int Pizza::numCustomers(bool a) const {//A, B의 고객 수를 a의 값에 따라 표시
	if (a == 1) {
		return A.size();
	}
	else
		return B.size();
}
float Pizza::meanFee() const { //배달료 평균 구하는 함수
	float temp = 0;
	for (int i = 0; i < numRiders(); i++) { //라이더 수 만큼 반복하며 라이더 한명당 배달비를 temp에 추가
		temp += R[i].reportMoney();
	}
	temp = temp / numRiders(); //라이더 수로 나눠 평균 반환
	return temp;
}
float Pizza::meanTimeRiders() const {//시간 평균 구하는 함수
	float temp = 0;
	for (int i = 0; i < R.size(); i++) {//라이더 수만큼 반복하며 배달 시간을 temp에 추가
		temp += R[i].reportTime();
	}
	temp = temp / (R.size()); //라이더 수로 나눠 평균 반환 
	return temp;
}
float Pizza::meanMoneyCustomers() const {//소비자 평균 소비 가격 구하는 함수
	float temp = 0;
	for (int i = 0; i < A.size(); i++) {//A 소비자 수만큼 반복하며 소비가격 temp에 추가
		temp += A[i].reportMoney();
	}
	for (int j = 0; j < B.size(); j++) {//B 소비자 수만큼 반복하며 소비가격 temp에 추가
		temp += B[j].reportMoney();
	}
	temp = temp / (A.size() + B.size());//A, B 인원 수로 나누어 반환

	return temp;
}
float Pizza::meanTimeCustomers() const { //소비자 평균 배달시간 구하는 함수
	float temp = 0;
	for (int i = 0; i < A.size(); i++) {//A 소비자 수 만큼 반복하며 시간 temp에 추가
		temp += A[i].reportTime();
	}
	for (int j = 0; j < B.size(); j++) {//B 소비자 수만큼 반복하며 시간temp에 추가
		temp += B[j].reportTime();
	}
	temp = temp / (A.size() + B.size());//인원수 합으로 나누어 반환

	return temp;
}
void Pizza::deliver() {//배달 수행 함수
	int count = 0;

	for(int i = 0; i<A.size(); i++){
		float tempmoney = A[i].asset() - priceA;//피자가격 빼기
		float temppaidMoney = A[i].reportMoney() + priceA;//피자가격 더하기
		float temptime = A[i].reportTime() + timeA;//시간 추가
		A[i].Customer::Customer(tempmoney, temppaidMoney, temptime);//temp에 담은 값으로 Customer 동일 위치에 복사
		money += priceA;//피자가게 돈 증가

		tempmoney = R[count % 5].asset() - priceA;//피자가격 빼기, count%5의 이유 : 배달기사는 5명이기때문에 동일 기사가 0,5/1,6/2,7/3,8/4,9번째 고객 방문하며, 이 값들의 mod 5값이 동일
		temppaidMoney = R[count % 5].reportMoney() + feeA;//배달료 더하기
		temptime = R[count % 5].reportTime() + timeA;//배달시간 추가
		R[count % 5].Rider::Rider(tempmoney, temppaidMoney, temptime);//temp에 담은 값으로 Rider 동일 위치에 복사
		money -= feeA;//배달비만큼 피자가게 돈 감소
		count++;//count 증가
	}
	for (int i = 0; i < B.size(); i++) {//B 고객들에 대해 위와 동일하게 진행
		float tempmoney = B[i].asset() - priceB;
		float temppaidMoney = B[i].reportMoney() + priceB;
		float temptime = B[i].reportTime() + timeB;
		B[i].Customer::Customer(tempmoney, temppaidMoney, temptime);
		money += priceB;

		tempmoney = R[count % 5].asset() - priceB;
		temppaidMoney = R[count % 5].reportMoney() + feeB;
		temptime = R[count % 5].reportTime() + timeB;
		R[count % 5].Rider::Rider(tempmoney, temppaidMoney, temptime);
		money -= feeB;
		count++;
	}

}
ostream& operator<< (ostream& os, const Pizza& x) {//결과값 출력
	os << "1) Money : " << x.reportMoney() << endl;
	os << "2) (Customers, Price, Fee)" << endl;
	os << " - A : (" << x.numCustomers(1) << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << " - B : (" << x.numCustomers(0) << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders: " << x.numRiders() << endl;
	return os;
}