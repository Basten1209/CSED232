#ifndef VECTOR_H_
#define VECTOR_H_

using namespace std;

class Vector { //Vector Class 선언

private:
	float *arr; //Vector Class의 멤버 변수 선언
	int _size;
	int _capacity;

public:
	typedef float* iterator; //iterator 타입 선언
	typedef const float* const_iterator;
	//멤버 함수 선언. 함수 선언 설명 주석은 Vector.cpp 파일에서.
	Vector();  //생성자 여러개 오버로딩
	Vector(int size);
	Vector(int size, const float& init);
	Vector(int size, const float* init);
	Vector(const Vector& v);
	~Vector(); //소멸자
	int capacity() const;
	int size() const;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	float& front();
	const float& front() const;
	float& back();
	const float& back() const;
	void allocate(int capacity);
	void resize(int size);
	void push_back(const float& value);
	void pop_back();
	void insert(iterator position, const float& value);
	void insert(iterator position, const float* first, const float* last);
	void erase(iterator position);
	void clear();
	float& operator[](int index); //[] 연산자
	const float& operator[](int index) const; //[]연산자 오버로딩
	Vector& operator=(const Vector& v);//=연산자






};




#endif

