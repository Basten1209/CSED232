#pragma once
#include "WhiteBoard.h"

class AShape
{
private:

protected:

	char alphabet; //���ĺ� ������ protected

public: //������, �Ҹ���, �׸���, ����ϱ� , ������ ũ�� �Լ��� ���� (�� ������ cpp ���Ͽ���)
	AShape();
	virtual ~AShape();
	virtual void draw(WhiteBoard* board) const = 0;
	virtual void print() const = 0;
	virtual int size() const = 0;
};

class APoint : public AShape { //APoint �� AShape�� ���ӵ� class
private:
	int x;
	int y;
public://������, �Ҹ���, �׸���, ����ϱ� , ������ ũ�� �Լ��� ���� (�� ������ cpp ���Ͽ���)
	APoint();
	APoint(int x_, int y_, char alphabet_);
	~APoint();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AVerticalLine : public AShape {//AVerticalLine�� AShape�� ���ӵ� class
private:
	int x;
	int y_start;
	int y_end;
public://������, �Ҹ���, �׸���, ����ϱ� , ������ ũ�� �Լ��� ���� (�� ������ cpp ���Ͽ���)
	AVerticalLine();
	AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
	~AVerticalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AHorizontalLine : public AShape {//AHorizontalLine�� AShape�� ���ӵ� class
private:
	int y;
	int x_start;
	int x_end;
public://������, �Ҹ���, �׸���, ����ϱ� , ������ ũ�� �Լ��� ���� (�� ������ cpp ���Ͽ���)
	AHorizontalLine();
	AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
	~AHorizontalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class ARectangle : public AShape {//ARectangle�� AShape�� ���ӵ� class
private:
	int x_start;
	int x_end;
	int y_start;
	int y_end;
public://������, �Ҹ���, �׸���, ����ϱ� , ������ ũ�� �Լ��� ���� (�� ������ cpp ���Ͽ���)
	ARectangle();
	ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);
	~ARectangle();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};