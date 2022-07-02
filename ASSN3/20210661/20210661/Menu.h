#pragma once
#include "AShapeList.h"
#include "WhiteBoard.h"

class Menu
{
private:
	bool is_running;//프로그램 실행여부
	AShapeList* shape_list;//링크드리스트
	WhiteBoard* board;//보드
public://메뉴를 보여주고 메뉴에 따른 함수 실행하는 함수들이 모인 class. 함수 설명은 cpp 파일에서.
	Menu(WhiteBoard* board, AShapeList* shape_list);
	~Menu();
	void display() const;
	bool getRunning() const;
	void getUserInput();
	void addAShape() const;
	void deleteAShape() const;
};

