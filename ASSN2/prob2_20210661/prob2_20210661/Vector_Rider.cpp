#include "Vector_Rider.h"
#include "Rider.h"
#include <iostream>
using namespace std;

Vector_Rider::Vector_Rider() { // ������, parameter ���� �� �� = 0, 0, NULL
	_size = 0;
	_capacity = 0;
	arr = NULL;
}
Vector_Rider::Vector_Rider(int size) { //_size ���� �޴� ������, �� = size, size, arr = {0, }
	_size = size;
	_capacity = size;
	arr = new Rider[size];
	for (int i = 0; i < _size; i++) {
		arr[i].Rider::Rider();
	}
}
Vector_Rider::Vector_Rider(int size, const Rider& init) {//_size ���� �� �ϳ��� �޴� ������. �� = size, size, arr = {init,NULL, NULL, ,,,, }
	_size = size;
	_capacity = size;
	arr = new Rider[size];
	*arr = init;
}
Vector_Rider::Vector_Rider(int size, const Rider* init) {//_size ���� float array �ϳ��� �޴� ������. �� = size, size, arr = init
	_size = size;
	_capacity = size;
	arr = new Rider[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = *(init + i);
	}
}
Vector_Rider::Vector_Rider(const Vector_Rider& v) {//���� ������. _size, _capacity ���� �ٷ� ���� �Ͽ� ����, arr�� ������ �ϳ��� for���� ���� ����.

	_size = v._size;
	_capacity = v._capacity;
	arr = new Rider[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = v.arr[i];
	}
}
Vector_Rider::~Vector_Rider() { //�Ҹ���. delete[] �� ���Ͽ� �Ҵ� ����.
	delete[] arr;
}
int Vector_Rider::capacity() const { //_capacity ���� return �ϴ� �Լ� const ver.
	return _capacity;
}
int Vector_Rider::size() const {//_size ���� return �ϴ� �Լ�, const ver.
	return _size;
}
Vector_Rider::iterator Vector_Rider::begin() {//arr ù �� �ּ� return �ϴ� �Լ�
	return arr;
}
Vector_Rider::const_iterator Vector_Rider::begin() const { //arr ù �� �ּ� return �ϴ� �Լ� , const. ver.
	return arr;
}
Vector_Rider::iterator Vector_Rider::end() { //arr ������ �� �ּ� return�ϴ� �Լ�. ������ �� �ּ� = ù �� + _size. 
	return arr + _size;
}
Vector_Rider::const_iterator Vector_Rider::end() const {//arr ������ �� �ּ� return�ϴ� �Լ�, const. ver.
	return arr + _size;
}
Rider& Vector_Rider::front() {//arr ù �� return �ϴ� �Լ�.
	return arr[0];
}
const Rider& Vector_Rider::front() const {//arr ù �� return �ϴ� �Լ�. const ver.
	return arr[0];
}
Rider& Vector_Rider::back() {//arr ������ �� return �ϴ� �Լ�.
	return arr[_size - 1];
}
const Rider& Vector_Rider::back() const { //arr ������ �� return �ϴ� �Լ�. const .ver

	return arr[_size - 1];
}
void Vector_Rider::allocate(int capacity) {
	Vector_Rider tmp;
	tmp._size = this->_size; //size�� this �� �״�� �ѱ�
	tmp._capacity = capacity; //capacity�� �Է¹��� �� ���
	tmp.arr = new Rider[capacity];//capacity�� ���߾� ���� �Ҵ�
	for (int i = 0; i < _capacity; i++) {//tmp.arr �� this->arr ����
		tmp.arr[i] = this->arr[i];
	}
	delete[] this->arr;
	*this = tmp; //tmp �� *this�� �ѱ�.
}
void Vector_Rider::resize(int size) {
	Vector_Rider tmp;
	tmp._size = size; //_size, _capacity ��� �Է¹��� ������ ����
	tmp._capacity = size;
	tmp.arr = new Rider[_size];//_size�� ���߾� ���� �Ҵ�
	for (int i = 0; i < tmp._capacity; i++) {//tmp.arr�� this->arr ����. 
		tmp.arr[i] = this->arr[i];
	}
	delete[] this->arr;
	*this = tmp;//tmp�� *this�� �ѱ�.
}
void Vector_Rider::push_back(const Rider& value) {

	_size = _size + 1;//�� �ϳ� �Է� ������ size 1 �߰�

	if (_size >= _capacity) {//_size�� _capacity �̻��� �� 
		if (_size < 5) { //<5�� ��� �� �� �״�� allocate
			allocate(_size);
		}
		else if (_size >= 5) {//>=5�� ��� size 2��� allocate
			allocate(_size * 2);
		}

	}
	arr[_size - 1] = value; //�������� �� �߰�

}

void Vector_Rider::pop_back() {//������ �� 0 ���� ���� �� _size 1 ����
	arr[_size - 1].Rider::Rider();
	_size = _size - 1;
}

void Vector_Rider::insert(iterator position, const Rider& value) {
	_size = _size + 1;//�� �ϳ� �߰��ϴ� 1 �߰�
	int x = position - arr; //�߰��Ϸ��� ��ġ �ּ�- ���� ��ġ �ּ�= arr������ �߰��Ϸ��� ��ġ�� index
	if (_size >= _capacity) { //size ��ȭ�� ���� allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size * 2);
		}

	}
	for (int i = _size - 2; i >= x; i--) {//���� size���� 1 �߰� �Ǿ����Ƿ� ���� �ִ� ���� ū ��ġ�� arr[_size-2], 1�� ���̸� 1ĭ�� �ű��
		arr[i + 1] = arr[i];
	}
	arr[x] = value;//���ϴ� ��ġ�� �� �߰�

}

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last) {//array �߰�
	int arraysize = last - first;//�߰��Ϸ��� array�� ũ�� = �� �ּ� - ù �ּ�
	int x = position - arr;//�߰��Ϸ��� ��ġ�� index = position - arr;
	_size = _size + arraysize; //size �߰�
	if (_size >= _capacity) {//size ���濡 ���� capacity ������ ���� allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size * 2);
		}

	}

	for (int i = _size - 1 - arraysize; i >= x; i--) {//arraysize ��ŭ arr�� �� �ű��
		arr[i + arraysize] = arr[i];
	}
	for (int j = 0; j < arraysize; j++) {//arr[x]���� �� �ϳ��� �߰�
		arr[x + j] = *(first + j);
	}
}

void Vector_Rider::erase(iterator position) {
	int x = position - arr;//������� ��ġ�� index
	for (int i = x; i < _size - 1; i++) {//�ϳ��� ������ ���ܿ���
		arr[i] = arr[i + 1];
	}
	_size = _size - 1;//������ �� ���� �ʰ� size 1 ����
}

void Vector_Rider::clear() {//size, capacity, arr ���� 0,0,NULL �� ��ȯ
	_size = 0;
	_capacity = 0;
	arr = NULL;

}

Rider& Vector_Rider::operator[](int index) { // index�� �ش��ϴ� �� ��ȯ
	return arr[index];
}

const Rider& Vector_Rider::operator[](int index) const { //index�� �ش��ϴ� �� ��ȯ. const ver.
	return arr[index];
}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v) {// = operator. �Է¹��� Vector �� ���ο� Vector Class ������ ��� ��ȯ

	_size = v._size; // size, capacity ����
	_capacity = v._capacity;
	arr = new Rider[_capacity];//capacity�� ���߾� ���� �Ҵ�
	for (int i = 0; i < v._size; i++) { //arr[i] �� v.arr[i] ���� ��ȯ
		arr[i] = v.arr[i];
	}
	return *this;
}
