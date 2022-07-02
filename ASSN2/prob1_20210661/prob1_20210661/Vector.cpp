#include <iostream>
#include "Vector.h"

Vector::Vector() { // ������, parameter ���� �� �� = 0, 0, NULL
	_size = 0;
	_capacity = 0;
	arr = NULL;
}
Vector::Vector(int size) { //_size ���� �޴� ������, �� = size, size, arr = {0, }
	arr = new float[size];
	_size = size;
	_capacity = size;
	for (int i = 0; i < _size; i++) {
		arr[i] = 0;
	}
}
Vector::Vector(int size, const float& init){//_size ���� �� �ϳ��� �޴� ������. �� = size, size, arr = {init,NULL, NULL, ,,,, }
	_size = size;
	_capacity = size;
	arr = new float[size];
	*arr = init;
}
Vector::Vector(int size, const float* init) {//_size ���� float array �ϳ��� �޴� ������. �� = size, size, arr = init
	_size = size;
	_capacity = size;
	arr = new float[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = *(init + i);
	}
}
Vector::Vector(const Vector& v) {//���� ������. _size, _capacity ���� �ٷ� ���� �Ͽ� ����, arr�� ������ �ϳ��� for���� ���� ����.
	
	_size = v._size;
	_capacity = v._capacity;
	arr = new float[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = v.arr[i];
	}
}
Vector::~Vector() { //�Ҹ���. delete[] �� ���Ͽ� �Ҵ� ����.
	delete[] arr;
}
int Vector::capacity() const { //_capacity ���� return �ϴ� �Լ� const ver.
	return _capacity;
}
int Vector::size() const {//_size ���� return �ϴ� �Լ�, const ver.
	return _size;
}
Vector::iterator Vector::begin() {//arr ù �� �ּ� return �ϴ� �Լ�
	return arr;
}
Vector::const_iterator Vector::begin() const { //arr ù �� �ּ� return �ϴ� �Լ� , const. ver.
	return arr;
}
Vector::iterator Vector::end() { //arr ������ �� �ּ� return�ϴ� �Լ�. ������ �� �ּ� = ù �� + _size. 
	return arr+_size;
}
Vector::const_iterator Vector::end() const {//arr ������ �� �ּ� return�ϴ� �Լ�, const. ver.
	return arr + _size;
}
float& Vector::front() {//arr ù �� return �ϴ� �Լ�.
	return arr[0];
}
const float& Vector::front() const {//arr ù �� return �ϴ� �Լ�. const ver.
	return arr[0];
}
float& Vector::back() {//arr ������ �� return �ϴ� �Լ�.
	return arr[_size-1];
}
const float& Vector::back() const { //arr ������ �� return �ϴ� �Լ�. const .ver
	
	return arr[_size-1];
}
void Vector::allocate(int capacity) { 
	Vector tmp;
	tmp._size = this->_size; //size�� this �� �״�� �ѱ�
	tmp._capacity = capacity; //capacity�� �Է¹��� �� ���
	tmp.arr = new float[capacity];//capacity�� ���߾� ���� �Ҵ�
	for (int i = 0; i < _capacity; i++) {//tmp.arr �� this->arr ����
		tmp.arr[i] = this->arr[i];
	}
	*this = tmp; //tmp �� *this�� �ѱ�.
}
void Vector::resize(int size) {
	Vector tmp;
	tmp._size = size; //_size, _capacity ��� �Է¹��� ������ ����
	tmp._capacity = size;
	tmp.arr = new float[_size];//_size�� ���߾� ���� �Ҵ�
	for (int i = 0; i < tmp._capacity; i++) {//tmp.arr�� this->arr ����. 
		tmp.arr[i] = this->arr[i];
	}
	*this = tmp;//tmp�� *this�� �ѱ�.
}
void Vector::push_back(const float& value) {

	_size = _size + 1;//�� �ϳ� �Է� ������ size 1 �߰�
	
	if (_size >= _capacity) {//_size�� _capacity �̻��� �� 
		if (_size < 5) { //<5�� ��� �� �� �״�� allocate
			allocate(_size);
		}
		else if (_size >= 5) {//>=5�� ��� size 2��� allocate
			allocate(_size*2);
		}

	}
	arr[_size - 1] = value; //�������� �� �߰�
	
}
void Vector::pop_back() {//������ �� 0 ���� ���� �� _size 1 ����
	arr[_size - 1] = 0;
	_size = _size - 1;
}
void Vector::insert(iterator position, const float& value) {
	_size = _size + 1;//�� �ϳ� �߰��ϴ� 1 �߰�
	int x = position - arr; //�߰��Ϸ��� ��ġ �ּ�- ���� ��ġ �ּ�= arr������ �߰��Ϸ��� ��ġ�� index
	if (_size >= _capacity) { //size ��ȭ�� ���� allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size*2);
		}

	}
	for (int i = _size-2; i >= x; i--) {//���� size���� 1 �߰� �Ǿ����Ƿ� ���� �ִ� ���� ū ��ġ�� arr[_size-2], 1�� ���̸� 1ĭ�� �ű��
		arr[i + 1] = arr[i];
	}
	arr[x] = value;//���ϴ� ��ġ�� �� �߰�


}
void Vector::insert(iterator position, const float* first, const float* last) {//array �߰�
	int arraysize = last - first;//�߰��Ϸ��� array�� ũ�� = �� �ּ� - ù �ּ�
	int x = position - arr;//�߰��Ϸ��� ��ġ�� index = position - arr;
	_size = _size + arraysize; //size �߰�
	if (_size >= _capacity) {//size ���濡 ���� capacity ������ ���� allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size*2);
		}

	}

	for (int i = _size - 1-arraysize; i >= x; i--) {//arraysize ��ŭ arr�� �� �ű��
		arr[i + arraysize] = arr[i];
	}
	for (int j = 0; j < arraysize; j++) {//arr[x]���� �� �ϳ��� �߰�
		arr[x + j] = *(first+j);
	}
}
void Vector::erase(iterator position) {
	int x = position - arr;//������� ��ġ�� index
	for (int i = x; i < _size - 1; i++) {//�ϳ��� ������ ���ܿ���
		arr[i] = arr[i + 1];
	}
	_size = _size - 1;//������ �� ���� �ʰ� size 1 ����
}
void Vector::clear() {//size, capacity, arr ���� 0,0,NULL �� ��ȯ
	_size = 0;
	_capacity = 0;
	arr = NULL;
	
}
float& Vector::operator[](int index) { // index�� �ش��ϴ� �� ��ȯ
	return arr[index];
}
const float& Vector::operator[](int index) const { //index�� �ش��ϴ� �� ��ȯ. const ver.
	return arr[index];
}
Vector& Vector::operator=(const Vector& v) {// = operator. �Է¹��� Vector �� ���ο� Vector Class ������ ��� ��ȯ

	_size = v._size; // size, capacity ����
	_capacity = v._capacity;
	arr = new float[_capacity];//capacity�� ���߾� ���� �Ҵ�
	for (int i = 0; i < v._size; i++) { //arr[i] �� v.arr[i] ���� ��ȯ
		arr[i] = v.arr[i];
	}
	return *this;
}
