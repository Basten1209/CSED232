#ifndef VECTOR_H_
#define VECTOR_H_

using namespace std;

class Vector { //Vector Class ����

private:
	float *arr; //Vector Class�� ��� ���� ����
	int _size;
	int _capacity;

public:
	typedef float* iterator; //iterator Ÿ�� ����
	typedef const float* const_iterator;
	//��� �Լ� ����. �Լ� ���� ���� �ּ��� Vector.cpp ���Ͽ���.
	Vector();  //������ ������ �����ε�
	Vector(int size);
	Vector(int size, const float& init);
	Vector(int size, const float* init);
	Vector(const Vector& v);
	~Vector(); //�Ҹ���
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
	float& operator[](int index); //[] ������
	const float& operator[](int index) const; //[]������ �����ε�
	Vector& operator=(const Vector& v);//=������






};




#endif

