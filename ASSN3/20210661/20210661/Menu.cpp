#include <iostream>
#include "Menu.h"
#include "WhiteBoard.h"
#include "AShapeList.h"
using namespace std;

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) {//생성자
	is_running = 1;
	this->board = board;
	this->shape_list = shape_list;
}
Menu::~Menu() {

}
void Menu::display() const {//메뉴 출력
	cout << "==============="<<endl;
	cout << "[SELECT MENU]" << endl;
	cout << "===============" << endl;
	cout << "1. ADD NEW SHAPE" << endl;
	cout << "2. DELETE EXISTING SHAPE" << endl;
	cout << "3. EXIT" << endl;
	cout << ">>";
}
bool Menu::getRunning() const {//실행여부 리턴, 1= 실행, 0=종료
	return is_running;
}
void Menu::getUserInput() { //유저 입력에 따른 함수 실행
	int ans;
	cin >> ans;
	switch (ans) {
	case 1: //도형추가
		addAShape();
		break;
	case 2://도형삭제
		deleteAShape();
		break;
	case 3://종료
		cout << "EXIT PROGRAM";
		is_running = 0;
		break;
	default://이외 예외처리
		cout << "WRONG INPUT! TYPE AGAIN." << endl;
		break;
	
	}
}
void Menu::addAShape() const {//도형추가
	char tempalp;//알파벳 담는 변수
	int xs, ys, xe, ye;//데이터 담는 변수
	cout << "[ADD NEW ASHAPE]" << endl;
	cout << "ENTER ALPHABET>>";
	cin >> tempalp;
	cout << "ENTER X_START>>";
	cin >> xs;
	cout << "ENTER X_END>>";
	cin >> xe;
	cout << "ENTER Y_START>>";
	cin >> ys;
	cout << "ENTER Y_END>>";
	cin >> ye;

	if (xs > xe) {//예외처리1
		cout << "ERROR! X_START EXCEED X_END" << endl;
	}
	else if (ys > ye) {//예외처리2
		cout << "ERROR! Y_START EXCEED Y_END" << endl;
	}
	else if (xs < 0 || xe < 0 || ys < 0 || ye < 0) {//예외처리3
		cout << "ERROR! COORDINATE CAN'T BE NEGATIVE VALUE" << endl;
	}
	else if (xs > 14 || xe > 14 || ys > 14 || ye > 14) {//예외처리4
		cout << "ERROR! INPUT EXCEED WHITBOARD SIZE" << endl;
	}
	else {
		if ((xs == xe) && (ys == ye)) {//APoint 생성
			APoint* temp = new APoint(xs, ys, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New APoint Added with size : " << temp->size() << endl;
		}
		if ((xs == xe) && (ye > ys)) {//AVerticalLine 생성
			AVerticalLine *temp = new AVerticalLine(xs, ys, ye, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New AVerticalLine Added with size : " << temp->size() << endl;
		}
		if ((xe > xs) && (ys == ye)) {//AHorizonLine 생성
			AHorizontalLine *temp = new AHorizontalLine(ys, xs, xe, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New AHorizontalLine Added with size : " << temp->size() << endl;
		}
		if ((xe > xs) && (ye > ys)) {//ARectangle 생성
			ARectangle *temp = new ARectangle(xs, xe, ys, ye, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New ARextangle Added with size : " << temp->size() << endl;
		}
	}
}
void Menu::deleteAShape() const {//AShape 삭제
	if (shape_list->getSize() == 0) {//빈 경우 예외처리
		cout << "ASHAPE LIST IS EMPTY" << endl;
	}
	else {
		int num; //삭제할 인덱스 담을 변수
		cout << "CHOOSE INDEX OF ASHAPE THAT YOU WANT TO REMOVE" << endl;
		cout << "[=======LIST OF ASHAPE========]" << endl;
		cout << "CURRENT SIZE : " << shape_list->getSize() << endl;
		shape_list->displayAShapeList();//리스트 보여주고
		cin >> num;//변수 받음

		if (num < 0 || num >= shape_list->getSize()) {//예외처리
			cout << "ERROR! INDEX EXCEED SIZE OF ASHAPELIST" << endl;
		}
		else {
			delete shape_list->popNodeByIdx(num);//노드 삭제
		}
	}
}