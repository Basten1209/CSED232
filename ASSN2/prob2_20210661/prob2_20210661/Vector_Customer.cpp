#include "Vector_Customer.h"
#include "Customer.h"
#include <iostream>

using namespace std;

Vector_Customer::Vector_Customer() { // 생성자, parameter 없을 때 값 = 0, 0, NULL
	_size = 0;
	_capacity = 0;
	arr = NULL;
}
Vector_Customer::Vector_Customer(int size) { //_size 값을 받는 생성자, 값 = size, size, arr = {0, }
	arr = new Customer[size];
	_size = size;
	_capacity = size;
	for (int i = 0; i < _size; i++) {
		arr[i].Customer::Customer();
	}
}
Vector_Customer::Vector_Customer(int size, const Customer& init) {//_size 값과 값 하나를 받는 생성자. 값 = size, size, arr = {init,NULL, NULL, ,,,, }
	_size = size;
	_capacity = size;
	arr = new Customer[size];
	*arr = init;
}
Vector_Customer::Vector_Customer(int size, const Customer* init) {//_size 값과 float array 하나를 받는 생성자. 값 = size, size, arr = init
	_size = size;
	_capacity = size;
	arr = new Customer[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = *(init + i);
	}
}
Vector_Customer::Vector_Customer(const Vector_Customer& v) {//복사 연산자. _size, _capacity 값은 바로 참조 하여 복사, arr의 값들은 하나씩 for문을 통해 복사.
	
	_size = v._size;
	_capacity = v._capacity;
	arr = new Customer[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = v.arr[i];
	}
}
Vector_Customer::~Vector_Customer() { //소멸자. delete[] 를 통하여 할당 해제.
	delete[] arr;
}
int Vector_Customer::capacity() const { //_capacity 값을 return 하는 함수 const ver.
	return _capacity;
}
int Vector_Customer::size() const {//_size 값을 return 하는 함수, const ver.
	return _size;
}
Vector_Customer::iterator Vector_Customer::begin() {//arr 첫 값 주소 return 하는 함수
	return arr;
}
Vector_Customer::const_iterator Vector_Customer::begin() const { //arr 첫 값 주소 return 하는 함수 , const. ver.
	return arr;
}
Vector_Customer::iterator Vector_Customer::end() { //arr 마지막 값 주소 return하는 함수. 마지막 값 주소 = 첫 값 + _size. 
	return arr+_size;
}
Vector_Customer::const_iterator Vector_Customer::end() const {//arr 마지막 값 주소 return하는 함수, const. ver.
	return arr + _size;
}
Customer& Vector_Customer::front() {//arr 첫 값 return 하는 함수.
	return arr[0];
}
const Customer& Vector_Customer::front() const {//arr 첫 값 return 하는 함수. const ver.
	return arr[0];
}
Customer& Vector_Customer::back() {//arr 마지막 값 return 하는 함수.
	return arr[_size-1];
}
const Customer& Vector_Customer::back() const { //arr 마지막 값 return 하는 함수. const .ver
	
	return arr[_size-1];
}
void Vector_Customer::allocate(int capacity) { 
	Vector_Customer tmp;
	tmp._size = this->_size; //size는 this 값 그대로 넘김
	tmp._capacity = capacity; //capacity는 입력받은 값 사용
	tmp.arr = new Customer[capacity];//capacity에 맞추어 동적 할당
	for(int i = 0; i < _capacity; i++) {//tmp.arr 에 this->arr 복사
		tmp.arr[i] = this->arr[i];
	}
	delete[] this->arr;
	*this = tmp; //tmp 를 *this로 넘김.
}
void Vector_Customer::resize(int size) {
	Vector_Customer tmp;
	tmp._size = size; //_size, _capacity 모두 입력받은 값으로 변경
	tmp._capacity = size;
	tmp.arr = new Customer[_size];//_size에 맞추어 동적 할당
	for (int i = 0; i < tmp._capacity; i++) {//tmp.arr에 this->arr 복사. 
		tmp.arr[i] = this->arr[i];
	}
	delete[] this->arr;
	*this = tmp;//tmp를 *this로 넘김.
}
void Vector_Customer::push_back(const Customer& value) {

	_size = _size + 1;//값 하나 입력 받으니 size 1 추가
	
	if (_size >= _capacity) {//_size가 _capacity 이상일 때 
		if (_size < 5) { //<5의 경우 그 값 그대로 allocate
			allocate(_size);
		}
		else if (_size >= 5) {//>=5인 경우 size 2배로 allocate
			allocate(_size*2);
		}

	}
	arr[_size - 1] = value; //마지막에 값 추가
	
}
void Vector_Customer::pop_back() {//마지막 값 0 으로 변경 후 _size 1 감소
	arr[_size - 1].Customer::Customer();
	_size = _size - 1;
}
void Vector_Customer::insert(iterator position, const Customer& value) {
	_size = _size + 1;//값 하나 추가하니 1 추가
	int x = position - arr; //추가하려는 위치 주소- 시작 위치 주소= arr에서의 추가하려는 위치의 index
	if (_size >= _capacity) { //size 변화에 따른 allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size*2);
		}

	}
	for(int i = _size-2; i >= x; i--) {//기존 size에서 1 추가 되었으므로 값이 있는 가장 큰 위치는 arr[_size-2], 1씩 줄이며 1칸씩 옮기기
		arr[i + 1] = arr[i];
	}
	arr[x] = value;//원하는 위치에 값 추가


}
void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last) {//array 추가
	int arraysize = last - first;//추가하려는 array의 크기 = 끝 주소 - 첫 주소
	int x = position - arr;//추가하려는 위치의 index = position - arr;
	_size = _size + arraysize; //size 추가
	if (_size >= _capacity) {//size 변경에 따른 capacity 변경을 위한 allocate
		if (_size < 5) {
			allocate(_size);
		}
		else if (_size >= 5) {
			allocate(_size*2);
		}

	}

	for (int i = _size - 1-arraysize; i >= x; i--) {//arraysize 만큼 arr의 값 옮기기
		arr[i + arraysize] = arr[i];
	}
	for (int j = 0; j < arraysize; j++) {//arr[x]부터 값 하나씩 추가
		arr[x + j] = *(first+j);
	}
}
void Vector_Customer::erase(iterator position) {
	int x = position - arr;//지우려는 위치의 index
	for (int i = x; i < _size - 1; i++) {//하나씩 앞으로 땡겨오기
		arr[i] = arr[i + 1];
	}
	_size = _size - 1;//마지막 값 읽지 않게 size 1 감소
}
void Vector_Customer::clear() {//size, capacity, arr 각각 0,0,NULL 로 변환
	_size = 0;
	_capacity = 0;
	arr = NULL;
	
}
Customer& Vector_Customer::operator[](int index) { // index에 해당하는 값 반환
	return arr[index];
}
const Customer& Vector_Customer::operator[](int index) const { //index에 해당하는 값 반환. const ver.
	return arr[index];
}
Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v) {// = operator. 입력받은 Vector 를 새로운 Vector Class 변수에 담아 반환

	_size = v._size; // size, capacity 대입
	_capacity = v._capacity;
	arr = new Customer[_capacity];//capacity에 맞추어 동적 할당
	for (int i = 0; i < v._size; i++) { //arr[i] 와 v.arr[i] 각각 반환
		arr[i] = v.arr[i];
	}
	return *this;
}
