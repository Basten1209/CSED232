#include <iostream>
#include "AShape.h"
#include "WhiteBoard.h"

using namespace std;

AShape::AShape() { //������
	alphabet = 'a';
}
AShape::~AShape() {//�Ҹ���

}
APoint::APoint() {//������
	x = 0;
	y = 0;
	alphabet = 'a';
}
APoint::APoint(int x_, int y_, char alphabet_) {//������(�����ε�)
	x = x_;
	y = y_;
	alphabet = alphabet_;
}
APoint::~APoint() {//�Ҹ���

}
void APoint::draw(WhiteBoard* board) const { //APoint �׸���(fillpoint)
	board->fillPoint(x, y, alphabet);
}
void APoint::print() const {//APoint ��� ���� ���
	cout <<
	") APoint with [alphabet: " << alphabet
	<< "] and [x: " << x << "] [y: " << y << "][size:" <<size() << "]" << endl;

	//AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12][size:3]
}
int APoint::size() const {//������ ���
	return 1;
}
AVerticalLine::AVerticalLine() {//������
	x = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';
}
AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_) {//������ �����ε�
	x = x_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}
AVerticalLine::~AVerticalLine() {//�Ҹ���

}
void AVerticalLine::draw(WhiteBoard* board) const { //AVerticalline �׸���, y �� �ٲ㰡�� �ݺ������� fillboard,
		for (int b = y_start; b <= y_end; b++) {
			board->fillPoint(x, b, alphabet);
		}
}
void AVerticalLine::print() const {//��� ���� ���
	cout << ") AVerticalLine with[alphabet:" 
	<< alphabet << "] and [x:" << x << "][y_start:"<< y_start << "][y_end:" << y_end << "][size:"
	<< size() << "]" << endl;
}
int AVerticalLine::size() const { //������ ���
	return (y_end - y_start + 1);
}
AHorizontalLine::AHorizontalLine() {//������
	x_start = 0;
	x_end = 0;
	y = 0;
	alphabet = 'a';
}
AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_) {//������ �����ε�
	y = y_;
	x_start = x_start_;
	x_end = x_end_;
	alphabet = alphabet_;
}
AHorizontalLine::~AHorizontalLine() {//�Ҹ���

}
void AHorizontalLine::draw(WhiteBoard* board) const {//AHorizontalLine �׸���, x�� �ٲ㰡�� �ݺ������� fillboard
	for (int a = x_start; a <= x_end; a++) {
			board->fillPoint(a, y, alphabet);
	}
}
void AHorizontalLine::print() const { //��� ���� ���
	cout << ") AHorizontalLine with[alphabet:"<<alphabet
	<<"] and [y:"<<y<<"][x_start:"<<x_start<<"][x_end:"<<x_end<<"][size:"<<size() << "]" << endl;
}
int AHorizontalLine::size() const { //������ ���
	return (x_end - x_start + 1);
}
ARectangle::ARectangle() { //������
	x_start = 0;
	x_end = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';
}
ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_) { //������(�����ε�)
	x_start = x_start_;
	x_end = x_end_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}
ARectangle::~ARectangle() { //�Ҹ���
	
}
void ARectangle::draw(WhiteBoard* board) const { //�׸���, x, y, ���� �ݺ������� fillboard ����
	for (int a = x_start; a <= x_end; a++) {
		for (int b = y_start; b <= y_end; b++) {
			board->fillPoint(a, b, alphabet);
		}
	}
}
void ARectangle::print() const {//��� ���� ���
	cout << ") ARectangle with[alphabet:"
	<< alphabet << "] and [x_start:" << x_start << "][x_end:" << x_end
		<< "][y_start:" << y_start << "][y_end:" << y_end << "][size:" << size() << "]" << endl;
}
int ARectangle::size() const {//������ ���
	return (y_end - y_start + 1) * (x_end - x_start + 1);
}