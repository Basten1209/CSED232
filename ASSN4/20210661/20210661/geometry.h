#pragma once

class geometry
{
private:

public:
	virtual void draw2canvas(float** canvas, int w, int h) { //���� Ŭ������ draw2canvas�� �̵���Ű��
		this->draw2canvas(canvas, w, h);
	}
};

template <typename T>
class rectangle : public geometry //rectangle�� geometry�� ��ӹ޴� class
{
private:
	T l_x; //���� �Ʒ� ������ x ��ǥ
	T l_y; //���� �Ʒ� ������ y ��ǥ
	T r_x; //������ �� ������ x ��ǥ
	T r_y; //������ �� ������ y ��ǥ
public:
	rectangle(T x_1, T y_1, T x_2, T y_2) {//�Է¹޴� ��ǥ���� ���� �Ʒ�, ������ �� ��ǥ�� �ǵ��� ��ġ ����
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

		if ((r_x - l_x) * (r_y - l_y) == 0) throw; //ũ�Ⱑ 0�̶�� throw
	}
	
	~rectangle() {//�Ҹ���
	}

	bool is_equal(const rectangle<T>& other) { //�� ��ǥ�� ��� �����ϸ� true
		if ((l_x == other.l_x) && (r_x == other.r_x) && (l_y == other.l_y) && (r_y == other.r_y))
			return true;
		else
			return false;

	}
	bool is_intersect(const rectangle<T>& other) {//�� �簢���� �������� �ľ��Ͽ�, ������ ������ �� ������ ǥ��. 
		//���� x��ǥ�� y��ǥ�� ���Ͽ�, is_equal�� false�� ��,  tl_x < tr_x && tl_y < tr_y�̸� true.�ƴϸ� false

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
	bool is_line_overlap(const rectangle<T>& other) {//�� �簢���� �������� �ľ��Ͽ�, ������ ������ �� ������ ǥ��. 
		//���� x��ǥ�� y��ǥ�� ���Ͽ�, (tl_x == tr_x),(tl_y == tr_y)�� �� �ϳ��� true��� true.�ƴϸ� false
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
	bool is_point_match(const rectangle<T>& other) {//�� �簢���� �������� �ľ��Ͽ�, ������ ������ �� ������ ǥ��. 
		//���� x��ǥ�� y��ǥ�� ���Ͽ�, tl_x == tr_x && tl_y == tr_y�̶�� true.�ƴϸ� false
		
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
	bool is_disjoint(const rectangle<T>& other) {//�� �簢���� �������� �ľ��Ͽ�, ������ ������ �� ������ ǥ��. 
		//���� x��ǥ�� y��ǥ�� ���Ͽ�, tl_x > tr_x || tl_y > tr_y�̶�� true.�ƴϸ� false
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
		int finalw, finalh;//r_x, r_y�� w, h�� ���Ͽ�, �� ���� ���� ���������� �׷��� �ϴ� �������� ����.(r_x, r_y�� canvas�� �Ѿ�� ���� ����)
		if (r_x >= w)
			finalw = w;
		else
			finalw = r_x;
		if (r_y >= h)
			finalh = h;
		else
			finalh = r_y;

			for (int i = l_y; i < finalh; i++) {//�ش��ϴ� ������ ���� for������ 1�� �߰�
				for (int j = l_x; j < finalw; j++) {
					canvas[i][j] += 1;
				}
			}
	}

};

template <typename T, int N>
class point : public geometry //point�� geometry�� ��ӹ޴� class
{
private: //int, float ���� �迭�� private�� ����
	T arr[N];
public:
	point(const T* coords) {

		for (int i = 0; i < N; i++) { //������, N size�� �迭�� �� �߰�
			arr[i] = coords[i];
		}

	}
	~point() {}//�Ҹ���,
	void draw2canvas(float** canvas, int w, int h) {//index�� 2 �̻��� �ڸ��� ���Ͽ� ���ļ� ���� �� ���ϰ� ���ϱ�, ���� 0�̶�� 1�� ġȯ�Ͽ� ���ϱ�.
		float coo = 0;
		for (int i = 2; i < N; i++) {
			coo += arr[i];
		}
		if (coo == 0)
			coo = 1;


		canvas[(int)arr[1]][(int)arr[0]] += coo;
	}
};