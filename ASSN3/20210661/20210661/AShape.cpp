#include <iostream>
#include "AShape.h"
#include "WhiteBoard.h"

using namespace std;

AShape::AShape() { //생성자
	alphabet = 'a';
}
AShape::~AShape() {//소멸자

}
APoint::APoint() {//생성자
	x = 0;
	y = 0;
	alphabet = 'a';
}
APoint::APoint(int x_, int y_, char alphabet_) {//생성자(오버로딩)
	x = x_;
	y = y_;
	alphabet = alphabet_;
}
APoint::~APoint() {//소멸자

}
void APoint::draw(WhiteBoard* board) const { //APoint 그리기(fillpoint)
	board->fillPoint(x, y, alphabet);
}
void APoint::print() const {//APoint 멤버 변수 출력
	cout <<
	") APoint with [alphabet: " << alphabet
	<< "] and [x: " << x << "] [y: " << y << "][size:" <<size() << "]" << endl;

	//AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12][size:3]
}
int APoint::size() const {//사이즈 출력
	return 1;
}
AVerticalLine::AVerticalLine() {//생성자
	x = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';
}
AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_) {//생성자 오버로딩
	x = x_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}
AVerticalLine::~AVerticalLine() {//소멸자

}
void AVerticalLine::draw(WhiteBoard* board) const { //AVerticalline 그리기, y 값 바꿔가며 반복문으로 fillboard,
		for (int b = y_start; b <= y_end; b++) {
			board->fillPoint(x, b, alphabet);
		}
}
void AVerticalLine::print() const {//멤버 변수 출력
	cout << ") AVerticalLine with[alphabet:" 
	<< alphabet << "] and [x:" << x << "][y_start:"<< y_start << "][y_end:" << y_end << "][size:"
	<< size() << "]" << endl;
}
int AVerticalLine::size() const { //사이즈 출력
	return (y_end - y_start + 1);
}
AHorizontalLine::AHorizontalLine() {//생성자
	x_start = 0;
	x_end = 0;
	y = 0;
	alphabet = 'a';
}
AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_) {//생성자 오버로딩
	y = y_;
	x_start = x_start_;
	x_end = x_end_;
	alphabet = alphabet_;
}
AHorizontalLine::~AHorizontalLine() {//소멸자

}
void AHorizontalLine::draw(WhiteBoard* board) const {//AHorizontalLine 그리기, x를 바꿔가며 반복문으로 fillboard
	for (int a = x_start; a <= x_end; a++) {
			board->fillPoint(a, y, alphabet);
	}
}
void AHorizontalLine::print() const { //멤버 변수 출력
	cout << ") AHorizontalLine with[alphabet:"<<alphabet
	<<"] and [y:"<<y<<"][x_start:"<<x_start<<"][x_end:"<<x_end<<"][size:"<<size() << "]" << endl;
}
int AHorizontalLine::size() const { //사이즈 출력
	return (x_end - x_start + 1);
}
ARectangle::ARectangle() { //생성자
	x_start = 0;
	x_end = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';
}
ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_) { //생성자(오버로딩)
	x_start = x_start_;
	x_end = x_end_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}
ARectangle::~ARectangle() { //소멸자
	
}
void ARectangle::draw(WhiteBoard* board) const { //그리기, x, y, 이중 반복문으로 fillboard 수행
	for (int a = x_start; a <= x_end; a++) {
		for (int b = y_start; b <= y_end; b++) {
			board->fillPoint(a, b, alphabet);
		}
	}
}
void ARectangle::print() const {//멤버 변수 출력
	cout << ") ARectangle with[alphabet:"
	<< alphabet << "] and [x_start:" << x_start << "][x_end:" << x_end
		<< "][y_start:" << y_start << "][y_end:" << y_end << "][size:" << size() << "]" << endl;
}
int ARectangle::size() const {//사이즈 출력
	return (y_end - y_start + 1) * (x_end - x_start + 1);
}