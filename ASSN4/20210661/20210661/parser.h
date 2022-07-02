#define _CRT_SECURE_NO_WARNINGS//strcpy��������
#pragma once
#include "canvas2d.h"
#include <string>
#include <iostream>

class parser //parser class
{
private:

public:
	canvas2d parse_canvas(const std::string& line) { //parse_canvas

		std::stringstream _line(line); //line�� stringstream���� ����
		std::string tempwidth; //�ʺ� ������ �ӽ� string
		std::string tempheight; //���̸� ������ �ӽ� string
		std::string tempchar; //���ڸ� ������ �ӽ� string
		getline(_line, tempwidth, ','); //getline���� �ʺ� �ޱ�
		int tempw = std::stoi(tempwidth); //int�� ��ȯ�Ͽ� ����
		getline(_line, tempheight, ','); //getline���� ���� �ޱ�
		int temph = std::stoi(tempheight);//int�� ��ȯ�Ͽ� ����
		getline(_line, tempchar);//getline���� char �ޱ�
		char tempc[2];//char�� �ޱ� ���� char array.(string�� �� ���� null���־ 1+1 = 2ĭ �ʿ�)
		strcpy(tempc, tempchar.c_str());//strcpy�� char������ ���� �ޱ�
		canvas2d* can = new canvas2d(tempw, temph, tempc[0]); //canvas2d ����
		return *can; //�ּ� ����
	}

	geometry* parse_geometry(const std::string& line) { //parse_geometry
		std::stringstream _line(line);
		std::string classtype; //classtype�� �ޱ� ���� string
		getline(_line, classtype, ',');//getline���� classtype���
		std::string intfloat; //int����, float���� �ޱ� ���� string
		getline(_line, intfloat, ',');//getline���� intfloat���
		std::string tempint;//�ӽ÷� ���� �ޱ� ���� string
		geometry geom;
		if (classtype == "point") {//point
			if (intfloat == "int") {//int�϶�,
				int temparri[5] = { 0,0,0,0,0 }; //temparri ����
				int counti = 0;
				while (getline(_line, tempint, ',')) {
					temparri[counti] = std::stoi(tempint); //�Է¹��� �� tempparri�� �Է�
					counti++; //�Է¹��� �� count
				}
				if (counti == 2) { //count�� ���� ���߾� point �����Ͽ� return
					point<int, 2>* p = new point<int, 2> (temparri);
					return p;
				}
				else if (counti == 3) {
					point<int, 3>* p = new point<int, 3>(temparri);
					return p;
				}
				else if (counti == 4) {
					point<int, 4>* p = new point<int,4>(temparri);
					return p;
				}
				else if (counti == 5) {
					point<int, 5>* p=new point<int, 5>(temparri);
					return p;
				}
			}
			else if (intfloat == "float") {//float�� ��쵵 int�� �����ϰ� ����
				float temparrf[5] = { 0,0,0,0,0 };
				int countf = 0;
				while (getline(_line, tempint, ',')) {
					temparrf[countf] = std::stof(tempint);
					countf++;
				}
				if (countf == 2) {
					point<float, 2> *p = new point<float, 2>(temparrf);
					return p;
				}
				else if (countf == 3) {
					point<float, 3> *p = new point<float, 3>(temparrf);
					return p;
				}
				else if (countf == 4) {
					point<float, 4> *p = new point<float, 4>(temparrf);
					return p;
				}
				else if (countf == 5) {
					point<float, 5> *p = new point<float, 5>(temparrf);
					return p;
				}
			}
		}
		else if (classtype == "rectangle") {//rectangle
			if (intfloat == "int") {//int�϶�
				std::string tempvaluei;
				int arr[4] = { 0,0,0,0 };
				int count = 0;
				while (getline(_line, tempvaluei, ',')) {
					arr[count] = std::stoi(tempvaluei);//�� �ϳ��� �Է�
					count++;
				}
				rectangle<int> *rec = new rectangle<int>(arr[0], arr[1], arr[2], arr[3]);//rec ���� �� ��ȯ
				return rec;
			}
			else if (intfloat == "float") {//float�� int�� �����ϰ� ����
				std::string tempvaluef;
				float arr[4] = { 0,0,0,0 };
				int count = 0;
				while (getline(_line, tempvaluef, ',')) {
					arr[count] = std::stof(tempvaluef);
					count++;
				}
				rectangle<float> *rec =new rectangle<float>(arr[0], arr[1], arr[2], arr[3]);
				return rec;
			}
		}
	}
};

