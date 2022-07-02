#pragma once
class WhiteBoard //WhiteBoard 클래스.
{
private:
	char board[15][15];
public: //보드 출력, 보드 도형으로 채우기, 보드 리셋을 수행하는 클래스. 함수 설명은 cpp 파일에서.
	WhiteBoard();
	~WhiteBoard();
	void fillPoint(int x, int y, char alphabet);
	void reset();
	void display() const;
};

