#pragma once
#include <iostream>
#include <vector>
#include "geometry.h"


class canvas2d : public std::vector<geometry*> //canvas2d�� std::vector<geometry*>�� ��ӹ޴� class
{
private: //�ʺ�, ����, ������� ä�� ����, ĵ������ private�� ����
	int width;
	int height;
	char c_empty;
	float **canvas;
public:
	canvas2d(int width, int height, char c_empty) {//������. ������� �� �Է�
		this->width = width;
		this->height = height;
		this->c_empty = c_empty;

		canvas = new float* [height]; //ĵ���� ���� �Ҵ�
		for (int i = 0; i < height; i++)
			canvas[i] = new float[width];

		for (int i = 0; i < height; i++) {//ĵ������ ��� ĭ�� �ʱⰪ 0 �Է�
			for (int j = 0; j < width; j++) {
				canvas[i][j] = 0;
			}
		}
	}
	~canvas2d() { //�Ҹ���, �����Ҵ� ����
		for (int i = 0; i < height; i++) {
			delete[] canvas[i];
		}

		delete[] canvas;
	}
	void draw2stdout() {

		std::vector<geometry*>::iterator it; //iterator ����, geometry�� �޾� draw2canvas ȣ�� �ݺ�
		for (it = this->begin(); it != this->end(); it++) {
			(*it)->draw2canvas(canvas, width, height); 
		}
		for (int i = 0; i < height; i++) {//ĵ���� ���
			for (int j = 0; j < width; j++) {
				if (canvas[i][j] > 0) { //���� �����ϴ� ���
					int temp = canvas[i][j];
					temp = temp % 10; //10�� �������� ���
					std::cout << temp;
				}
				else
					std::cout << c_empty; //�� ���� ��� c_empty ���
			}
			std::cout << "\n";
		}
	}
};

