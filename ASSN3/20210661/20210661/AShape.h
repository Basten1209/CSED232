#pragma once
#include "WhiteBoard.h"

class AShape
{
private:

protected:

	char alphabet; //알파벳 변수만 protected

public: //생성자, 소멸자, 그리기, 출력하기 , 사이즈 크기 함수로 구성 (각 설명은 cpp 파일에서)
	AShape();
	virtual ~AShape();
	virtual void draw(WhiteBoard* board) const = 0;
	virtual void print() const = 0;
	virtual int size() const = 0;
};

class APoint : public AShape { //APoint 는 AShape에 종속된 class
private:
	int x;
	int y;
public://생성자, 소멸자, 그리기, 출력하기 , 사이즈 크기 함수로 구성 (각 설명은 cpp 파일에서)
	APoint();
	APoint(int x_, int y_, char alphabet_);
	~APoint();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AVerticalLine : public AShape {//AVerticalLine은 AShape에 종속된 class
private:
	int x;
	int y_start;
	int y_end;
public://생성자, 소멸자, 그리기, 출력하기 , 사이즈 크기 함수로 구성 (각 설명은 cpp 파일에서)
	AVerticalLine();
	AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
	~AVerticalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AHorizontalLine : public AShape {//AHorizontalLine은 AShape에 종속된 class
private:
	int y;
	int x_start;
	int x_end;
public://생성자, 소멸자, 그리기, 출력하기 , 사이즈 크기 함수로 구성 (각 설명은 cpp 파일에서)
	AHorizontalLine();
	AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
	~AHorizontalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class ARectangle : public AShape {//ARectangle은 AShape에 종속된 class
private:
	int x_start;
	int x_end;
	int y_start;
	int y_end;
public://생성자, 소멸자, 그리기, 출력하기 , 사이즈 크기 함수로 구성 (각 설명은 cpp 파일에서)
	ARectangle();
	ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);
	~ARectangle();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};