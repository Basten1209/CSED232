#pragma once
#include "AShapeList.h"
#include "WhiteBoard.h"

class Menu
{
private:
	bool is_running;//���α׷� ���࿩��
	AShapeList* shape_list;//��ũ�帮��Ʈ
	WhiteBoard* board;//����
public://�޴��� �����ְ� �޴��� ���� �Լ� �����ϴ� �Լ����� ���� class. �Լ� ������ cpp ���Ͽ���.
	Menu(WhiteBoard* board, AShapeList* shape_list);
	~Menu();
	void display() const;
	bool getRunning() const;
	void getUserInput();
	void addAShape() const;
	void deleteAShape() const;
};

