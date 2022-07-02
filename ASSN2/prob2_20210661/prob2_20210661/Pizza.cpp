#include "Pizza.h"
#include "customer.h"
#include "Vector_Customer.h"
#include "Vector_Rider.h"
#include <iostream>
#include <cstdbool>

Pizza::Pizza(){ //�⺻������
	money = 10000;
	timeA = 10;
	timeB = 20;
	A.Vector_Customer::Vector_Customer(5);
	B.Vector_Customer::Vector_Customer(5);
	R.Vector_Rider::Vector_Rider(5);
	setPrice();
}
Pizza::Pizza(float money) { //money ���� ���� ���� ������ (�����ε�)
	this->money = money;
	timeA = 10;
	timeB = 20;
	A.Vector_Customer::Vector_Customer(5);
	B.Vector_Customer::Vector_Customer(5);
	R.Vector_Rider::Vector_Rider(5);
	setPrice();
}
Pizza::Pizza(const Pizza& pizza) { //���� ������
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
Pizza::~Pizza() { //�Ҹ���

}
void Pizza::setPrice() { //���� ���ݰ� ��޷� å��
	priceA = 100 - 3 * A.size();
	priceB = 100 - 6 * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}
void Pizza::setPrice(float a, float b) { //���� ���ݰ� ��޷� å�� �����ε�(������ ������ ������ �ٸ���)
	priceA = 100 - a * A.size();
	priceB = 100 - b * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}
void Pizza::hire(const Rider& rider) {//���̴� ���, �� �� ���̴� ����� �ڿ� push_back
	R.erase(R.begin());
	R.push_back(rider);
}
void Pizza::hire(const Rider* riders, int size) {//���� ���̴� ���, ������ŭ �տ������� ���̴� ����� �ڿ� insert.
	
	for (int i = 0; i < size; i++) {
		R.erase(R.begin());
	}
	R.insert(R.begin() + R.size(), riders, riders + size);
}
void Pizza::enroll(const Customer& customer, bool a) {//�Һ��� �߰�. 
	if (a == 1) {//a==1�̸� A�� �߰�
		if (A.size() < 9) {//A�� �ο��� �߰� �� �� �ִ� ���
			B.erase(B.begin()); //B���� ���� ��
			A.push_back(customer); //A�� �߰�
		}
		else if (A.size() == 9) {//A�� �ο��� �߰��� �� ���� ��Ȳ�� ���
			A.erase(A.begin());//A���� ���� ��
			A.push_back(customer);//A�� �߰�
		}
	}
	if (a == 0) {//a==0�̸� B�� �߰�
		if (B.size() < 9) { 
			A.erase(A.begin());
			B.push_back(customer);
		}
		else if (B.size() == 9) {
			B.erase(B.begin());
			B.push_back(customer);
		}
	}
	setPrice();//���� ������
}
void Pizza::enroll(const Customer* customers, int size, bool a) { //���� �Һ��� �߰� case, ����� ���� 1�� �߰� enroll(�����ε�)�� ����.
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
float Pizza::reportMoney() const {//���� �ڻ� ǥ��
	return money;
}
int Pizza::numRiders() const {//���̴� �� ǥ��
	return R.size();
}
int Pizza::numCustomers(bool a) const {//A, B�� �� ���� a�� ���� ���� ǥ��
	if (a == 1) {
		return A.size();
	}
	else
		return B.size();
}
float Pizza::meanFee() const { //��޷� ��� ���ϴ� �Լ�
	float temp = 0;
	for (int i = 0; i < numRiders(); i++) { //���̴� �� ��ŭ �ݺ��ϸ� ���̴� �Ѹ�� ��޺� temp�� �߰�
		temp += R[i].reportMoney();
	}
	temp = temp / numRiders(); //���̴� ���� ���� ��� ��ȯ
	return temp;
}
float Pizza::meanTimeRiders() const {//�ð� ��� ���ϴ� �Լ�
	float temp = 0;
	for (int i = 0; i < R.size(); i++) {//���̴� ����ŭ �ݺ��ϸ� ��� �ð��� temp�� �߰�
		temp += R[i].reportTime();
	}
	temp = temp / (R.size()); //���̴� ���� ���� ��� ��ȯ 
	return temp;
}
float Pizza::meanMoneyCustomers() const {//�Һ��� ��� �Һ� ���� ���ϴ� �Լ�
	float temp = 0;
	for (int i = 0; i < A.size(); i++) {//A �Һ��� ����ŭ �ݺ��ϸ� �Һ񰡰� temp�� �߰�
		temp += A[i].reportMoney();
	}
	for (int j = 0; j < B.size(); j++) {//B �Һ��� ����ŭ �ݺ��ϸ� �Һ񰡰� temp�� �߰�
		temp += B[j].reportMoney();
	}
	temp = temp / (A.size() + B.size());//A, B �ο� ���� ������ ��ȯ

	return temp;
}
float Pizza::meanTimeCustomers() const { //�Һ��� ��� ��޽ð� ���ϴ� �Լ�
	float temp = 0;
	for (int i = 0; i < A.size(); i++) {//A �Һ��� �� ��ŭ �ݺ��ϸ� �ð� temp�� �߰�
		temp += A[i].reportTime();
	}
	for (int j = 0; j < B.size(); j++) {//B �Һ��� ����ŭ �ݺ��ϸ� �ð�temp�� �߰�
		temp += B[j].reportTime();
	}
	temp = temp / (A.size() + B.size());//�ο��� ������ ������ ��ȯ

	return temp;
}
void Pizza::deliver() {//��� ���� �Լ�
	int count = 0;

	for(int i = 0; i<A.size(); i++){
		float tempmoney = A[i].asset() - priceA;//���ڰ��� ����
		float temppaidMoney = A[i].reportMoney() + priceA;//���ڰ��� ���ϱ�
		float temptime = A[i].reportTime() + timeA;//�ð� �߰�
		A[i].Customer::Customer(tempmoney, temppaidMoney, temptime);//temp�� ���� ������ Customer ���� ��ġ�� ����
		money += priceA;//���ڰ��� �� ����

		tempmoney = R[count % 5].asset() - priceA;//���ڰ��� ����, count%5�� ���� : ��ޱ��� 5���̱⶧���� ���� ��簡 0,5/1,6/2,7/3,8/4,9��° �� �湮�ϸ�, �� ������ mod 5���� ����
		temppaidMoney = R[count % 5].reportMoney() + feeA;//��޷� ���ϱ�
		temptime = R[count % 5].reportTime() + timeA;//��޽ð� �߰�
		R[count % 5].Rider::Rider(tempmoney, temppaidMoney, temptime);//temp�� ���� ������ Rider ���� ��ġ�� ����
		money -= feeA;//��޺�ŭ ���ڰ��� �� ����
		count++;//count ����
	}
	for (int i = 0; i < B.size(); i++) {//B ���鿡 ���� ���� �����ϰ� ����
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
ostream& operator<< (ostream& os, const Pizza& x) {//����� ���
	os << "1) Money : " << x.reportMoney() << endl;
	os << "2) (Customers, Price, Fee)" << endl;
	os << " - A : (" << x.numCustomers(1) << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << " - B : (" << x.numCustomers(0) << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders: " << x.numRiders() << endl;
	return os;
}