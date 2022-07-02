#include <iostream>
#include "Menu.h"
#include "WhiteBoard.h"
#include "AShapeList.h"
using namespace std;

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) {//������
	is_running = 1;
	this->board = board;
	this->shape_list = shape_list;
}
Menu::~Menu() {

}
void Menu::display() const {//�޴� ���
	cout << "==============="<<endl;
	cout << "[SELECT MENU]" << endl;
	cout << "===============" << endl;
	cout << "1. ADD NEW SHAPE" << endl;
	cout << "2. DELETE EXISTING SHAPE" << endl;
	cout << "3. EXIT" << endl;
	cout << ">>";
}
bool Menu::getRunning() const {//���࿩�� ����, 1= ����, 0=����
	return is_running;
}
void Menu::getUserInput() { //���� �Է¿� ���� �Լ� ����
	int ans;
	cin >> ans;
	switch (ans) {
	case 1: //�����߰�
		addAShape();
		break;
	case 2://��������
		deleteAShape();
		break;
	case 3://����
		cout << "EXIT PROGRAM";
		is_running = 0;
		break;
	default://�̿� ����ó��
		cout << "WRONG INPUT! TYPE AGAIN." << endl;
		break;
	
	}
}
void Menu::addAShape() const {//�����߰�
	char tempalp;//���ĺ� ��� ����
	int xs, ys, xe, ye;//������ ��� ����
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

	if (xs > xe) {//����ó��1
		cout << "ERROR! X_START EXCEED X_END" << endl;
	}
	else if (ys > ye) {//����ó��2
		cout << "ERROR! Y_START EXCEED Y_END" << endl;
	}
	else if (xs < 0 || xe < 0 || ys < 0 || ye < 0) {//����ó��3
		cout << "ERROR! COORDINATE CAN'T BE NEGATIVE VALUE" << endl;
	}
	else if (xs > 14 || xe > 14 || ys > 14 || ye > 14) {//����ó��4
		cout << "ERROR! INPUT EXCEED WHITBOARD SIZE" << endl;
	}
	else {
		if ((xs == xe) && (ys == ye)) {//APoint ����
			APoint* temp = new APoint(xs, ys, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New APoint Added with size : " << temp->size() << endl;
		}
		if ((xs == xe) && (ye > ys)) {//AVerticalLine ����
			AVerticalLine *temp = new AVerticalLine(xs, ys, ye, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New AVerticalLine Added with size : " << temp->size() << endl;
		}
		if ((xe > xs) && (ys == ye)) {//AHorizonLine ����
			AHorizontalLine *temp = new AHorizontalLine(ys, xs, xe, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New AHorizontalLine Added with size : " << temp->size() << endl;
		}
		if ((xe > xs) && (ye > ys)) {//ARectangle ����
			ARectangle *temp = new ARectangle(xs, xe, ys, ye, tempalp);
			shape_list->addNewAShape(temp);
			cout << "New ARextangle Added with size : " << temp->size() << endl;
		}
	}
}
void Menu::deleteAShape() const {//AShape ����
	if (shape_list->getSize() == 0) {//�� ��� ����ó��
		cout << "ASHAPE LIST IS EMPTY" << endl;
	}
	else {
		int num; //������ �ε��� ���� ����
		cout << "CHOOSE INDEX OF ASHAPE THAT YOU WANT TO REMOVE" << endl;
		cout << "[=======LIST OF ASHAPE========]" << endl;
		cout << "CURRENT SIZE : " << shape_list->getSize() << endl;
		shape_list->displayAShapeList();//����Ʈ �����ְ�
		cin >> num;//���� ����

		if (num < 0 || num >= shape_list->getSize()) {//����ó��
			cout << "ERROR! INDEX EXCEED SIZE OF ASHAPELIST" << endl;
		}
		else {
			delete shape_list->popNodeByIdx(num);//��� ����
		}
	}
}