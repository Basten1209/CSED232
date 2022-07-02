#include <iostream>
#include "WhiteBoard.h"

using namespace std;

WhiteBoard::WhiteBoard() {//생성자
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = 'a';
		}
	}
}
WhiteBoard::~WhiteBoard() {//소멸자

}
void WhiteBoard::fillPoint(int x, int y, char alphabet) {//화이트보드 한 칸 채우기
	board[y][x] = alphabet;
}
void WhiteBoard::reset() {//보드 리셋
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = '*';
		}
	}
}
void WhiteBoard::display() const {//보드 디스플레이, 반복문으로 출력
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