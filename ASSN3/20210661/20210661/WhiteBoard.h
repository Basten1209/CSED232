#pragma once
class WhiteBoard //WhiteBoard Ŭ����.
{
private:
	char board[15][15];
public: //���� ���, ���� �������� ä���, ���� ������ �����ϴ� Ŭ����. �Լ� ������ cpp ���Ͽ���.
	WhiteBoard();
	~WhiteBoard();
	void fillPoint(int x, int y, char alphabet);
	void reset();
	void display() const;
};

