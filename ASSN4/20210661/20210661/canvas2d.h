#pragma once
#include <iostream>
#include <vector>
#include "geometry.h"


class canvas2d : public std::vector<geometry*> //canvas2d는 std::vector<geometry*>를 상속받는 class
{
private: //너비, 높이, 빈공간을 채울 문자, 캔버스를 private로 지님
	int width;
	int height;
	char c_empty;
	float **canvas;
public:
	canvas2d(int width, int height, char c_empty) {//생성자. 멤버변수 값 입력
		this->width = width;
		this->height = height;
		this->c_empty = c_empty;

		canvas = new float* [height]; //캔버스 동적 할당
		for (int i = 0; i < height; i++)
			canvas[i] = new float[width];

		for (int i = 0; i < height; i++) {//캔버스의 모든 칸에 초기값 0 입력
			for (int j = 0; j < width; j++) {
				canvas[i][j] = 0;
			}
		}
	}
	~canvas2d() { //소멸자, 동적할당 해제
		for (int i = 0; i < height; i++) {
			delete[] canvas[i];
		}

		delete[] canvas;
	}
	void draw2stdout() {

		std::vector<geometry*>::iterator it; //iterator 선언, geometry를 받아 draw2canvas 호출 반복
		for (it = this->begin(); it != this->end(); it++) {
			(*it)->draw2canvas(canvas, width, height); 
		}
		for (int i = 0; i < height; i++) {//캔버스 출력
			for (int j = 0; j < width; j++) {
				if (canvas[i][j] > 0) { //값이 존재하는 경우
					int temp = canvas[i][j];
					temp = temp % 10; //10의 나머지를 출력
					std::cout << temp;
				}
				else
					std::cout << c_empty; //빈 값의 경우 c_empty 출력
			}
			std::cout << "\n";
		}
	}
};

