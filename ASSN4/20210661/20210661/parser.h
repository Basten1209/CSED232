#define _CRT_SECURE_NO_WARNINGS//strcpy쓰기위함
#pragma once
#include "canvas2d.h"
#include <string>
#include <iostream>

class parser //parser class
{
private:

public:
	canvas2d parse_canvas(const std::string& line) { //parse_canvas

		std::stringstream _line(line); //line을 stringstream으로 받음
		std::string tempwidth; //너비를 저장할 임시 string
		std::string tempheight; //높이를 저장할 임시 string
		std::string tempchar; //문자를 저장할 임시 string
		getline(_line, tempwidth, ','); //getline으로 너비 받기
		int tempw = std::stoi(tempwidth); //int로 변환하여 저장
		getline(_line, tempheight, ','); //getline으로 높이 받기
		int temph = std::stoi(tempheight);//int로 변환하여 저장
		getline(_line, tempchar);//getline으로 char 받기
		char tempc[2];//char를 받기 위한 char array.(string은 맨 뒤의 null값있어서 1+1 = 2칸 필요)
		strcpy(tempc, tempchar.c_str());//strcpy로 char형으로 문자 받기
		canvas2d* can = new canvas2d(tempw, temph, tempc[0]); //canvas2d 생성
		return *can; //주소 리턴
	}

	geometry* parse_geometry(const std::string& line) { //parse_geometry
		std::stringstream _line(line);
		std::string classtype; //classtype을 받기 위한 string
		getline(_line, classtype, ',');//getline으로 classtype얻기
		std::string intfloat; //int인지, float인지 받기 위한 string
		getline(_line, intfloat, ',');//getline으로 intfloat얻기
		std::string tempint;//임시로 값을 받기 위한 string
		geometry geom;
		if (classtype == "point") {//point
			if (intfloat == "int") {//int일때,
				int temparri[5] = { 0,0,0,0,0 }; //temparri 선언
				int counti = 0;
				while (getline(_line, tempint, ',')) {
					temparri[counti] = std::stoi(tempint); //입력받은 값 tempparri에 입력
					counti++; //입력받은 수 count
				}
				if (counti == 2) { //count한 수에 맞추어 point 선언하여 return
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
			else if (intfloat == "float") {//float의 경우도 int와 동일하게 진행
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
			if (intfloat == "int") {//int일때
				std::string tempvaluei;
				int arr[4] = { 0,0,0,0 };
				int count = 0;
				while (getline(_line, tempvaluei, ',')) {
					arr[count] = std::stoi(tempvaluei);//값 하나씩 입력
					count++;
				}
				rectangle<int> *rec = new rectangle<int>(arr[0], arr[1], arr[2], arr[3]);//rec 선언 후 반환
				return rec;
			}
			else if (intfloat == "float") {//float도 int와 동일하게 구현
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

