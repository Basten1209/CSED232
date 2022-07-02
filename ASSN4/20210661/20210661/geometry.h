#pragma once

class geometry
{
private:

public:
	virtual void draw2canvas(float** canvas, int w, int h) { //하위 클래스의 draw2canvas로 이동시키기
		this->draw2canvas(canvas, w, h);
	}
};

template <typename T>
class rectangle : public geometry //rectangle은 geometry에 상속받는 class
{
private:
	T l_x; //왼쪽 아래 꼭짓점 x 좌표
	T l_y; //왼쪽 아래 꼭짓점 y 좌표
	T r_x; //오른쪽 위 꼭짓점 x 좌표
	T r_y; //오른쪽 위 꼭짓점 y 좌표
public:
	rectangle(T x_1, T y_1, T x_2, T y_2) {//입력받는 좌표값을 왼쪽 아래, 오른쪽 위 좌표가 되도록 위치 수정
		if (x_1 < x_2) {
			l_x = x_1;
			r_x = x_2;
		}
		else {
			l_x = x_2;
			r_x = x_1;
		}

		if (y_1 < y_2) {
			l_y = y_1;
			r_y = y_2;
		}
		else {
			l_y = y_2;
			r_y = y_1;
		}

		if ((r_x - l_x) * (r_y - l_y) == 0) throw; //크기가 0이라면 throw
	}
	
	~rectangle() {//소멸자
	}

	bool is_equal(const rectangle<T>& other) { //네 좌표가 모두 동일하면 true
		if ((l_x == other.l_x) && (r_x == other.r_x) && (l_y == other.l_y) && (r_y == other.r_y))
			return true;
		else
			return false;

	}
	bool is_intersect(const rectangle<T>& other) {//두 사각형의 교차점을 파악하여, 교차점 공간을 네 점으로 표기. 
		//이의 x좌표와 y좌표를 비교하여, is_equal이 false일 때,  tl_x < tr_x && tl_y < tr_y이면 true.아니면 false

		T tl_x, tl_y, tr_x, tr_y;
		if (l_x < other.l_x) {
			tl_x = other.l_x;
		}
		else
			tl_x = l_x;
		if (l_y < other.l_y) {
			tl_y = other.l_y;
		}
		else
			tl_y = l_y;
		if (r_x < other.r_x) {
			tr_x = r_x;
		}
		else
			tr_x = other.r_x;
		if (r_y < other.r_y) {
			tr_y = r_y;
		}
		else
			tr_y = other.r_y;


		if (is_equal(other) == false) {
			if (tl_x < tr_x && tl_y < tr_y)
				return true;
			else
				return false;
		}
		else
			return false;

	}
	bool is_line_overlap(const rectangle<T>& other) {//두 사각형의 교차점을 파악하여, 교차점 공간을 네 점으로 표기. 
		//이의 x좌표와 y좌표를 비교하여, (tl_x == tr_x),(tl_y == tr_y)둘 중 하나만 true라면 true.아니면 false
		T tl_x, tl_y, tr_x, tr_y;
		if (l_x < other.l_x) {
			tl_x = other.l_x;
		}
		else
			tl_x = l_x;
		if (l_y < other.l_y) {
			tl_y = other.l_y;
		}
		else
			tl_y = l_y;
		if (r_x < other.r_x) {
			tr_x = r_x;
		}
		else
			tr_x = other.r_x;
		if (r_y < other.r_y) {
			tr_y = r_y;
		}
		else
			tr_y = other.r_y;

		if ((tl_x == tr_x) != (tl_y == tr_y))
			return true;
		else
			return false;
	}
	bool is_point_match(const rectangle<T>& other) {//두 사각형의 교차점을 파악하여, 교차점 공간을 네 점으로 표기. 
		//이의 x좌표와 y좌표를 비교하여, tl_x == tr_x && tl_y == tr_y이라면 true.아니면 false
		
		T tl_x, tl_y, tr_x, tr_y;
		if (l_x < other.l_x) {
			tl_x = other.l_x;
		}
		else
			tl_x = l_x;
		if (l_y < other.l_y) {
			tl_y = other.l_y;
		}
		else
			tl_y = l_y;
		if (r_x < other.r_x) {
			tr_x = r_x;
		}
		else
			tr_x = other.r_x;
		if (r_y < other.r_y) {
			tr_y = r_y;
		}
		else
			tr_y = other.r_y;
		if (tl_x == tr_x && tl_y == tr_y)
			return true;
		else
			return false;
	}
	bool is_disjoint(const rectangle<T>& other) {//두 사각형의 교차점을 파악하여, 교차점 공간을 네 점으로 표기. 
		//이의 x좌표와 y좌표를 비교하여, tl_x > tr_x || tl_y > tr_y이라면 true.아니면 false
		T tl_x, tl_y, tr_x, tr_y;
		if (l_x < other.l_x) {
			tl_x = other.l_x;
		}
		else
			tl_x = l_x;
		if (l_y < other.l_y) {
			tl_y = other.l_y;
		}
		else
			tl_y = l_y;
		if (r_x < other.r_x) {
			tr_x = r_x;
		}
		else
			tr_x = other.r_x;
		if (r_y < other.r_y) {
			tr_y = r_y;
		}
		else
			tr_y = other.r_y;

		if (tl_x > tr_x || tl_y > tr_y)
			return true;
		else
			return false;
	}
	void draw2canvas(float** canvas, int w, int h) {
		int finalw, finalh;//r_x, r_y와 w, h를 비교하여, 더 작은 값을 최종적으로 그려야 하는 공간으로 선택.(r_x, r_y가 canvas를 넘어가는 것을 방지)
		if (r_x >= w)
			finalw = w;
		else
			finalw = r_x;
		if (r_y >= h)
			finalh = h;
		else
			finalh = r_y;

			for (int i = l_y; i < finalh; i++) {//해당하는 범위에 이중 for문으로 1씩 추가
				for (int j = l_x; j < finalw; j++) {
					canvas[i][j] += 1;
				}
			}
	}

};

template <typename T, int N>
class point : public geometry //point는 geometry에 상속받는 class
{
private: //int, float 형의 배열을 private로 가짐
	T arr[N];
public:
	point(const T* coords) {

		for (int i = 0; i < N; i++) { //생성자, N size의 배열에 값 추가
			arr[i] = coords[i];
		}

	}
	~point() {}//소멸자,
	void draw2canvas(float** canvas, int w, int h) {//index가 2 이상인 자리에 대하여 합쳐서 차원 합 구하고 더하기, 합이 0이라면 1로 치환하여 더하기.
		float coo = 0;
		for (int i = 2; i < N; i++) {
			coo += arr[i];
		}
		if (coo == 0)
			coo = 1;


		canvas[(int)arr[1]][(int)arr[0]] += coo;
	}
};