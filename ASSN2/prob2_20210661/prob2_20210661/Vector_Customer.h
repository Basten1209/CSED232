#include "Customer.h"
#pragma once
using namespace std;

class Vector_Customer {//Vector_Customer Class 선언.

private://멤버 변수 선언
	Customer *arr;
	int _size;
	int _capacity;

public:
	typedef Customer* iterator;// iterator 선언 + 오버로딩
	typedef const Customer* const_iterator;
	//멤버 함수 선언. 함수 설명 주석은 cpp 파일에서.
	Vector_Customer();
	Vector_Customer(int size);
	Vector_Customer(int size, const Customer& init);
	Vector_Customer(int size, const Customer* init);
	Vector_Customer(const Vector_Customer& v);
	~Vector_Customer();
	int capacity() const;
	int size() const;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	Customer& front();
	const Customer& front() const;
	Customer& back();
	const Customer& back() const;
	void allocate(int capacity);
	void resize(int size);
	void push_back(const Customer& value);
	void pop_back();
	void insert(iterator position, const Customer& value);
	void insert(iterator position, const Customer* first, const Customer* last);
	void erase(iterator position);
	void clear();
	Customer& operator[](int index);
	const Customer& operator[](int index) const;
	Vector_Customer& operator=(const Vector_Customer& v);




};


