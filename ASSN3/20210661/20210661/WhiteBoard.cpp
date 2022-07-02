#include <iostream>
#include "WhiteBoard.h"

using namespace std;

WhiteBoard::WhiteBoard() {//������
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = 'a';
		}
	}
}
WhiteBoard::~WhiteBoard() {//�Ҹ���

}
void WhiteBoard::fillPoint(int x, int y, char alphabet) {//ȭ��Ʈ���� �� ĭ ä���
	board[y][x] = alphabet;
}
void WhiteBoard::reset() {//���� ����
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = '*';
		}
	}
}
void WhiteBoard::display() const {//���� ���÷���, �ݺ������� ���
	cout << "[WHITEBOARD]" << endl;
	cout << "===============" << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "===============" << endl;
}